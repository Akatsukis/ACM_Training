#include <bits/stdc++.h>
using namespace std;

long long calc(long long n, bool mul) {
    long long base = 1, ret = 0;
    for(int i = 1; n >= base; i++, base *= 10) {
        long long l = max(1LL, n-base*10+2), r = n-base+1;
        if(!mul) ret += (l+r)*(r-l+1)/2*i;
        else ret += (r-l+1)*i;
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        long long n;
        scanf("%lld", &n);
        int l = 0, r = 1e9, cnt = 0;
        while(l <= r) {
            int m = (l+r)/2;
            if(calc(m, 0) < n) {
                cnt = m;
                l = m+1;
            }
            else r = m-1;
        }
        n -= calc(cnt, 0);
        l = 0, r = cnt;
        while(l <= r) {
            int m = (l+r)/2;
            if(calc(m, 1) < n) {
                cnt = m;
                l = m+1;
            }
            else r = m-1;
        }
        n -= calc(cnt, 1);
        string s = to_string(cnt+1);
        printf("%c\n", s[n-1]);
    }

    return 0;
}

