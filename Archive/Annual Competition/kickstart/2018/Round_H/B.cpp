#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6+10;
char s[maxn];
int sum[maxn];

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        scanf("%s", s+1);
        for(int i = 1; i <= n; i++)sum[i] = sum[i-1]+s[i]-'0';
        int ans = 0, gap = (n+1)/2;
        for(int i = gap; i <= n; i++){
            ans = max(ans, sum[i]-sum[i-gap]);
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}
