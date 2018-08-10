#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int mat[maxn];
 
void solve(int n)
{
    if(n <= 1)return;
    else if(n == 2){
        mat[1] = 0;
        mat[0] = 1;
        return;
    }
    int nxt = -1;
    int k = 0, mx = 0;
    while((1<<k) < n)k++;
    mx = (1<<k)-1;
    for(int i = 0; i < n; i++){
        if((i^mx) < n)mat[i] = i^mx;
        else nxt = i;
    }
    solve(nxt+1);
}
 
int main()
{
    int n;
    scanf("%d", &n);
    solve(n);
    for(int i = 0; i < n; i++)printf("%d%c", mat[i], " \n"[i==n-1]);
    return 0;
}
