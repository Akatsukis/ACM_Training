#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+10;
char s[2][maxn];
int main()
{
    for(int i = 0; i < 2; i++)scanf("%s", s[i]);
    int n = strlen(s[0]);
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        if(s[0][i] == '0' && s[1][i] == '0'){
            if(s[0][i+1] == '0'){
                s[0][i+1] = 'X';
                ans++;
            }
            else if(s[1][i+1] == '0'){
                s[1][i+1] = 'X';
                ans++;
            }
        }
        else if(s[0][i] == '0' || s[1][i] == '0'){
            if(s[0][i+1] == '0' && s[1][i+1] == '0'){
                s[0][i+1] = s[1][i+1] = 'X';
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
