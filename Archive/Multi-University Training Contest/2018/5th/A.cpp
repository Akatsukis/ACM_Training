#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 1e5+10;
const int maxm = 3e5+10;
struct edge
{
    int u, v, w;
    bool used;
    edge(){}
    edge(int u, int v, int w, bool used):u(u), v(v), w(w), used(used){}
    bool operator < (const edge &rhs){return w > rhs.w;}
}es[maxm];
int par[maxn];
int dep[maxn];
int fa[maxn], idf[maxn];
int sz[maxn][32][2];
vector<pii> G[maxn];

void init(int n)
{
    for(int i = 1; i <= n; i++){
        par[i] = i;
        for(int j = 0; j < 31; j++){
            sz[i][j][0] = ((i>>j)&1)^1;
            sz[i][j][1] = (i>>j)&1;
        }
        G[i].clear();
    }
}

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool unite(int x, int y)
{
    x = find(x); y = find(y);
    if(x != y){
        par[x] = y;
        return 1;
    }
    else return 0;
}

void dfs(int u, int f, int id)
{
    fa[u] = f, dep[u] = dep[f]+1, idf[u] = id;
    for(auto v : G[u]){
        if(v.fi == f)continue;
        else dfs(v.fi, u, v.se);
    }
}

int main()
{
    int T; sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        init(n);
        for(int i = 1; i <= m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v ,&w);
            es[i] = edge(u, v, w, 0);
        }
        sort(es+1, es+1+m);
        for(int i = 1; i <= m; i++){
            int u = es[i].u, v = es[i].v;
            if(unite(u, v)){
                es[i].used = 1;
                G[u].pb(mk(v, i)); G[v].pb(mk(u, i));
            }
        }
        dfs(1, 0, 0);
        for(int i = 1; i <= m; i++){
            if(!es[i].used){
                int u = es[i].u, v = es[i].v, w = es[i].w;
                if(dep[u] > dep[v])swap(u, v);
                while(dep[v] > dep[u]){
                    es[idf[v]].w += w;
                    v = fa[v];
                }
                while(u != v){
                    es[idf[u]].w += w, es[idf[v]].w += w;
                    u = fa[u], v = fa[v];
                }
            }
        }
        for(int i = 1; i <= n; i++)par[i] = i;
        sort(es+1, es+1+m);
        ull ans = 0;
        for(int i = 1; i <= m; i++){
            if(es[i].used){
                int u = es[i].u, v = es[i].v, w = es[i].w;
                u = find(u), v = find(v);
                for(int j = 0; j < 31; j++) {
                    if((w>>j)&1)ans += (1ull*sz[u][j][0]*sz[v][j][0]+1ull*sz[u][j][1]*sz[v][j][1])*(1<<j);
                    else ans += (1ull*sz[u][j][0]*sz[v][j][1]+1ull*sz[u][j][1]*sz[v][j][0])*(1<<j);
                    sz[u][j][0] += sz[v][j][0];
                    sz[u][j][1] += sz[v][j][1];
                }
                par[v] = u;
            }
        }
        printf("%llu\n", ans);
    }
    return 0;
}


