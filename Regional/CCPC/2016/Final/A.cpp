#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int a[maxn];
int n;

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)scanf("%d", &a[i]);
        sort(a, a+n, greater<int>());
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i%3 == 2)continue;
            else ans += a[i];
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}
