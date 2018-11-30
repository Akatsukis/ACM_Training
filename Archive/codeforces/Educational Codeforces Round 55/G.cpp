#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define SZ(x) ((int)x.size())
typedef long long ll;
const int maxn = 3e3+10;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
struct edge
{
    ll to, cap, rev;
    edge(){}
    edge(ll to, ll cap, ll rev):to(to), cap(cap), rev(rev){}
};
vector<edge> G[maxn];
int lev[maxn];
int cnt;

void add_edge(int u, int v, ll cap)
{
    G[u].pb(edge(v, cap, SZ(G[v])));
    G[v].pb(edge(u, 0, SZ(G[u])-1));
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &e : G[u]){
            if(e.cap > 0 && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
                if(e.to == t){
                    return 1;
                }
                q.push(e.to);
            }
        }
    }
    return 0;
}

ll dfs(int v, int t, ll f)
{
    if(v == t)return f;
    ll ret = 0;
    for(auto &e : G[v]){
        if(e.cap > 0 && lev[e.to] == lev[v]+1){
            ll d = dfs(e.to, t, min(e.cap, f-ret));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                ret += d;
                if(ret == f)break;
            }
            
        }
    }
    if(!ret)lev[v] = 0;
    return ret;
}
ll max_flow(int s, int t)
{
    ll flow = 0;
    while(bfs(s, t))flow += dfs(s, t, INF64);
    return flow;
}

int main()
{
    int n, m;
    sc(n); sc(m);
    int src = n+m+1, dst = src+1;
    ll ans = 0, sum = 0;
    for(int i = 1; i <= n; i++){
        ll w;
        scanf("%lld", &w);
        add_edge(i, dst, w);
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        add_edge(src, i+n, w);
        sum += w;
        add_edge(i+n, u, INF64); add_edge(i+n, v, INF64);
    }
    ans = max(ans, sum-max_flow(src, dst));
    printf("%lld\n", ans);
}
