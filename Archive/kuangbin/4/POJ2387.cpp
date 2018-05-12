#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mk make_pair
#define fi first
#define se second
const int maxn = 1e5+10;
vector<pii> G[maxn];
int cost[maxn];
int n, m;
void dijkstra(int s)
{
    memset(cost, 0x3f, sizeof(cost));
    cost[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push(mk(0, s));
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        if(cost[p.se] < p.fi)continue;
        for(int i = 0; i < (int)G[p.se].size(); i++){
            pii v = G[p.se][i];
            if(cost[v.fi] > cost[p.se]+v.se){
                cost[v.fi] = cost[p.se]+v.se;
                pq.push(mk(cost[v.fi], v.fi));
            }
        }
    }
}
int main()
{
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].pb(mk(v, w));
        G[v].pb(mk(u, w));
    }
    dijkstra(1);
    printf("%d\n", cost[n]);
}
