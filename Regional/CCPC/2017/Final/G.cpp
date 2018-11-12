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
const int maxn = 2e3+10;
int dp[maxn][maxn];
int nxt[maxn];
int n, m, k;

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        memset(dp, 0, sizeof(dp));
        memset(nxt, 0, sizeof(nxt));
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            for(int j = u; j <= v; j++)nxt[j] = max(nxt[j], v);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= k; j++){
                if(nxt[i])dp[nxt[i]][j+1] = max(dp[nxt[i]][j+1], dp[i-1][j]+nxt[i]-i+1);
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
                dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            }
        }
        printf("Case #%d: %d\n", kase++, dp[n][k]);
    }
    return 0;
}

