#include <bits/stdc++.h>
using namespace std;

long long g(int x, int r) {
    long long ret = 0, k = 0;
    for(int i = 1; r; i <<= 1) {
        if(r&i) {
            r ^= i;
            if(!(x&r)) ret += 1<<k;
        }
        if(!(x&i)) k++;
    }
    return ret;
}


long long f(int l, int r) {
    if(l == r-1) return l == 0;
    if(l&1) return f(l+1, r)+2*(g(l, r)-g(l, l));
    if(r&1) return f(l, r-1)+2*(g(r-1, r)-g(r-1, l));
    return 3*f(l>>1, r>>1);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", f(l, r+1));
    }
    return 0;
}

