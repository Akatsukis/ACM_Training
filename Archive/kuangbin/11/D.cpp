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
const int maxn = 110;
const int maxv = 10100;
int n, m, ans;
vector<pii> house;
vector<pii> man;
struct es
{
    int to, cap, rev, cost;
};
vector<es> G[maxv];
bool vis[maxv];
int dist[maxv];

void init()
{
    for(int i = 0; i < maxv; i++)G[i].clear();
    man.clear();
    house.clear();
}

void add_edge(int from, int to, int cap, int cost)
{
    //printf(">>%d %d %d %d\n", from, to, cap, cost);
    G[from].pb((es){to, cap, (int)G[to].size(), cost});
    G[to].pb((es){from, 0, (int)G[from].size()-1, -cost});
}

int dis(int u, int v)
{
    return Abs(man[u].fi-house[v].fi)+Abs(man[u].se-house[v].se);
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
    int used = 0; vis[v] = 1;
    for(int i = 0; i < (int)G[v].size(); i++){
        es &e = G[v][i];
        if(!vis[e.to] && e.cap && dist[v] - e.cost == dist[e.to]){
            int d = dfs(e.to, t, min(e.cap, f-used));
            if(d){
                ans += e.cost*d;
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
    while(scanf("%d%d", &n, &m) != EOF && (n||m)){
        init();
        for(int i = 0; i < n; i++){
            char s[maxn];
            scanf("%s", s);
            for(int j = 0; j < m; j++){
                if(s[j] == 'm')man.pb(mk(i, j));
                if(s[j] == 'H')house.pb(mk(i, j));
            }
        }
        int p = man.size(), q = house.size();
        int src = 0, dst = p+q+1;
        for(int i = 1; i <= p; i++)add_edge(src, i, 1, 0);
        for(int i = 1; i <= q; i++)add_edge(i+p, dst, 1, 0);
        for(int i = 0; i < p; i++){
            for(int j = 0; j < q; j++){
                add_edge(i+1, j+p+1, 1, dis(i, j));
            }
        }
        ans = 0;
        costflow(src, dst);
        printf("%d\n", ans);
    }
    return 0;
}

