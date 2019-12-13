#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 4e5+10;
int sum[maxn];
int rk[maxn];
int a[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        int tot = 0;
        for(int i = 1; i <= n; ) {
            int j = 1;
            while(i+j <= n && a[i+j] == a[i]) j++;
            i += j;
            rk[++tot] = j;
            sum[tot] = sum[tot-1]+rk[tot];
        }
        vector<int> ans(3, 0);
        int mx = 0;
        for(int i = 1; i <= tot; i++) {
            int g = sum[i];
            int l = i+1, r = tot, j = -1, k = -1;
            while(l <= r) {
                int m = (l+r)/2;
                if(sum[m]-sum[i] > g) {
                    j = m;
                    r = m-1;
                }
                else l = m+1;
            }
            if(j == -1) break;
            int s = sum[j]-sum[i];
            l = j+1, r = tot;
            while(l <= r) {
                int m = (l+r)/2;
                if(sum[m]*2 <= n) {
                    k = m;
                    l = m+1;
                }
                else r = m-1;
            }
            if(k == -1)break;
            int b = sum[k]-sum[j];
            if(b > g && g+s+b > mx) {
                mx = g+s+b;
                ans = {g, s, b};
            }
        }
        for(int i = 0; i < 3; i++) {
            printf("%d%c", ans[i], " \n"[i==2]);
        }
    }
    return 0;
}

