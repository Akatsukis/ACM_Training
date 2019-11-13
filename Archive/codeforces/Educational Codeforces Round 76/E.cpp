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
const int maxn = 2e5+10;
int a[maxn];
int k[3];
int dp[maxn][3];


int main() {
    int n = 0;
    for(int i = 0; i < 3; i++) {
        scanf("%d", &k[i]);
        n += k[i];
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < k[i]; j++) {
            int x;
            scanf("%d", &x);
            a[x] = i;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i-1][k]+(a[i]!=j));
            }
        }
    }
    int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    printf("%d\n", ans);
    return 0;
}

