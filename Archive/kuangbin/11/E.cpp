#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
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
const int maxn = 60;
const int maxv = 5010;
struct es
{
    int to, cap, rev, cost;
};
vector<es> G[maxv];
bool vis[maxv];
int dist[maxv];
int n, m, k, ans;

void init()
{
    for(int i = 0; i < maxv; i++)G[i].clear();
}

void add_edge(int from, int to, int cap, int cost)
{
    //printf("add(%d,%d,%d,%d)\n", from, to, cap, cost);
    G[from].pb((es){to, cap, (int)G[to].size(), cost});
    G[to].pb((es){from, 0, (int)G[from].size()-1, -cost});
}

bool spfa(int s, int t)
{
    memset(vis, 0, sizeof(vis));
    memset(dist, INF, sizeof(dist));
    dist[t] = 0;
    vis[t] = 1;
    deque<int> q;
    q.pb(t);
    while(!q.empty()){
        int u = q.front(); q.pop_front();
        for(int i = 0; i < (int)G[u].size(); i++){
            es &e = G[u][i];
            if(G[e.to][e.rev].cap && dist[e.to] > dist[u]-e.cost){
                dist[e.to] = dist[u]-e.cost;
                if(!vis[e.to]){
                    vis[e.to] = 1;
                    if(!q.empty() && dist[e.to] < dist[q.front()])q.push_front(e.to);
                    else q.pb(e.to);
                }
            }
        }
        vis[u] = 0;
    }
    return dist[s] < INF;
}

int dfs(int v, int t, int f)
{
    if(v == t){
        vis[v] = 1;
        return f;
    }
    int used = 0;
    vis[v] = 1;
    for(int i = 0; i < (int)G[v].size(); i++){
        es &e = G[v][i];
        if(!vis[e.to] && e.cap && dist[v]-e.cost == dist[e.to]){
            int d = dfs(e.to, t, min(e.cap, f-used));
            if(d > 0){
                ans += d*e.cost;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                used += d;
            }
            if(used == f)break;
        }
    }
    return used;
}

int costflow(int s, int t)
{
    int flow = 0;
    while(spfa(s, t)){
        vis[t] = 1;
        while(vis[t]){
            memset(vis, 0, sizeof(vis));
            flow += dfs(s, t, INF);
        }
    }
    return flow;
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &k) != EOF && (n||m||k)){
        init();
        int src = 0, dst = n*k+m*k+n+m+1;
        for(int i = 0; i < n; i++)add_edge(i*(k+1)+1, dst, INF, 0);
        for(int i = 0; i < m; i++)add_edge(src, n*(k+1)+i*(k+1)+1, INF, 0);
        int foo, tot = 0;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= k; j++){
                sc(foo);
                tot += foo;
                if(foo)add_edge(i*(k+1)+1+j, i*(k+1)+1, foo, 0);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 1; j <= k; j++){
                sc(foo);
                if(foo)add_edge(n*(k+1)+i*(k+1)+1, n*(k+1)+i*(k+1)+1+j, foo, 0);
            }
        }
        for(int i = 1; i <= k; i++){
            for(int j = 0; j < n; j++){
                for(int l = 0; l < m; l++){
                    sc(foo);
                    if(foo)add_edge(n*(k+1)+l*(k+1)+1+i, j*(k+1)+1+i, INF, foo);
                }
            }
        }
        ans = 0;
        int flow = costflow(src, dst);
        if(flow != tot)printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}

