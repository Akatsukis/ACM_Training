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
int dist[2][maxn], pre[2][maxn];
int n, m, S, E;

void init()
{
    for(int i = 1; i <= n; i++)G[i].clear();
}

void dijkstra(int s, int dist[], int pre[])
{
    for(int i = 1; i <= n; i++)dist[i] = INF;
    dist[s] = 0; pre[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(mk(0, s));
    while(!pq.empty()){
        pii p = pq.top(); pq.pop();
        if(p.fi != dist[p.se])continue;
        for(auto v : G[p.se]){
            if(dist[v.fi] > dist[p.se]+v.se){
                dist[v.fi] = dist[p.se]+v.se;
                pre[v.fi] = p.se;
                pq.push(mk(dist[v.fi], v.fi));
            }
        }
    }
}

int main()
{
    bool fst = 1;
    while(scanf("%d%d%d", &n, &S, &E) != EOF){
        init();
        sc(m);
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb(mk(v, w)); G[v].pb(mk(u, w));
        }
        dijkstra(S, dist[0], pre[0]); dijkstra(E, dist[1], pre[1]);
        sc(m);
        int ans = dist[0][E], fr = -1, to = -1;
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if(dist[0][u]+dist[1][v]+w < ans){
                ans = min(ans, dist[0][u]+dist[1][v]+w);
                fr = u, to = v;
            }
            if(dist[0][v]+dist[1][u]+w < ans){
                ans = min(ans, dist[0][v]+dist[1][u]+w);
                fr = v, to = u;
            }
        }
        vector<int> vec;
        if(fr == -1){
            int vt = E;
            while(vt)vec.pb(vt), vt = pre[0][vt];
            reverse(ALL(vec));
        }
        else{
            vector<int> v1, v2;
            int vt = fr;
            while(vt)v1.pb(vt), vt = pre[0][vt];
            reverse(ALL(v1));
            vt = to;
            while(vt)v2.pb(vt), vt = pre[1][vt];
            for(auto u : v1)vec.pb(u);
            for(auto u : v2)vec.pb(u);
        }
        if(fst)fst = 0;
        else puts("");
        for(int i = 0; i < SZ(vec); i++)printf("%d%c", vec[i], " \n"[i==SZ(vec)-1]);
        if(fr == -1)puts("Ticket Not Used");
        else printf("%d\n", fr);
        printf("%d\n", ans);
    }
    return 0;
}

