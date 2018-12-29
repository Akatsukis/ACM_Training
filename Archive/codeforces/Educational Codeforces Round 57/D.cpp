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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5+10;
ll dp[maxn][4];
char s[maxn];
int a[maxn];
int n;

int main()
{
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d%s", &n, s+1);
    for(int i = 1; i <= n; i++)sc(a[i]);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'h'){
            dp[i][0] = dp[i-1][0]+a[i];
            dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }
        else if(s[i] == 'a'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1]+a[i];
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
            dp[i][3] = dp[i-1][3];
        }
        else if(s[i] == 'r'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2]+a[i];
            dp[i][3] = min(dp[i-1][2], dp[i-1][3]);
        }
        else if(s[i] == 'd'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3]+a[i];
        }
        else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        }
        //for(int j = 0; j < 4; j++)printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
    }
    ll ans = INF;
    for(int j = 0; j < 4; j++)ans = min(ans, dp[n][j]);
    printf("%lld\n", ans);
    return 0;
}

