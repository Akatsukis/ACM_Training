#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4+10;
vector<pll> G[maxn];
ll dist[maxn];
int n, m, x;

ll dijkstra(int t)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(mk(dist[1], 1));
    while(!pq.empty()){
        pll u = pq.top(); pq.pop();
        if(u.fi < dist[u.se])continue;
        for(auto v : G[u.se]){
            if(dist[v.fi] > dist[u.se]+v.se && v.se <= t){
                dist[v.fi] = dist[u.se]+v.se;
                pq.push(mk(dist[v.fi], v.fi));
            }
        }
    }
    if(dist[n] == INF64)return 1e14;
    else return dist[n];
}

int main()
{
    scanf("%d%d%d", &n, &m, &x);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].pb(mk(v, w));
        G[v].pb(mk(u, w));
    }
    ll st = dijkstra(INF);
    int l = 0, r = INF, ans = 0;
    while(l <= r){
        int mid = (l+r)>>1;
        if(dijkstra(mid)*100 <= st*(100+x)){
            ans = mid;
            r =  mid-1;
        }
        else l = mid+1;
    }
    printf("%d\n", ans);
    return 0;
}


