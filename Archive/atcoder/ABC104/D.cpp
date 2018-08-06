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
const int mod = 1e9+7;
const int maxn = 1e5+10;
char s[maxn];
ll dp[maxn][3];

ll qpow(ll a, ll n)
{
    ll ret = 1;
    while(n){
        if(n&1)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    scanf("%s", s+1);
    int n = strlen(s+1), cnt = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'A'){
            dp[i][0] = dp[i-1][0]+qpow(3, cnt);
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
        }
        else if(s[i] == 'B'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1]+dp[i-1][0];
            dp[i][2] = dp[i-1][2];
        }
        else if(s[i] == 'C'){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2]+dp[i-1][1];
        }
        else{
            dp[i][0] = 3*dp[i-1][0]+qpow(3, cnt);
            dp[i][1] = 3*dp[i-1][1]+dp[i-1][0];
            dp[i][2] = 3*dp[i-1][2]+dp[i-1][1];
            cnt++;
        }
        for(int j = 0; j < 3; j++){
            dp[i][j] %= mod;
            //printf("dp[%d][%d][%d]=%lld\n", i, j, k, dp[i][j][k]);
        }
    }
    printf("%lld\n", dp[n][2]%mod);
    return 0;
}


