#include <bits/stdc++.h>
int main()
{
    int a, b, c, n;
    scanf("%d%d%d%d", &a, &b, &c, &n);
    int ans = n-(a+b-c);
    if(ans <= 0 || c > a || c > b || ans > n || a > n || b > n || c > n)ans = -1;
    printf("%d\n", ans);
    return 0;
}
