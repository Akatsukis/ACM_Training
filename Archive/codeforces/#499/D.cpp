#include <bits/stdc++.h>
using namespace std;
const int maxn = 70;
int a[maxn];

int main()
{
    int m, n, x;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++){
        printf("1\n");
        fflush(stdout);
        scanf("%d", &x);
        if(x == 0)return 0;
        else if(x < 0)a[i] = -1;
        else a[i] = 1;
    }
    int cnt = 0, l = 1, r = m;
    while(l <= r){
        int m = (l+r)/2;
        printf("%d\n", m);
        fflush(stdout);
        scanf("%d", &x);
        if(x == 0)return 0;
        if(a[cnt] > 0){
            if(x < 0)r = m-1;
            else l = m+1;
        }
        else{
            if(x < 0)l = m+1;
            else r = m-1;
        }
        //printf("l=%d, r=%d, %d\n", l, r, a[cnt]);
        cnt = (cnt+1)%n;
    }
}
