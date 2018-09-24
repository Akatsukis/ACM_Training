#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define SZ(x) ((int)x.size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+10;
vector<pii> G[maxn];
int dist[maxn][maxn], h[maxn];
int n;
void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
}
bool bellmanFord()
{
    for(int i = 1; i <= n; i++)G[0].pb(mk(i, 0));
    for(int i = 1; i <= n; i++)h[i] = INF;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k < SZ(G[j]); k++){
                pii p = G[j][k];
                if(h[p.fi] > h[j]+p.se){
                    h[p.fi] = h[j]+p.se;
                    if(i == n)return 1;
                }
            }
        }
    }
    return 0;
}
void dijkstra(int s)
{
    for(int i = 1; i <= n; i++)dist[s][i] = INF;
    dist[s][s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mk(0, s));
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        if(dist[s][p.se] < p.fi)continue;
        for(int i = 0; i < SZ(G[p.se]); i++){
            pii v = G[p.se][i];
            if(dist[s][v.fi] > dist[s][p.se]+v.se){
                dist[s][v.fi] = dist[s][p.se]+v.se;
                pq.push(mk(dist[s][v.fi], v.fi));
            }
        }
    }
}
bool johnson()
{
    if(bellmanFord())return 0;//存在负圈
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < SZ(G[i]); j++)
            G[i][j].se += h[i]-h[G[i][j].fi];
    }
    for(int i = 1; i <= n; i++)dijkstra(i);
    return 1;//不存在负圈
}
int main()
{
    while(sc(n) != EOF && n){
        init(); 
        for(int i = 1; i <= n; i++){
            int k; sc(k);
            for(int j = 0; j < k; j++){
                int v, w;
                sc(v); sc(w);
                G[i].pb(mk(v, w));
            }
        }
        johnson();
        int id = 0, mn = INF;
        for(int i = 1; i <= n; i++){
            int cur = 0;
            for(int j = 1; j <= n; j++){
                cur = max(cur, dist[i][j]);
            }
            if(cur < mn)mn = cur, id = i;
        }
        printf("%d %d\n", id, mn);
    }
    return 0;
}
