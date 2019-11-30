#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int a[3];
        for(int i = 0; i < 3; i++) scanf("%d", &a[i]);
        sort(a, a+3);
        int ans;
        if(a[0]+a[1] < a[2]) ans = a[0]+a[1];
        else ans = (a[0]+a[1]+a[2])/2;
        printf("%d\n", ans);
    }
    return 0;
}

