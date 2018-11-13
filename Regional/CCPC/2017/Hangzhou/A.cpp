#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+10;
char s[maxn];
int num[26][2];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        memset(num, 0, sizeof(num));
        scanf("%s", s);
        int n = strlen(s);
        for(int i = 0; i < n; i++){
            num[s[i]-'a'][i%2]++;
        }
        int mx[2] = {0, 0};
        for(int i = 0; i < 26; i++){
            mx[0] = max(mx[0], num[i][0]);
            mx[1] = max(mx[1], num[i][1]);
        }
        int ans = n/2-mx[0]+(n+1)/2-mx[1];
        printf("%d\n", ans);
    }
    return 0;
}
