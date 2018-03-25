#include <bits/stdc++.h>
#define sc(x) scanf("%d", &x)
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        if(n&1)printf("Balanced\n");
        else printf("Bad\n");
    }
    return 0;
}
