#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5010;
char s[maxn][3];
int dp[maxn][maxn];
int sum[maxn][maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++){
        scanf("%s", s[i]);
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)sum[1][i] = 1;
    for(int i = 2; i <= n; i++){
        if(s[i-1][0] == 's'){
            for(int j = 1; j <= n; j++){
                dp[i][j] = sum[i-1][n] - sum[i-1][j-1];
                dp[i][j] = (dp[i][j]+mod)%mod;
            }
        }
        else if(s[i-1][0] == 'f'){
            for(int j = 1; j <= n; j++){
                dp[i][j+1] = dp[i-1][j];
                dp[i][j+1] %= mod;
            }
        }
        for(int j = 1; j <= n; j++){
            sum[i][j] = sum[i][j-1] + dp[i][j];
            sum[i][j] %= mod;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += dp[n][i];
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}

