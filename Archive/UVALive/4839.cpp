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
const int maxn = 2e4+10;
const int maxm = 2e5+10;
const int maxd = 20;
struct edge
{
    int u, v, nxt; 
    edge(){}
    edge(int u, int v, int nxt):u(u), v(v), nxt(nxt){}
}es[maxm];
int dfn[maxn], low[maxn], bcc[maxn], head[maxn];
int dep[maxn], anc[maxn][maxd];
int blg[maxm];
bool vis[maxn];
vector<int> G[maxn];
stack<int> sk;
int n, m, idx;

void init()
{
    for(int i = 1; i <= 2*n; i++){
        dfn[i] = low[i] = bcc[i] = vis[i] = 0;
        head[i] = -1;
        G[i].clear();
    }
    idx = 0;
}

void add_edge(int u, int v, int id)
{
    es[id*2] = edge(u, v, head[u]); es[id*2+1] = edge(v, u, head[v]);
    head[u] = id*2, head[v] = id*2+1;
}

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    bool fst = 1;
    for(int i = head[u]; ~i; i = es[i].nxt){
        int v = es[i].v;
        if(v == f){
            if(fst){
                fst = 0;
                continue;
            }
        }
        if(!dfn[v]){
            sk.push(i);
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){
                n++;
                while(1){
                    int id = sk.top(); sk.pop();
                    if(bcc[es[id].u] != n){
                        bcc[es[id].u] = n;
                        G[n].pb(es[id].u); G[es[id].u].pb(n);
                    }
                    if(bcc[es[id].v] != n){
                        bcc[es[id].v] = n;
                        G[n].pb(es[id].v); G[es[id].v].pb(n);
                    }
                    blg[id>>1] = n;
                    if(id == i)break;
                }
            }
        }
        else if(dfn[v] < dfn[u]){
            sk.push(i);
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void tarjan()
{
    int pnt = n;
    for(int i = 1; i <= pnt; i++){
        if(!dfn[i])dfs(i, 0);
    }
}

void get_dep(int u, int f)
{
    vis[u] = 1;
    dep[u] = dep[f]+1; anc[u][0] = f;
    for(auto v : G[u]){
        if(v == f)continue;
        get_dep(v, u);
    }
}

void init_lca()
{
    for(int j = 1; j < maxd; j++){
        for(int i = 1; i <= n; i++){
            anc[i][j] = anc[anc[i][j-1]][j-1];
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

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && n){
        init();
        for(int i = 1; i <= m; i++){
            int u, v;
            sc(u); sc(v);
            add_edge(u, v, i);
        }
        tarjan();
        for(int i = 1; i <= n; i++){
            if(!vis[i])get_dep(i, 0);
        }
        init_lca();
        int q; sc(q);
        for(int i = 0; i < q; i++){
            int u, v;
            sc(u); sc(v);
            u = blg[u], v = blg[v];
            int f = lca(u, v);
            printf("%d\n", (dep[u]+dep[v]-2*dep[f])/2);
        }
    }
    return 0;
}

