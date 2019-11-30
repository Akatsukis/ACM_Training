#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int xl = -maxn, xr = maxn;
        int yl = -maxn, yr = maxn;
        for(int i = 0; i < n; i++) {
            int x, y;
            int f[4];
            scanf("%d%d", &x, &y);
            for(int j = 0; j < 4; j++) {
                scanf("%d", &f[j]);
            }
            if(!f[0]) {
                xl = max(xl, x);
            }
            if(!f[1]) {
                yr = min(yr, y);
            }
            if(!f[2]) {
                xr = min(xr, x);
            }
            if(!f[3]) {
                yl = max(yl, y);
            }
        }
        if(xl <= xr && yl <= yr) {
            printf("1 %d %d\n", xl, yl);
        }
        else puts("0");
    }
    return 0;
}

