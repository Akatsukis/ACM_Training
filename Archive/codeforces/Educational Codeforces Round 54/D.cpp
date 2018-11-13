#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e5+10;
const int maxm = 6e5+10;
struct Edge
{
    int v, w, nxt;
    Edge(){}
    Edge(int v, int w, int nxt):v(v), w(w), nxt(nxt){}
}es[maxm];
int head[maxn];
ll dist[maxn];
bool vis[maxn];
vector<int> ans;
int n, m, k;

void init()
{
    for(int i = 1; i <= n; i++)head[i] = -1;
}

void add_edge(int u, int v, int w, int id)
{
    es[id<<1] = Edge(v, w, head[u]);
    head[u] = id<<1;
    es[id<<1|1] = Edge(u, w, head[v]);
    head[v] = id<<1|1;
}

void dijkstra(int s)
{
    for(int i = 1; i <= n; i++)dist[i] = INF64;
    dist[s] = 0;
    priority_queue<pli, vector<pli>, greater<pli> > pq;
    pq.push(mk(dist[s], s));
    while(!pq.empty()){
        pli p = pq.top(); pq.pop();
        if(p.fi != dist[p.se])continue;
        for(int i = head[p.se]; ~i; i = es[i].nxt){
            Edge e = es[i];
            if(dist[e.v] > dist[p.se]+e.w){
                dist[e.v] = dist[p.se]+e.w;
                pq.push(mk(dist[e.v], e.v));
            }
        }
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for(int i = head[u]; ~i; i = es[i].nxt){
        Edge e = es[i];
        if(k && !vis[e.v] && dist[e.v] == dist[u]+e.w){
            k--;
            ans.pb(i>>1);
            dfs(e.v);
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    init();
    for(int i = 1; i <= m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add_edge(u, v, w, i);
    }
    dijkstra(1);
    dfs(1);
    printf("%d\n", SZ(ans));
    for(int i = 0; i < SZ(ans); i++)printf("%d%c", ans[i], " \n"[i==SZ(ans)-1]);
    return 0;
}

