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
const int maxn = 1e3+10;
const int mod = 998244353;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pii>> G(n+1);
        vector<set<short>> st(n+1);
        vector<vector<ll>> dist(n+1, vector<ll>(n+1, 0));
        vector<vector<short>> ans(n+1, vector<short>(n+1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = i==j?0:INF;
            }
        }
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb(mk(v, w)); G[v].pb(mk(u, w));
            if(dist[u][v] > w) {
                dist[u][v] = dist[v][u] = min(dist[u][v], 1LL*w);
                if(!st[u].count(v))st[u].insert(v), st[v].insert(u);
            }
        }
        for(int k = 1; k <= n; k++) {
            for(auto itu = st[k].begin(); itu != st[k].end(); itu++) {
                for(auto itv = itu; itv != st[k].end(); itv++) {
                    int u = *itu, v = *itv;
                    if(dist[u][k]+dist[k][v] < dist[u][v]) {
                        ans[u][v] = ans[v][u] = k;
                        dist[u][v] = dist[v][u] = dist[u][k]+dist[k][v];
                        if(!st[u].count(v))st[u].insert(v), st[v].insert(u);
                    }
                }
            }
        }
        ll res = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                res = (res+ans[i][j])%mod;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}

