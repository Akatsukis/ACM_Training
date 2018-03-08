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
#define Abs(x) ((x)>=0?(x):(-(x)))
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
const int maxn = 22;
const int maxv = 810;
const int maxe = 400010;
struct edge
{
    int to, cap, next;
};
edge es[maxe];
int lev[maxv];
int head[maxv];
int iter[maxv];
char ss[maxn][maxn];
vector<pii> L;
int cnt = 0;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    L.clear();
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
    int n, m, d, T, kase = 1;
    sc(T);
    while(T--){
        scanf("%d%d", &n, &d);
        init();
        for(int i = 0; i < n; i++){
            scanf("%s", ss[i]);
        }
        m = strlen(ss[0]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)if(ss[i][j]>'0'){
                add_edge(i*m+j, i*m+j+n*m, ss[i][j]-'0');
                for(int k = -d; k <= d; k++)
                    for(int l = -d; l <= d; l++)
                        if(Abs(k)+Abs(l)<=d&&Abs(k)+Abs(l)>0&&i+k>=0&&i+k<n&&j+l>=0&&j+l<m&&ss[i+k][j+l]>'0')add_edge(i*m+j+n*m, (i+k)*m+(j+l), INF);
            }
        for(int i = 0; i < n; i++){
            char t[maxn];
            scanf("%s", t);
            for(int j = 0; j < m; j++)if(t[j] == 'L')L.pb(mk(i, j));
        }
        int src = n*m*2, dst = src+1;
        for(int i = 0; i < (int)L.size(); i++)add_edge(src, L[i].fi*m+L[i].se, 1);
        for(int i = 0; i < d; i++){
            for(int j = 0; j < m; j++){
                if(i < n)add_edge(i*m+j+n*m, dst, INF);
                if(n-1-i >= 0)add_edge((n-1-i)*m+j+n*m, dst, INF);
            }
            for(int j = 0; j < n; j++){
                if(i < m)add_edge(j*m+i+n*m, dst, INF);
                if(m-1-i >= 0)add_edge(j*m+(m-1-i)+n*m, dst, INF);
            }
        }
        int ans = L.size()-max_flow(src, dst);
        if(!ans)printf("Case #%d: no lizard was left behind.\n", kase++);
        else if(ans == 1)printf("Case #%d: 1 lizard was left behind.\n", kase++);
        else printf("Case #%d: %d lizards were left behind.\n", kase++, ans);
    }
    return 0;
}

