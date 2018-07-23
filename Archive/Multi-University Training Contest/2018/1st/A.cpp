#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)

int main()
{
    int T; sc(T);
    while(T--){
        int n;
        scanf("%d", &n);
        if(n%3 == 0)printf("%lld\n", 1LL*n*n*n/27);
        else if(n%4 == 0)printf("%lld\n", 1LL*n*n*n/32);
        else printf("-1\n");
    }
}
