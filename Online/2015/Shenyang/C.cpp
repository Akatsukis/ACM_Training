#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e4+10;
const int maxh = 19;
vector<int> G[maxn];
int anc[maxn][maxh];
int dep[maxn];
int tag[maxn];
int n, m, ans;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(tag, 0, sizeof(tag));
}

void dfs(int u, int f)
{
    dep[u] = dep[f]+1;
    anc[u][0] = f;
    for(auto v : G[u]){
        if(v != f)dfs(v, u);
    }
}

void init_lca()
{
    dfs(1, 0);
    for(int i = 1; i < maxh; i++){
        for(int j = 1; j <= n; j++){
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
}

int lca(int u, int v)
{
    if(dep[u] > dep[v])swap(u, v);
    for(int i = maxh-1; i >= 0; i--){
        if(dep[anc[v][i]] >= dep[u])v = anc[v][i];
    }
    if(u == v)return u;
    for(int i = maxh-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}

void dfs_ans(int u, int f)
{
    for(auto v : G[u]){
        if(v == f)continue;
        dfs_ans(v, u);
        tag[u] += tag[v];
    } 
    if(u != 1)ans = min(ans, tag[u]+1);
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(m);
        init();
        for(int i = 1; i <= n-1; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        init_lca();
        for(int i = n; i <= m; i++){
            int u, v;
            sc(u); sc(v);
            tag[u]++, tag[v]++, tag[lca(u, v)] -= 2;
        }
        ans = INF;
        dfs_ans(1, 0);
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}
