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
const int maxn = 1e3+10;
struct edge
{
    int to, cap, cost, rev;
    edge(){}
    edge(int to, int cap, int cost, int rev):to(to), cap(cap), cost(cost), rev(rev){}
};
vector<edge> G[maxn];
bool vis[maxn];
ll dist[maxn];
int n, m;
ll F;

void add_edge(int u, int v, int cap, int cost)
{
    G[u].pb(edge(v, cap, cost, SZ(G[v])));
    G[v].pb(edge(u, cap, -cost, SZ(G[v])-1));
}

bool spfa(int s, int t)
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s); vis[s] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = 0;
        for(auto e : G[u]){
            if(e.cap > 0 && dist[e.to] > dist[u]+e.cost){
                dist[e.to] = dist[u]+e.cost;
                q.push(e.to); vis[e.to] = 1;
            }
        }
    }
    //printf("dist[%d]=%lld\n", n, dist[n]);
    return dist[n] <= F;
}

int dfs(int v, int t, int f)
{
    vis[v] = 1;
    if(v == t)return f;
    int ret = 0;
    for(auto &e : G[v]){
        if(!vis[e.to] && e.cap > 0 && dist[e.to] == dist[v]+e.cost){
            //printf("dist[%d]=dist[%d]+%d cap=%d\n", e.to, v, e.cost, e.cap);
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d){
                //printf("v=%d, d=%d\n", v, d);
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                ret += d;
                F -= 1LL*d*e.cost;
                if(ret == f)break;
            }
        }
    }
    return ret;
}

int costFlow(int s, int t)
{
    int ret = 0;
    while(spfa(s, t)){
        vis[t] = 1;
        while(vis[t] && F/dist[n]){
            memset(vis, 0, sizeof(vis));
            ret += dfs(s, t, F/dist[n]);
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d%lld", &n, &m, &F);
    for(int i = 0; i < m; i++){
        int u, v, c, w;
        scanf("%d%d%d%d", &u, &v, &c, &w);
        add_edge(u, v, c, w);
    }
    int ans = costFlow(1, n);
    printf("%d\n", ans);
    return 0;
}

