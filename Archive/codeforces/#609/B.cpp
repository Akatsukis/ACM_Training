#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long long ans = 0;
    int add[2] = {0};
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ans += x/2;
        if(x%2) add[i%2]++;
    }
    ans += min(add[0], add[1]);
    printf("%lld\n", ans);
    return 0;
}

