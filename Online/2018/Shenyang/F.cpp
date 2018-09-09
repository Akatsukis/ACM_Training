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
const int maxn = 5e3+10;
const int maxm = 1e5+10;
struct edge
{
    int to, cap, next;
}es[maxm*2];
int head[maxn];
int lev[maxn], iter[maxn];
int cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int from, int to, int cap)
{
    es[cnt].to = to, es[cnt].cap = cap, es[cnt].next = head[from];
    head[from] = cnt++;
    es[cnt].to = from, es[cnt].cap = 0, es[cnt].next = head[to];
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
            if(e.cap > 0 && lev[e.to] < 0){
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
        if(e.cap > 0 && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d > 0){
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

void solve(int s, int t)
{
    int flow = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        flow += dfs(s, t, INF);
    }
}

int main()
{
    int kase = 1;
    int n, m, k;
    while(~scanf("%d%d%d", &n, &m, &k)){
        init();
        int src = n+m+1, dst = src+1;
        int sps = dst+1, spd = sps+1;
        int l, r;
        sc(l); sc(r);
        for(int i = 0; i < k; i++){
            int u, v;
            sc(u); sc(v);
            v += n;
            add_edge(u, v, 1);
        }
        for(int i = 1; i <= n; i++){
            add_edge(src, spd, l);
            add_edge(sps, i, l);
            add_edge(src, i, r-l);
        }
        for(int i = 1; i <= m; i++){
            add_edge(i+n, spd, l);
            add_edge(sps, dst, l);
            add_edge(i+n, dst, r-l);
        }
        add_edge(dst, src, INF);
        solve(sps, spd);
        bool flg = 1;
        for(int i = head[sps]; ~i; i = es[i].next){
            if(es[i].cap){
                flg = 0;
                break;
            }
        }
        printf("Case %d: ", kase++);
        if(flg)puts("Yes");
        else puts("No");
    }
    return 0;
}
