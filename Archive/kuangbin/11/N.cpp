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
const int maxn = 110;
const int maxv = 210;
const int maxe = 40210;
int par[maxn];
bool mp[maxn][maxn];
struct edge
{
    int to, cap, next;
};
edge es[maxe];
int head[maxv];
int iter[maxv];
int lev[maxv];
int cnt;

void init()
{
    memset(mp, 0, sizeof(mp));
    for(int i = 0; i < maxn; i++){
        par[i] = i;
    }
}

int find(int x)
{
    if(par[x]==x)return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x==y)return;
    par[x] = y;
}

void add_edge(int from, int to, int cap)
{
    //printf("add(%d,%d,%d)\n", from, to, cap);
    es[cnt].to = to, es[cnt].cap = cap, es[cnt].next = head[from];
    head[from] = cnt++;
    es[cnt].to = from, es[cnt].cap = 0, es[cnt].next = head[to];
    head[to] = cnt++;
}

void build(int n, int cap)
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    int src = 2*n, dst = src+1;
    for(int i = 0; i < n; i++){
        add_edge(src, i, cap);
        add_edge(i+n, dst, cap);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mp[i][j])add_edge(i-1, j-1+n, 1);
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
        int v = q.front(); q.pop();
        for(int i = head[v]; ~i; i = es[i].next){
            edge &e = es[i];
            if(e.cap && lev[e.to] < 0){
                lev[e.to] = lev[v]+1;
                if(e.to == t)return true;
                q.push(e.to);
            }
        }
    }
    return false;
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
        int n, m, f;
        sc(n); sc(m); sc(f);
        int u, v;
        for(int i = 0; i < m; i++){
            sc(u); sc(v);
            mp[u][v] = 1;
        }
        for(int i = 0; i < f; i++){
            sc(u);sc(v);
            unite(u, v);
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(find(i) == find(j)){
                    for(int k = 1; k <= n; k++){
                        if(mp[i][k]||mp[j][k]){
                            mp[i][k] = mp[j][k] = 1;
                        }
                    }
                }
            }
        }
        int src = n*2, dst = src+1;
        int l = 0, r = n, ans = 0;
        while(l <= r){
            int mid = (l+r)/2;
            build(n, mid);
            int flow = max_flow(src, dst);
            if(flow == n*mid){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

