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
const int maxn = 120;
ll dp[maxn][maxn][maxn];
int bit[maxn];
int m, d;

ll dfs(int len, int sum, int mod, int bound)
{
    if(len == 0)return sum==d&&mod==0;
    ll &ret = dp[len][sum][mod];
    if(!bound && ret != -1)return ret;
    else if(sum > d)return ret = 0;
    else ret = 0;
    int to = bound?bit[len]:9;
    for(int i = 0; i <= to; i++){
        ret += dfs(len-1, sum+i, (mod*10+i)%d, bound&&i==to);
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(dp, 0, sizeof(dp));
        ll n;
        scanf("%lld", &n);
        ll now = n, m = 0;
        while(now){
            bit[++m] = now%10;
            now /= 10;
        }
        ll ans = 0;
        for(int i = 1; i <= 9*m; i++){
            d = i;
            memset(dp, -1, sizeof(dp));
            ans += dfs(m, 0, 0, 1);
        }
        printf("Case %d: %lld\n", kase++, ans);
    }
    return 0;
}


