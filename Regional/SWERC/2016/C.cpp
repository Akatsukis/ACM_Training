#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int main()
{
    int D, R, T;
    scanf("%d%d%d", &D, &R, &T);
    int a = 0, b = 0;
    for(int i = 4; i < maxn; i++){
        int u = i, v = i-D;
        if(u >= 4)a += u;
        if(v >= 3)b += v;
        if(a+b == T+R){
            printf("%d\n", R-a);
            break;
        }
    }
    return 0;
}
