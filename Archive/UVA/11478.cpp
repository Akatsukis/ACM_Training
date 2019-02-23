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
const int INF = 2e4;
const int maxn = 3e3+10;
struct edge
{
    int u, v, w;
    edge(){}
    edge(int u, int v, int w):u(u), v(v), w(w){}
}es[maxn];
int dist[maxn];
vector<pii> G[maxn];
int n, m;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear(), dist[i] = 0;
    for(int i = 1; i <= n; i++)G[0].pb(mk(i, 0));
}

bool negative_loop()
{
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(auto v : G[j]){
                if(dist[v.fi] > dist[j]+v.se){
                    dist[v.fi] = dist[j]+v.se;
                    if(i == n)return 1;
                }
            }
        }
    }
    return 0;
}

bool check(int t)
{
    init();
    for(int i = 0; i < m; i++){
        int u = es[i].u, v = es[i].v, w = es[i].w;
        G[u].pb(mk(v, w-t));
    }
    return !negative_loop();
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            es[i] = edge(u, v, w);
        }
        int l = 1, r = INF, ans = 0;
        while(l <= r){
            int mid = (l+r)>>1;
            if(check(mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        if(ans == INF)puts("Infinite");
        else if(!ans)puts("No Solution");
        else printf("%d\n", ans);
    }
    return 0;
}

