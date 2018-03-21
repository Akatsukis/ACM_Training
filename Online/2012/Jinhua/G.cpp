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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-10;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 65;
const int maxe = 3500;
struct edge
{
    int to, cap, cost, nxt;
}es[maxe];
int head[maxn];
int score[maxn];
int credits[maxn];
ll dist[maxn];
bool vis[maxn];
int n, m, k, cnt;

void init()
{
    memset(head, -1, sizeof(head));
    cnt = 0;
}

void add_edge(int u, int v, int cap, int cost)
{
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].cost = cost, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].cost = -cost, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

bool bfs(int s, int t)
{
    memset(dist, -1, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    vis[t] = 1; dist[t] = 0;
    deque<int> q;
    q.pb(t);
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        for(int i = head[u]; ~i; i = es[i].nxt){
            edge &e = es[i];
            if(es[i^1].cap && dist[e.to] < dist[u]-e.cost){
                dist[e.to] = dist[u]-e.cost;
                if(!vis[e.to]){
                    vis[e.to] = 1;
                    if(!q.empty() && dist[e.to] > dist[q.front()])q.push_front(e.to);
                    else q.pb(e.to);
                }
            }
        }
        vis[u] = 0;
    }
    return dist[s] != -1;
}

int dfs(int v, int t, int f)
{
    vis[v] = 1;
    if(v == t)return f;
    int ret = 0;
    for(int i = head[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(!vis[e.to] && e.cap && dist[e.to] == dist[v]-e.cost){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d){
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
    while(bfs(s, t)){
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
    while(scanf("%d%d%d", &n, &k, &m) != EOF && (n||m||k)){
        init();
        int src = n+m, dst = src+1, sum = 0;
        for(int i = 0; i < n; i++)add_edge(i+m, dst, k, 0);
        for(int i = 0; i < m; i++)sc(credits[i]), sum += credits[i];
        for(int i = 0; i < m; i++){
            sc(score[i]);
            if(score[i] < 60)add_edge(src, i, 60-score[i], INF);
            for(int j = max(60, score[i]); j < 100; j++){
                add_edge(src, i, 1, credits[i]*(199-2*j));
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int u; sc(u);
                if(u)add_edge(j, i+m, k, 0);
            }
        }
        costflow(src, dst);
        for(int i = head[src]; ~i; i = es[i].nxt){
            int u = es[i].to;
            score[u] += es[i^1].cap;
        }
        double ans = 0;
        for(int i = 0; i < m; i++){
            if(score[i] < 60){
                ans = 0;
                break;
            }
            else ans += 1.0*credits[i]/sum*(4-3.0*sqr(100-score[i])/1600);
        }
        printf("%.6f\n", ans+eps);
    }
    return 0;
}
