#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
const int maxn = 1e4+10;
const int mod = 1e9+7;
int dp[maxn][3];
char s[3][maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n; sc(n);
        for(int i = 0; i < 3; i++){
            scanf("%s", s[i]+1);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            if(i%2 == 1){
                if(s[1][i] == '#')continue;
                if(s[0][i] != '#')dp[i][1] = (dp[i][1]+dp[i-1][0])%mod;
                if(s[2][i] != '#')dp[i][1] = (dp[i][1]+dp[i-1][2])%mod;
            }
            else{
                if(s[1][i] == '#')continue;
                if(s[0][i] != '#')dp[i][0] = dp[i-1][1];
                if(s[2][i] != '#')dp[i][2] = dp[i-1][1];
            }
        }
        printf("Case #%d: %d\n", kase++, dp[n][2]);
    }
}
