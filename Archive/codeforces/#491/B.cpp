#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a+n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(2*sum >= 9*n)break;
        else ans++;
        sum += 5-a[i];
    }
    printf("%d\n", ans);
    return 0;
}
