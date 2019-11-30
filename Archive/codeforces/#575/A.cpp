#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        long long a[3];
        for(int i = 0; i < 3; i++) scanf("%lld", &a[i]);
        sort(a, a+3);
        long long diff = a[1]-a[0];
        long long take = min(diff, a[2]);
        a[2] -= take;
        long long ans = a[0]+take+a[2]/2;
        printf("%lld\n", ans);
    }
    return 0;
}

