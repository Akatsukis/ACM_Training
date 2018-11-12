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
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+10;
vector<pii> G[maxn];
vector<int> G2[maxn];
int dist[maxn];
int dp[maxn], deg[maxn];
int n, m;

void init()
{
    for(int i = 1; i <= n; i++){
        deg[i] = dp[i] = 0;
        G[i].clear(); G2[i].clear();
    }
}

void dijkstra(int s)
{
    for(int i = 1; i <= n; i++)dist[i] = INF;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mk(0, s));
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        if(p.fi < dist[p.se])continue;
        for(auto v : G[p.se]){
            if(dist[v.fi] > dist[p.se]+v.se){
                dist[v.fi] = dist[p.se]+v.se;
                pq.push(mk(dist[v.fi], v.fi));
            }
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && n){
        init();
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb(mk(v, w)); G[v].pb(mk(u, w));
        }
        dijkstra(2);
        for(int i = 1; i <= n; i++){
            for(auto u : G[i]){
                if(dist[i] > dist[u.fi])G2[i].pb(u.fi), deg[u.fi]++;
            }
        }
        dp[1] = 1;
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(!deg[i])q.push(i);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto v : G2[u]){
                dp[v] += dp[u];
                deg[v]--;
                if(!deg[v])q.push(v);
            }
        }
        printf("%d\n", dp[2]);
    }
    return 0;
}

