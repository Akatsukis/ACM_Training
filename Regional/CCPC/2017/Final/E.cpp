#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
const int maxn = 1e3+10;

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n; sc(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int x; sc(x);
            ans += x+(x+9)/10;
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}
