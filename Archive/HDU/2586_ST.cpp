#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
const int maxn = 1e5+10;
const int maxd = 20;
vector<pii> G[maxn];
int beg[maxn], id[maxn], dep[maxn];
int st[maxn][maxd];
int dist[maxn];
int n, m, tot;

void init()
{
    for(int i = 1; i <= n; i++)G[i].clear();
    tot = 0;
}

void init_rmq(int sz)
{
    for(int i = 0; i < sz; i++)st[i][0] = i;
    for(int j = 1; (1<<j) <= sz; j++){
        for(int i = 0; i+(1<<j)-1 < sz; i++){
            int u = st[i][j-1], v = st[i+(1<<(j-1))][j-1];
            st[i][j] = dep[u]<dep[v]?u:v;
        }
    }
}

int query(int l, int r)
{
    int k = log2(r-l+1);
    return min(st[l][k], st[r-(1<<k)+1][k]);
}

int lca(int x, int y)
{
    int l = beg[x], r = beg[y];
    if(l > r)swap(l, r);
    return id[query(l, r)];
}

void dfs(int u, int f, int d)
{
    beg[u] = tot; id[tot] = u; dep[tot] = d; tot++;
    for(auto v : G[u]){
        if(v.fi == f)continue;
        dist[v.fi] = dist[u]+v.se;
        dfs(v.fi, u, d+1);
        id[tot] = u; dep[tot] = d; tot++;
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
            G[u].pb(mk(v, w)); G[v].pb(mk(u, w));
        }
        dfs(1, 0, 0);
        init_rmq(tot);
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            int f = lca(u, v);
            int ans = dist[u]+dist[v]-2*dist[f];
            printf("%d\n", ans);
        }
    }
    return 0;
}
