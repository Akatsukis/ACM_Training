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
const int maxn = 1e3+10;
const int maxm = 2e4+10;
struct edge
{
    int to, cap, nxt;
}es[maxm];
int head[maxn], iter[maxn], lev[maxn];
int deg[maxn];
vector<int> G[maxn];
stack<int> S;
pii p[maxm];
int cnt;

void init(int n)
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(deg, 0, sizeof(deg));
    for(int i = 0; i <= n; i++)G[i].clear();
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

void solve()
{
    vector<int> ans;
    S.push(1);
    while(!S.empty()){
        int u = S.top();
        bool flag = 0;
        for(auto &v : G[u]){
            if(v != -1){
                flag = 1;
                S.push(v);
                v = -1;
                break;
            } 
        }
        if(!flag){
            S.pop();
            ans.pb(u);
        }
    }
    reverse(ALL(ans));
    for(auto u : ans)printf("%d ", u);
    puts("");
}


int main()
{
    int T, fst = 1;
    sc(T);
    while(T--){
        if(fst)fst = 0;
        else puts("");
        int n, m, num = 0;
        sc(n); sc(m);
        init(n);
        for(int i = 0; i < m; i++){
            int u, v;
            char s[3];
            scanf("%d%d%s", &u, &v, s);
            deg[u]++, deg[v]--;
            if(s[0] == 'U')p[num++] = mk(u, v);
            else G[u].pb(v);
        }
        bool flg = 1;
        int src = n+1, dst = src+1;
        for(int i = 1; i <= n; i++){
            if(deg[i]%2 != 0){
                flg = 0;
                break;
            }
            if(deg[i] > 0)add_edge(src, i, deg[i]/2);
            else if(deg[i] < 0)add_edge(i, dst, -deg[i]/2);
        }
        if(!flg){
            puts("No euler circuit exist");
            continue;
        }
        for(int i = 0; i < num; i++){
            add_edge(p[i].fi, p[i].se, 1);
        }
        max_flow(src, dst);
        for(int i = head[src]; ~i; i = es[i].nxt){
            if(es[i].cap){
                flg = 0;
                break;
            }
        }
        if(!flg)puts("No euler circuit exist");
        else{
            for(int i = 1; i <= n; i++){
                for(int j = head[i]; ~j; j = es[j].nxt){
                    int u = i, v = es[j].to;
                    if(v <= n && es[j].cap)G[u].pb(v);
                }
            }
            /*for(int i = 1; i <= n; i++){
                printf("G[%d]={", i);
                for(auto u:G[i])printf("%d,", u);
                printf("}\n");
            }*/
            solve();
        }
    }
    return 0;
}

