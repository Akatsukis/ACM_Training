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
const double eps = 1e-5;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
struct Edge
{
    int u, v, w;
}es[maxn];
vector<pair<int, double> > G[maxn];
double dist[maxn];
int cnt[maxn];
bool vis[maxn];
int n, m;

bool negative()
{
    queue<int> q;
    for(int i = 1; i <= n; i++){
        dist[i] = 0;
        cnt[i] = vis[i] = 1;
        q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = 0;
        for(auto v : G[u]){
            if(dist[v.fi] > dist[u]+v.se){
                dist[v.fi] = dist[u]+v.se;
                if(!vis[v.fi]){
                    vis[v.fi] = 1;
                    q.push(v.fi);
                    if(++cnt[v.fi] > n)return 1;
                }    
            }
        }
    }
    return 0;
}

bool check(double mid)
{
    for(int i = 1; i <= n; i++)G[i].clear();
    for(int i = 0; i < m; i++){
        G[es[i].u].pb(mk(es[i].v, es[i].w-mid));
    }
    return negative();
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
        double l = 0, r = 1e9, ans = -1;
        while(l+eps < r){
            double mid = (l+r)/2;
            if(check(mid)){
                ans = mid;
                r = mid;
            }
            else l = mid;
        }
        printf("Case #%d: ", kase++);
        if(ans < 0)puts("No cycle found.");
        else printf("%.2f\n", ans);
    }
    return 0;
}

