#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e3+10;
int par[2][maxn], deg[2][maxn], dev[2][maxn];
int cost[2][maxn][maxn];
int dp[maxn];
int cur[maxn];
int sz[maxn];
int n;

void calc() {
    for(int k = 0; k < 2; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sz[k]; j++) {
                cur[j] = deg[k][j];
            }
            for(int j = i; j <= n; j++) {
                cost[k][i][j] = cost[k][i][j-1];
                int p = dev[k][j];
                while(p && !cur[p]) {
                    p = par[k][p];
                    if(p) {
                        cost[k][i][j]++;
                        cur[p]--;
                    }
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < 2; i++) {
        scanf("%d", &sz[i]);
        for(int j = 2; j <= sz[i]; j++) {
            scanf("%d", &par[i][j]);
            deg[i][par[i][j]]++;
        }
        for(int j = 1; j <= n; j++) {
            scanf("%d", &dev[i][j]);
        }
    }
    calc();
    for(int i = 1; i <= n; i++)  {
        for(int j = 1; j <= n; j++) {
            dp[j] = max(dp[j], dp[i-1]+max(cost[0][i][j], cost[1][i][j]));
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}

