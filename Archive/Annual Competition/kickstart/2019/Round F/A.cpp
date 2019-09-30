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
const int maxn = 1e2+10;
int dp[maxn][maxn][maxn];
int mn[maxn][maxn];
int h[maxn];

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        memset(dp, 0x3f, sizeof(dp));
        memset(mn, 0x3f, sizeof(mn));
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> dis;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &h[i]);
            dis.push_back(h[i]);
        }
        sort(dis.begin(), dis.end());
        dis.erase(unique(dis.begin(), dis.end()), dis.end());
        int p = dis.size();
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k < p; k++) {
                dp[0][j][k] = 0;
            }
            mn[0][j] = 0;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k < p; k++) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]+1);
                    if(dis[k] == h[i]) {
                        if(j)dp[i][j][k] = min(dp[i][j][k], mn[i-1][j-1]);
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
                    }
                }
            }
            for(int j = 0; j <= m; j++) {
                for(int k = 0; k < p; k++) {
                    mn[i][j] = min(mn[i][j], dp[i][j][k]);
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j < p; j++) {
                ans = min(ans, dp[n][i][j]);
            }
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

