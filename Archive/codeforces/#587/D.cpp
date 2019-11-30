#include <bits/stdc++.h>
using namespace std;

long long calc(

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        long long x;
        scanf("%lld", &x);
        int l = 1, r = 1e9, num = 0;
        while(l <= r) {
            int m = (l+r)/2;
            if(calc(m) <= x) {
                num = m;
                l = m+1;
            }
            else r = m-1;
        }
    }
    return 0;
}

