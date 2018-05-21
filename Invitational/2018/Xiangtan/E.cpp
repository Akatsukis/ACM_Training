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
const int maxn = 1e5+10;
const int maxd = 20;
int anc[maxn][maxd], dep[maxn];
int par[maxn];
int z[maxn];
vector<int> G[maxn];
int n, ans;

void init()
{
    for(int i = 0; i <= n; i++){
        par[i] = i;
        G[i].clear();
    }
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
        for(int j = 1; j <= n; j++){
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
    x = find(x);
    while(anc[x][0] > 0 && dep[anc[x][0]] > dep[f]){
        ans = ans^z[anc[x][0]]^(z[anc[x][0]]-1);
        z[anc[x][0]]--;
        par[x] = anc[x][0];
        x = find(x);
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
            u++; v++;
            G[u].pb(v); G[v].pb(u);
        }
        dfs(1, 0);
        init_lca();
        for(int i = 1; i <= n; i++){
            z[i] = G[i].size();
            ans ^= z[i];
        }
        for(int i = 0; i < m; i++){
            int nx = (a*x+b*y+ans)%n, ny = (b*x+a*y+ans)%n;
            x = nx, y = ny;
            int f = lca(x+1, y+1);
            Link(x+1, f);
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}

