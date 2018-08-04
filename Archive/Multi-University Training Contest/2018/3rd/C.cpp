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
const int maxn = 10;
int dp[1<<maxn];
int ans[maxn];

int cal_bit(int x)
{
    int ret = 0;
    while(x){
        ret++;
        x -= x&(-x);
    }
    return ret;
}

int main()
{
    int T; sc(T);
    while(T--){
        memset(dp, 0, sizeof(dp));
        int n, m;
        sc(n); sc(m);
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            char s[2];
            int u, v;
            scanf("%s%d%d", s, &u, &v);
            u--, v--;
            if(s[0] == '+'){
                for(int S = (1<<n)-1; S >= 0; S--){
                    if((!((S>>u)&1)) || (!((S>>v)&1)))continue;
                    dp[S] = (dp[S]+dp[S-(1<<u)-(1<<v)])%mod;
                }
            }
            else{
                for(int S = 0; S < (1<<n); S++){
                    if((!((S>>u)&1)) || (!((S>>v)&1)))continue;
                    dp[S] = (dp[S]-dp[S-(1<<u)-(1<<v)]+mod)%mod;
                }
            }
            memset(ans, 0, sizeof(ans));
            for(int S = 0; S < (1<<n); S++){
                int bit = cal_bit(S);
                if(bit%2)continue;
                ans[bit/2] += dp[S];
                ans[bit/2] %= mod;
            }
            for(int j = 1; j <= n/2; j++)printf("%d%c", ans[j], " \n"[j==n/2]);
        }
    }
    return 0;
}


