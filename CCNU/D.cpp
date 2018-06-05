#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const int INF = 0x3f3f3f3f;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
const int maxm = 1e6+10;
struct edge
{
    int to, cost, cap, nxt;
}es[maxm];
int head[maxn], dist[maxn];
bool vis[maxn];
int cnt;
int ans;

void init()
{
    memset(head, -1, sizeof(head));
    cnt = ans = 0;
}

void add_edge(int u, int v, int w, int f)
{
    //printf("add(%d, %d, %d, %d)\n", u, v, w, f);
    es[cnt].to = v, es[cnt].cost = w, es[cnt].cap = f, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cost = -w, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

bool dijkstra(int s, int t)
{
    memset(dist, -127, sizeof(dist));
    dist[t] = 0;
    priority_queue<pii> pq;
    pq.push(mk(0, t));
    while(!pq.empty()){
        pii u = pq.top(); pq.pop();
        if(dist[u.se] > u.fi)continue;
        //printf(">>dist[%d]=%d\n", u.se, dist[u.se]);
        for(int i = head[u.se]; ~i; i = es[i].nxt){
            edge e = es[i];
            //printf("dist[%d]=%d, dist[%d]-%d=%d\n", e.to, dist[e.to], u.se, e.cost, dist[u.se]-e.cost);
            if(es[i^1].cap && dist[e.to] < dist[u.se]-e.cost){
                dist[e.to] = dist[u.se]-e.cost;
                pq.push(mk(dist[e.to], e.to));
            }
        }
    }
    return dist[s] > 0;
}

int dfs(int v, int t, int f)
{
    vis[v] = 1;
    if(v == t)return f;
    int ret = 0;
    for(int i = head[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(!vis[e.to] && e.cap && dist[e.to] == dist[v]-e.cost){
            int d = dfs(e.to, t, min(f-ret, e.cap));
            if(d){
                ans += e.cost*d;
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
                if(ret == f)break;
            }
        }
    }
    return ret;
}


int costflow(int s, int t)
{
    int ret = 0;
    while(dijkstra(s, t)){
        vis[t] = 1;
        while(vis[t]){
            memset(vis, 0, sizeof(vis));
            ret += dfs(s, t, INF);
        }
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        int n;
        sc(n);
        for(int i = 0; i < n; i++){
            int w; sc(w);
            add_edge(i, i+n, w, 1);
        }
        for(int i = 0; i < n; i++){
            int w; sc(w);
            add_edge(i, i+n, w, INF);
        }
        int src = 0, dst = 2*n;
        for(int i = 0; i < n; i++){
            int m; sc(m);
            if(!m){
                add_edge(i+n, dst, 0, INF);
                continue;
            }
            for(int j = 0; j < m; j++){
                int t; sc(t);
                add_edge(i+n, t-1, 0, INF);
            }
        }
        costflow(src, dst);
        printf("%d\n", ans);
    }
    return 0;
}
