#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int r, b, k;
        scanf("%d%d%d", &r, &b, &k);
        int d = __gcd(r, b);
        r /= d, b /= d;
        if(r < b) swap(r, b);
        if((r-1+b-1)/b < k) puts("OBEY");
        else puts("REBEL");
    }
    return 0;
}

