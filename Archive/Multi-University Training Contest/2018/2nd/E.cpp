#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e3+10;
char ans[maxn][maxn];

int main()
{
    int n = 2000, p = 47;
    for(int i = 0; i < p; i++){
        for(int j = 0; j < p; j++){
            for(int k = 0; k < p; k++){
                ans[i*p+j][k*p+(j*k+i)%p] = '1';
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)if(!ans[i][j])ans[i][j] = '0';
        ans[i][n] = 0;
    }
    printf("%d\n", n);
    for(int i = 0; i < n; i++){
        puts(ans[i]);
    }
}
