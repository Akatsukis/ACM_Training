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
const int maxn = 1e4+10;
const int maxp = 5e3;
const int INF = 0x3f3f3f3f;
int pp[maxn], cc[maxn], kk[maxn], vis[maxn];

struct edge
{
    int to, cap, rev;
    edge(){}
    edge(int to, int cap, int rev):to(to), cap(cap), rev(rev){}
};
vector<edge> G[maxn];
int lev[maxn];

void add_edge(int u, int v, int w)
{
    G[u].pb(edge(v, w, SZ(G[v])));
    G[v].pb(edge(u, 0, SZ(G[u])-1));
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &e : G[u]){
            if(e.cap > 0 && lev[e.to] < 0){
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
    for(auto &e : G[v]){
        if(e.cap > 0 && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
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
    while(bfs(s, t))flow += dfs(s, t, INF);
    return flow;
}

int main()
{
    int n, m, d;
    sc(n); sc(m);
    for(int i = 1; i <= n; i++)sc(pp[i]);
    for(int i = 1; i <= n; i++)sc(cc[i]);
    sc(d);
    for(int i = 1; i <= d; i++)sc(kk[i]), vis[kk[i]] = 1;
    int src = maxp+m+1, dst = src+1;
    for(int i = 1; i <= m; i++)add_edge(i+maxp, dst, 1);
    for(int i = 1; i <= n; i++){
        if(!vis[i])add_edge(pp[i], cc[i]+maxp, 1);
    }
    int pre = 0;
    add_edge(src, pre, 1);
    vector<int> ans;
    for(int i = d; i >= 1; i--){
        while(max_flow(src, dst))add_edge(src, ++pre, 1);
        ans.pb(pre);
        add_edge(pp[kk[i]], cc[kk[i]]+maxp, 1);
    }
    reverse(ALL(ans));
    for(auto u : ans)printf("%d\n", u);
    return 0;
}

