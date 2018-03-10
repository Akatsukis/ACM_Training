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
const int maxv = 1010;
const int maxe = 200010;
struct edge
{
    int to, cap, next;
}es[maxe];
int head[maxv];
int iter[maxv];
int lev[maxv];
int cnt;
int dist1[maxv];
int dist2[maxv];
bool vis[maxv];
vector<pii> G[maxv];
vector<pii> H[maxv];

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    for(int i = 0; i < maxv; i++)G[i].clear();
    for(int i = 0; i < maxv; i++)H[i].clear();
}

void add_edge(int from, int to, int cap)
{
    //printf("add(%d,%d,%d)\n", from, to, cap);
    es[cnt].to = to, es[cnt].cap = cap, es[cnt].next = head[from];
    head[from] = cnt++;
    es[cnt].to = from, es[cnt].cap = 0, es[cnt].next = head[to];
    head[to] = cnt++;
}

void spfa(int s, int d[maxv], vector<pii> mp[maxv])
{
    memset(vis, 0, sizeof(vis));
    d[s] = 0;
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        vis[v] = 0;
        for(int i = 0; i < (int)mp[v].size(); i++){
            int u = mp[v][i].fi, w = mp[v][i].se;
            if(d[u] > d[v]+w){
                d[u] = d[v]+w;
                if(!vis[u]){
                    vis[u] = 1;
                    q.push(u);
                }
            }
        }
    }
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].next){
            edge &e = es[i];
            if(e.cap && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    int ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].next){
        edge &e = es[i];
        if(e.cap && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d){
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
                if(ret == f)break;
            }
        }
    }
    if(!ret)lev[v] = 0;
    return ret;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        flow += dfs(s, t, INF);
    }
    return flow;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        int n, m;
        sc(n); sc(m);
        int u, v, w;
        for(int i = 0; i < m; i++){
            sc(u); sc(v); sc(w);
            if(u != v){
                G[u].pb(mk(v, w));
                H[v].pb(mk(u, w));
            }
        }
        int src, dst;
        sc(src); sc(dst);
        memset(dist1, INF, sizeof(dist1));
        memset(dist2, INF, sizeof(dist2));
        spfa(src, dist1, G); spfa(dst, dist2, H);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < (int)G[i].size(); j++){
                if(dist1[i]+dist2[G[i][j].fi]+G[i][j].se==dist1[dst]){
                    add_edge(i, G[i][j].fi, 1);
                }
            }
        }
        int ans = max_flow(src, dst);
        printf("%d\n", ans);
    }
    return 0;
}

