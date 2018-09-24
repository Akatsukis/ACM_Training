#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define SZ(x) ((int)x.size())
#define pb push_back
#define mk make_pair
#define fi first 
#define se second
struct data
{
    int v, rev, f, id;
    data(){}
    data(int v, int rev, int id):v(v), rev(rev), id(id){}
};
vector<data> q[maxn];
vector<pii> G[maxn];
int par[maxn], dist[maxn];
int ans[maxn];
bool vis[maxn];
int n, m;

void init()
{
    for(int i = 1; i <= n; i++)q[i].clear(), G[i].clear(), vis[i] = 0, par[i] = i;
}

void add_query(int u, int v, int id)
{
    q[u].pb(data(v, SZ(q[v]), id));
    q[v].pb(data(u, SZ(q[u])-1, id));
}

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int u, int v)
{
    u = find(u); v = find(v);
    if(u != v)par[u] = v;
}

void dfs(int u, int f)
{
    vis[u] = 1;
    for(auto v : G[u]){ 
        if(!vis[v.fi]){    
            dist[v.fi] = dist[u]+v.se;
            dfs(v.fi, u);
            unite(v.fi, u);
        }
    }
    for(auto &d : q[u]){
        if(vis[d.v])d.f = q[d.v][d.rev].f = find(d.v);
    }
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n); sc(m);
        init();
        for(int i = 1; i < n; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            G[u].pb(mk(v, w));
            G[v].pb(mk(u, w));
        }
        for(int i = 1; i <= m; i++){
            int u, v;
            sc(u); sc(v);
            add_query(u, v, i);
        }
        dfs(1, 0);
        for(int i = 1; i <= n; i++){
            for(auto d : q[i]){
                ans[d.id] = dist[i]+dist[d.v]-2*dist[d.f];
            }
        }
        for(int i = 1; i <= m; i++){
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
