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
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
const int INF = 0x3f3f3f3f;
const int maxn = 30;
const int maxv = 50;
const int maxe = 2e3+10;
int a[maxn][maxn];
struct edge
{
    int to, cap, nxt;
}es[maxe];
int head[maxv], lev[maxv], iter[maxv];
int cnt;

void add_edge(int u, int v, int cap)
{
    //printf("add_edge(%d,%d,%d)\n", u, v, cap);
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

void init()
{
    memset(head, -1, sizeof(head));
    cnt = 0;
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
            edge &e = es[i];
            if(lev[e.to] < 0 && e.cap){
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
            int d = dfs(e.to, t, min(f-ret, e.cap));
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
    int T, kase = 1;
    sc(T);
    while(T--){
        int n, m, sum = 0;
        sc(n); sc(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sc(a[i][j]);
                sum += a[i][j];
            }
        }
        int ans = INF;
        int src = n+m+1, dst = src+1;
        int gap = lcm(n, m);
        for(int k = 0; k <= 20*n*m; k += gap){
            init();
            for(int i = 0; i < n; i++)add_edge(src, i, k/n);
            for(int i = 0; i < m; i++)add_edge(i+n, dst, k/m);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    add_edge(i, j+n, a[i][j]);
                }
            }
            int flow = max_flow(src, dst);
            ans = min(ans, sum-flow+k-flow);
        }
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}


