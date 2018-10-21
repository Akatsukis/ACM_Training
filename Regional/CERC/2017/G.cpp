#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, int> pii;
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
const int maxn = 3e5+10;
vector<int> G[maxn];
double dist[maxn], sum[maxn];
int num[maxn], deg[maxn];
bool vis[maxn];
int n, m;

void dijkstra(int s = n)
{
    for(int i = 1; i <= n; i++)dist[i] = INF;
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mk(dist[s], s));
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        if(vis[p.se])continue;
        else vis[p.se] = 1;
        for(auto v : G[p.se]){
            if(vis[v])continue;
            sum[v] += p.fi; num[v]++;
            if(dist[v] > (sum[v]+deg[v])/num[v]){
                dist[v] = (sum[v]+deg[v])/num[v];
                pq.push(mk(dist[v], v));
            }
        }
    }
}

int main()
{
    sc(n); sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v); G[v].pb(u);
    }
    for(int i = 1; i <= n; i++)deg[i] = SZ(G[i]);
    dijkstra();
    printf("%.10f\n", dist[1]);
    return 0;
}

