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
const int maxn = 1e5+10;
const int maxm = 1e6+10;
struct edge
{
    int to, cap, nxt;
}es[maxm];
int head[maxn], iter[maxn], lev[maxn];
int cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int cap)
{
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
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
    for(int &i = iter[v]; ~i; i = es[i].nxt){
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
    int ret = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        ret += dfs(s, t, INF);
    }
    return ret;
}

int main()
{
    int n, m, sum = 0;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int src = n+m+1, dst = src+1;
        for(int i = 1; i <= n; i++){
            int w;
            sc(w);
            add_edge(i, dst, w);
        }
        for(int i = 1; i <= m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            sum += w;
            add_edge(src, i+n, w);
            add_edge(i+n, u, INF);
            add_edge(i+n, v, INF);
        }
        int ans = sum-max_flow(src, dst);
        printf("%d\n", ans);
    }
    return 0;
}

