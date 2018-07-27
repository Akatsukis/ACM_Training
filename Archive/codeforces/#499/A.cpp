#include <bits/stdc++.h>
using namespace std;
char s[110];
int tot[110];

int main()
{
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    for(int i = 0; i < n; i++){
        tot[s[i]-'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; ){
        if(tot[i] && k){
            k--;
            ans += i+1;
            i += 2;
        }
        else i++;
    }
    if(k)ans = -1;
    printf("%d\n", ans);
}
