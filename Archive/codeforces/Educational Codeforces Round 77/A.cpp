#include <bits/stdc++.h>
using namespace std;

int sqr(int x) { return x*x;}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        long long ans = 0;
        int per = k/n;
        for(int i = 0; i < n; i++) {
            if(i < k%n) ans += sqr(per+1);
            else ans += sqr(per);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

