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

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<vector<pii>> G(n);
        vector<vector<int>> dist(n, vector<int>(n, INF));
        vector<vector<int>> req(n, vector<int>(n, INF));
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            G[u].pb(mk(v, w)); G[v].pb(mk(u, w));
            dist[u][v] = dist[v][u] = w;
            req[u][v] = req[v][u] = w;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        bool flg = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(req[i][j] != INF && req[i][j] != dist[i][j]) {
                    flg = 0;
                }
            }
        }
        printf("Case #%d: ", kase++);
        if(flg) {
            printf("%d\n", m);
            for(int i = 0; i < n; i++) {
                for(auto p: G[i]) {
                    if(i < p.fi) {
                        printf("%d %d %d\n", i+1, p.fi+1, p.se);
                    }
                }
            }
        }
        else puts("Impossible");
    }
    return 0;
}

