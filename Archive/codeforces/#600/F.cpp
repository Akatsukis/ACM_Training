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
constexpr int maxn = 1e5+10;
constexpr int maxd = 20;
vector<pair<int, long long>> G[maxn], G2[maxn];
long long dist[maxn];
int from[maxn];
bool vis[maxn];
int anc[maxn][maxd], dep[maxn], par[maxn];
long long fx[maxn][maxd];
int n, m, k, q;
struct edge {
    int u, v;
    long long w;
    bool operator < (const edge &rhs) const {
        return w < rhs.w;
    }
};
vector<edge> es;

void dijkstra() {
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    for(int s = 1; s <= k; s++) {
        pq.push(make_pair(0, s));
        from[s] = s;
        dist[s] = 0;
    }
    while(!pq.empty()) {
        long long dis = pq.top().first;
        int u = pq.top().second;
        vis[u] = 1;
        pq.pop();
        if(dis != dist[u])continue;
        for(auto p: G[u]) {
            int v = p.first, w = p.second;
            if(vis[v] && from[v] != from[u]) {
                es.push_back({from[u], from[v], dist[u]+dist[v]+w});
            }
            if(dist[v] > dist[u]+w) {
                dist[v] = dist[u]+w;
                from[v] = from[u];
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void dfs(int u, int f) {
    dep[u] = dep[f]+1;
    anc[u][0] = f;
    for(auto p: G2[u]) {
        if(p.first == f)continue;
        fx[p.first][0] = p.second;
        dfs(p.first, u);
    }
}

void init_lca() {
    for(int j = 1; j < maxd; j++) {
        for(int i = 1; i <= k; i++) {
            anc[i][j] = anc[anc[i][j-1]][j-1];
            fx[i][j] = max(fx[i][j-1], fx[anc[i][j-1]][j-1]);
        }
    }
}

long long query(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    long long ans = 0;
    for(int i = maxd-1; i >= 0; i--) {
        if(dep[anc[u][i]] >= dep[v]) {
            ans = max(ans, fx[u][i]);
            u = anc[u][i];
        }
    }
    if(u == v) return ans;
    for(int i = maxd-1; i >= 0; i--) {
        if(anc[u][i] != anc[v][i]) {
            ans = max(ans, max(fx[u][i], fx[v][i]));
            u = anc[u][i], v = anc[v][i];
        }
    }
    ans = max(ans, max(fx[u][0], fx[v][0]));
    return ans;
}

int find(int x) {
    return par[x] == x ? par[x] : par[x] = find(par[x]);   
}

bool unite(int u, int v) {
    u = find(u), v = find(v);
    if(u != v) {
        par[u] = v;
        return 1;
    }
    else return 0;
}


int main()
{
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    dijkstra();
    sort(es.begin(), es.end());
    for(int i = 1; i <= k; i++) {
        par[i] = i;
    }
    for(auto e: es) {
        if(unite(e.u, e.v)) {
            G2[e.u].push_back(make_pair(e.v, e.w));
            G2[e.v].push_back(make_pair(e.u, e.w));
        }
    }
    dfs(1, 0);
    init_lca();
    for(int i = 0; i < q; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        long long ans = query(u, v);
        printf("%lld\n", ans);
    }
    return 0;
}

