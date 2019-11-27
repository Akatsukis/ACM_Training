#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 11;
int mp[maxn][maxn];
int id[maxn][maxn];
int to[maxn*maxn];
double dp[maxn*maxn];
int cnt;

int main()
{
    int n = 10;
    for(int i = n-1; i >= 0; i--) {
        if(i&1) {
            for(int j = 0; j < n; j++) {
                id[i][j] = cnt++;
            }
        }
        else {
            for(int j = n-1; j >= 0; j--) {
                id[i][j] = cnt++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int v;
            scanf("%d", &v);
            to[id[i][j]] = id[i-v][j];
        }
    }
    dp[99] = 0;
    for(int i = 93; i <= 98; i++) {
        dp[i] = 6;
    }
    for(int i = 92; i >= 0; i--) {
        for(int j = 1; j <= 6; j++) {
            dp[i] += (min(dp[i+j], dp[to[i+j]])+1)/6.0;
        }
    }
    printf("%.10f\n", dp[0]);
    return 0;
}

