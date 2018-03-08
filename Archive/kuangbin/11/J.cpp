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
const int maxv = 60;
const int maxe = 1010;
struct edge
{
    int to, cap, next;
};
edge es[maxe];
int head[maxv];
int lev[maxv];
int iter[maxv];
bool vis[maxv];
int cnt = 0;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
}

void add_edge(int from, int to, int cap)
{
    es[cnt].to = to, es[cnt].cap = cap, es[cnt].next = head[from];
    head[from] = cnt++;
    es[cnt].to = from, es[cnt].cap = cap, es[cnt].next = head[to];
    head[to] = cnt++;
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int i = head[v]; ~i; i = es[i].next){
            edge &e = es[i];
            if(e.cap && lev[e.to] < 0){
                lev[e.to] = lev[v]+1;
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
            int d = dfs(e.to, t, min(f-ret, e.cap));
            if(d){
                ret += d;
                e.cap -= d;
                es[i^1].cap += d;
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
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        flow += dfs(s, t, INF);
    }
    return flow;
}

void solve(int u)
{
    vis[u] = 1;
    for(int i = head[u]; ~i; i = es[i].next){
        if(!vis[es[i].to] && es[i].cap)solve(es[i].to);
    }
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF && (n||m)){
        init();
        int src = 1, dst = 2;
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add_edge(u, v, w);
        }
        max_flow(src, dst);
        solve(src);
        for(int i = 1; i <= n; i++){
            for(int j = head[i]; ~j; j = es[j].next){
                edge &e = es[j];
                if(vis[i]^vis[e.to]&&i<e.to)printf("%d %d\n", i, e.to);
            }
        }
        printf("\n");
    }
    return 0;
}

