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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e3+10;
const int maxm = 3e5+10;
struct edge
{
    int to, nxt;
    ll cap;
}es[maxm];
int head[maxn], iter[maxn], lev[maxn];
int cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, ll cap)
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

ll dfs(int v, int t, ll f)
{
    if(v == t)return f;
    ll ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.cap && lev[e.to] == lev[v]+1){
            ll d = dfs(e.to, t, min(e.cap, f-ret));
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

ll max_flow(int s, int t)
{
    ll ret = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        ret += dfs(s, t, INF64);
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        init();
        int n;
        sc(n);
        int src = 100*25+1, dst = src+1;
        ll sum = 0;
        for(int i = 0; i < n; i++){
            int t;
            sc(t);
            for(int j = 0; j < t; j++){
                ll u, v, k;
                scanf("%lld%lld%lld", &u, &v, &k);
                if(u > v)add_edge(i*25+j, dst, u-v);
                else if(u < v)add_edge(src, i*25+j, v-u), sum += v-u;;
                for(int h = 0; h < k; h++){
                    scanf("%lld%lld", &u, &v);
                    add_edge(i*25+j, 25*(u-1)+(v-1), INF64);
                }
            }
        }
        ll ans = sum-max_flow(src, dst);
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

