#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
int sum[maxn][3];
char s[maxn];

int get(char c) {
    if(c == 'R') return 0;
    else if(c == 'G') return 1;
    else return 2;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s+1);
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 3; j++) {
                sum[i][j] = sum[i-1][j];
            }
            for(int j = 0; j < 3; j++) {
                if((i-1+j)%3 == get(s[i])) sum[i][j]++;
                if(i >= k) ans = min(ans, k-(sum[i][j]-sum[i-k][j]));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

