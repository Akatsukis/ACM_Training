#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define sc(x) scanf("%d", &x)
#define pb emplace_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e5+10;
const int maxm = 50;
const int maxd = 20;
struct edge
{
    int u, v, w, nxt;
    edge(){}
    edge(int u, int v, int w, int nxt):u(u), v(v), w(w), nxt(nxt){}
}es[maxn*2];
int head[maxn];
int anc[maxn][maxd], dep[maxn];
ll dist[maxn], dist2[maxm][maxm], dist3[maxm][maxn];
bool vis[maxn], used[maxn];
vector<pll> G[maxn];
vector<edge> vec;
map<int, int> mp, rev;
int n, m, cnt, idx;

void add_edge(int u, int v, int w)
{
    es[cnt] = edge(u, v, w, head[u]);
    head[u] = cnt++;
    es[cnt] = edge(v, u, w, head[v]);
    head[v] = cnt++;
}

void dfs(int u, int f)
{
    vis[u] = 1;
    dep[u] = dep[f]+1;
    anc[u][0] = f;
    for(int i = head[u]; ~i; i = es[i].nxt){
        if(!vis[es[i].v]){
            used[i>>1] = 1;
            dist[es[i].v] = dist[u]+es[i].w;
            dfs(es[i].v, u);
        }
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

ll get_dis(int u, int v)
{
    int f = lca(u, v);
    return dist[u]+dist[v]-2*dist[f];
}

int main()
{
    memset(head, -1, sizeof(head));
    sc(n); sc(m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        sc(u); sc(v); sc(w);
        add_edge(u, v, w);
    }
    dfs(1, 0);
    init_lca();
    memset(dist2, 0x3f, sizeof(dist2));
    for(int i = 0; i < cnt; i++){
        if(!used[i>>1]){
            int u = es[i].u, v = es[i].v;
            if(!mp.count(u))mp[u] = ++idx, rev[idx] = u;
            if(!mp.count(v))mp[v] = ++idx, rev[idx] = v;
            dist2[mp[u]][mp[v]] = min(dist2[mp[u]][mp[v]], (ll)es[i].w);
        }
    }
    for(int i = 1; i <= idx; i++){
        for(int j = 1; j <= idx; j++)dist2[i][j] = min(dist2[i][j], get_dis(rev[i], rev[j]));
    }
    for(int k = 1; k <= idx; k++){
        for(int i = 1; i <= idx; i++){
            for(int j = 1; j <= idx; j++){
                if(dist2[i][j] > dist2[i][k]+dist2[k][j]){
                    dist2[i][j] = dist2[i][k]+dist2[k][j];
                }
            }
        }
    }
    for(int i = 1; i <= idx; i++){
        for(int j = 1; j <= n; j++){
            dist3[i][j] = get_dis(rev[i], j);
        }
    }
    int q; sc(q);
    for(int i = 0; i < q; i++){
        int u, v;
        sc(u); sc(v);
        ll ans = get_dis(u, v);
        for(int i = 1; i <= idx; i++){
            for(int j = 1; j <= idx; j++){
                ans = min(ans, dist3[i][u]+dist2[i][j]+dist3[j][v]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
