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
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
vector<pii> G[maxn];
int in[maxn];
int out[maxn];
int ans[maxn];
ll cost[maxn];
priority_queue<pair<ll, int> > pq;
struct edge
{
    int u, v, w, nxt;
}es[maxn*2];
int head[maxn];
int sz[maxn];
bool vis[maxn];
int n, m, cnt;

void add_edge(int u, int v, int w)
{
    es[cnt].u = u, es[cnt].v = v, es[cnt].w = w, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].u = v, es[cnt].v = u, es[cnt].w = w, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

void dijkstra()
{
    memset(cost, 0x3f, sizeof(cost));
    cost[1] = 0;
    pq.push(mk(0, 1));
    while(!pq.empty()){
        int u = pq.top().se;
        ll w = pq.top().fi;
        if(cost[u] < w)continue;
        pq.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
            int v = es[i].v;
            if(cost[v] > cost[u]+es[i].w){
                cost[v] = cost[u]+es[i].w;
                pq.push(mk(cost[v], v));
            }
        }   
    }
}

void dfs(int u)
{
    sz[u]++;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i].fi, id = G[u][i].se;
        if(vis[v])continue;
        dfs(v);
        sz[u] += sz[v];
        vis[id] = 1;
    }
    if(in[u] == 1){
        vad[u]++;
        sz[u]++;
        ans[pid[u]] = sz[u];
    }
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
    dijkstra();
    for(int i = 0; i < cnt; i++){
        int u = es[i].u, v = es[i].v, w = es[i].w;
        if(cost[v] == cost[u]+w){
            G[u].pb(mk(v, i));
            in[v]++;
            out[u]++;
        }
    }
    dfs(1);
    for(int i = 0; i < m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}

