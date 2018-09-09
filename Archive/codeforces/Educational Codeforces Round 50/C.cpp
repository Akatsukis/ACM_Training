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
int bit[maxn];
ll dp[maxn][maxn];

ll dfs(int len, int num, bool bound)
{
    //printf("dfs(%d,%d) %d\n", len, num, bit[len]);
    if(len == -1)return 1;
    if(!bound && dp[len][num] != -1)return dp[len][num];
    ll ret = 0;
    int to = bound?bit[len]:9;
    for(int i = 0; i <= to; i++){
        int nxt = num+(i!=0);
        if(nxt > 3)continue;
        ret += dfs(len-1, nxt, bound&&i==to);
    }
    if(bound)return ret;
    else return dp[len][num] = ret;
}

ll solve(ll n)
{
    int m = 0;
    if(!n)bit[m++] = 0;
    while(n){
        bit[m++] = n%10;
        n /= 10;
    }
    ll ret = dfs(m-1, 0, 1);
    //printf("ret=%lld\n", ret);
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int T; sc(T);
    while(T--){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        ll ans = solve(r)-solve(l-1);
        printf("%lld\n", ans);
    }
    return 0;
}

