#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        int d = b-a;
        if(b <= 2*a && (a-d)%3 == 0) puts("YES");
        else puts("NO");
    }
    return 0;
}

