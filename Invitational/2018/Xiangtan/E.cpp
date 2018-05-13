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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e3+10;
const int maxd = 20;
int anc[maxn][maxd], dep[maxn];
int par[maxn];
int z[maxn];
vector<int> G[maxn];
int n, ans;

void init()
{
    memset(anc, 0, sizeof(anc));
    memset(dep, 0, sizeof(dep));
    for(int i = 0; i <= n; i++)par[i] = i, G[i].clear();
    ans = 0;
}

void dfs(int u, int f)
{
    dep[u] = dep[f]+1;
    anc[u][0] = f;
    for(auto v : G[u]){
        if(v == f)continue;
        else dfs(v, u);
    }
}

void init_lca()
{
    for(int i = 1; i < maxd; i++){
        for(int j = 0; j < n; j++){
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
}

int lca(int u, int v)
{
    if(dep[u] < dep[v])swap(u, v);
    for(int i = maxd-1; i >= 0; i--){
        if(dep[anc[u][i]] >= dep[v])u = anc[u][i];
    }
    if(u == v)return u;
    for(int i = maxd-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}

int find(int x)
{
    return x==par[x]?x:par[x]=find(par[x]);
}

void Link(int x, int f)
{
    //printf("Link(%d,%d)\n", x, f);
    x = find(x); f = find(f);
    while(x != f){
        int v = anc[x][0];
        if(find(v) != f){
            assert(z[v] >= 1);
            ans = ans^z[v]^(z[v]-1);
            z[v]--;
            par[x] = f;
        }
        x = find(v);
    }
}

int main()
{
    int m, a, b, x, y;
    while(scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &x, &y) != EOF){
        init();
        for(int i = 0; i < n-1; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v); G[v].pb(u);
        }
        dfs(0, 0);
        init_lca();
        for(int i = 0; i < n; i++){
            z[i] = G[i].size();
            ans ^= z[i];
        }
        for(int i = 0; i < m; i++){
            int pre = ans;
            int f = lca(x, y);
            Link(x, f);
            int nx = (a*x+b*y+pre)%n, ny = (b*x+a*y+pre)%n;
            x = nx, y = ny;
            //printf("x=%d, y=%d\n", x, y);
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}

