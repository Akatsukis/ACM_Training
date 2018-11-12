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
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+10;
struct Edge
{
    int to, dis, nxt;
    bool del;
    Edge(){}
    Edge(int to, int dis, int nxt, bool del):to(to), dis(dis), nxt(nxt), del(del){}
}es[maxn];
int head[maxn], dist[maxn];
ll res[maxn];
vector<int> used;
int n, m, L;

void init()
{
    for(int i = 1; i <= n; i++)head[i] = -1;
    for(int i = 0; i < m; i++)res[i] = 0;
}

void add_edge(int u, int v, int w, int id)
{
    es[id<<1] = Edge(v, w, head[u], 0);
    head[u] = id<<1;
    es[id<<1|1] = Edge(u, w, head[v], 0);
    head[v] = id<<1|1;
}

ll dijkstra(int s)
{
    used.clear();
    for(int i = 1; i <= n; i++)dist[i] = INF;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mk(0, s));
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        if(p.fi != dist[p.se])continue;
        for(int i = head[p.se]; ~i; i = es[i].nxt){
            Edge e = es[i];
            if(!e.del && dist[e.to] > dist[p.se]+e.dis){
                used.pb(i>>1);
                dist[e.to] = dist[p.se]+e.dis;
                pq.push(mk(dist[e.to], e.to));
            }
        }
    }
    ll ret = 0;
    for(int i = 1; i <= n; i++)ret += dist[i]==INF?L:dist[i];
    return ret;
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &L) != EOF){
        init();
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w, i);
        }
        ll ans1 = 0, ans2 = 0;
        for(int i = 1; i <= n; i++){
            ll d = dijkstra(i);
            ans1 += d;
            for(int j = 0; j < m; j++)res[j] += d;
            vector<int> vec = used;
            for(auto id : vec){
                es[id<<1].del = es[id<<1|1].del = 1;
                res[id] = res[id]-d+dijkstra(i);
                es[id<<1].del = es[id<<1|1].del = 0;
            }
        }
        for(int i = 0; i < m; i++)ans2 = max(ans2, res[i]);
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}

