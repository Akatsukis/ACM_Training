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
const int maxn = 20;
const int mod = 998244353;
ll dp[maxn][1<<12], pw[maxn];
int bit[maxn];
int t, m;

void init()
{
    memset(dp, -1, sizeof(dp));
    pw[0] = 1;
    for(int i = 1; i < maxn; i++)pw[i] = pw[i-1]*10%mod;
}

ll dfs(int pos, int k, bool bound, bool zero)
{
    //printf("dfs(%d,%d,%d,%d)\n", pos, k, bound, zero);
    if(pos == 0)return 0;
    if(!bound && dp[pos][k] != -1)return dp[pos][k];
    ll ret = 0;
    int to = bound?bit[pos]:9;
    //printf("to=%d\n", to);
    for(int i = 0; i <= to; i++){
        int nk = k|(1<<i);
        if(zero && i == 0)nk = 0;
        if(__builtin_popcount(nk) > t)continue;
        ret += dfs(pos-1, nk, bound&&i==to, zero&&i==0)+i*pw[pos];
        ret %= mod;
    }
    //printf("dp[%d][%d]=%lld\n", pos, k, ret);
    if(!bound)dp[pos][k] = ret;
    return ret;
}

ll cal(ll num)
{
    m = 0;
    if(!num)bit[++m] = 0;
    while(num){
        bit[++m] = num%10;
        num /= 10;
    }
    ll ans = dfs(m, 0, 1, 1);
    //printf("ans=%lld\n", ans);
    return ans;
}

int main()
{
    init();
    ll l, r;
    scanf("%lld%lld%d", &l, &r, &t);
    ll ans = cal(r)-cal(l-1);
    printf("%lld\n", ans);
    return 0;
}

