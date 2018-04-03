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
const long double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e4+10;
const int maxm = 2e5+10;
struct edge
{
    int to, nxt;
    long double cap;
}es[maxm];
int head[maxn], iter[maxn], lev[maxn];
pii p[maxm];
int a[maxn];
int N, M, cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, long double cap)
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
            if(e.cap > eps && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

long double dfs(int v, int t, long double f)
{
    if(v == t)return f;
    long double ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.cap > eps && lev[e.to] == lev[v]+1){
            long double d = dfs(e.to, t, min(e.cap, f-ret));
            if(d > eps){
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
                if(ret+eps>=f)break;
            }
        }
    }
    if(ret < eps)lev[v] = 0;
    return ret;
}

long double max_flow(int s, int t)
{
    long double ret= 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        ret += dfs(s, t, INF);
    }
    return ret;
}


bool solve(long double m)
{
    init();
    int src = N+M+1, dst = src+1;
    long double sum = 0;
    for(int i = 1; i <= N; i++)add_edge(i, dst, m);
    for(int i = 1; i <= M; i++){
        int u = p[i].fi, v = p[i].se;
        add_edge(src, i+N, 1), sum += 1;
        add_edge(i+N, u, INF);
        add_edge(i+N, v, INF);
    }
    long double ret = sum-max_flow(src, dst);
    //printf("m=%f, ret=%Lf\n", m, ret);
    return ret > 0;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        M = 0;
        sc(N);
        for(int i = 1; i <= N; i++)sc(a[i]);
        for(int i = 1; i <= N; i++){
            for(int j = i+1; j <= N; j++){
                if(a[i] > a[j])p[++M] = mk(i, j);
            }
        }
        long double l = 0, r = M, ans = 0;
        while(l+eps < r){
            long double m = (l+r)/2.0;
            if(solve(m)){
                ans = m;
                l = m;
            }
            else r = m;
        }
        printf("Case #%d: %.10Lf\n", kase++, ans);
    }
    return 0;
}

