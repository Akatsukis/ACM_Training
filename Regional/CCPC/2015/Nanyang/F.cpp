#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+10;
vector<pii> G[maxn];
int x[maxn], y[maxn], w[maxn], c[maxn];
ll dist[maxn];
int n, m;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
}

ll dijkstra(int s = 0)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    pq.push(mk(0, s));
    while(!pq.empty()){
        pll p = pq.top(); pq.pop();
        if(p.fi > dist[p.se])continue;
        for(auto v : G[p.se]){
            if(dist[v.fi] > dist[p.se]+v.se){
                dist[v.fi] = dist[p.se]+v.se;
                pq.push(mk(dist[v.fi], v.fi));
            }
        }
    }
    ll ret = 0;
    for(int i = 1; i <= n; i++){
        if(w[i] == 2){
            if(dist[i] == INF64)return -1;
            else ret += dist[i];
        }
    }
    return ret;
}


int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(m); sc(n);
        init();
        for(int i = 1; i <= m; i++)sc(x[i]);
        for(int i = 1; i <= m; i++)sc(y[i]);
        for(int i = 1; i <= m; i++)sc(c[i]);
        for(int i = 1; i <= m; i++)G[y[i]].pb(mk(x[i], c[i]));
        for(int i = 1; i <= n; i++){
            sc(w[i]);
            if(!w[i])G[0].pb(mk(i, 0));
        }
        ll ans = dijkstra();
        printf("Case #%d: ", kase++);
        if(ans == -1)printf("-1\n");
        else printf("%lld\n", ans);
    }
    return 0;
}

