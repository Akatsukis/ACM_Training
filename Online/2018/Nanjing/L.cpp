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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+10;
const int maxk = 11;
ll dist[maxn][maxk];
vector<pii> G[maxn];
struct data
{
    int p, k;
    ll dis;
    data(){}
    data(int p, int k, ll dis):p(p), k(k), dis(dis){}
    bool operator < (const data &rhs)const
    {
        return dis > rhs.dis;
    }
};
int n, m, k;

ll dijkstra(int s, int t)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s][0] = 0;
    priority_queue<data> pq;
    pq.push(data(s, 0, 0));
    while(!pq.empty()){
        data u = pq.top(); pq.pop();
        if(dist[u.p][u.k] < u.dis)continue;
        for(auto v : G[u.p]){
            if(dist[v.fi][u.k] > dist[u.p][u.k]+v.se){
                dist[v.fi][u.k] = dist[u.p][u.k]+v.se;
                pq.push(data(v.fi, u.k, dist[v.fi][u.k]));
            }
            if(u.k < k && dist[v.fi][u.k+1] > dist[u.p][u.k]){
                dist[v.fi][u.k+1] = dist[u.p][u.k];
                pq.push(data(v.fi, u.k+1, dist[v.fi][u.k+1]));
            }
        }
    }
    ll ret = INF64;
    for(int i = 0; i <= k; i++){
        ret = min(ret, dist[t][i]);
    }
    return ret;
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n); sc(m); sc(k);
        for(int i = 0; i <= n; i++)G[i].clear();
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb(mk(v, w));
        }
        ll ans = dijkstra(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}

