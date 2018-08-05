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
const int mod = 1000000007;
const int maxn = 1e3+10;
ll dp[maxn][5][2];

int dfs(int len, int sum, int flg)
{
    //printf("dfs(%d,%d)\n", len, sum);
    if(!len)return flg == 1;
    ll &ret = dp[len][sum][flg];
    if(ret != -1)return ret;
    else ret = 0;
    for(int i = 0; i < 10; i++){
        if(flg && sum == 2 && i == 6)continue;
        if(sum == 3 && i == 6)continue;
        int nx = flg|(sum == 2 && i == 6);
        if(i == 6)ret += dfs(len-1, sum+1, nx);
        else ret += dfs(len-1, 0, nx);
        ret %= mod;
    }
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n; sc(n);
    int ans = dfs(n, 0, 0);
    printf("%d\n", ans);
    return 0;
}


