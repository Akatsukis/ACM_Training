#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5+10;
constexpr int mod = 1e9+7;
int f[maxn];
char s[maxn];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    f[1] = 1, f[2] = 2;
    for(int i = 3; i <= n; i++) {
        f[i] = (f[i-1]+f[i-2])%mod;
    }
    int ans = 1;
    for(int i = 0; i < n;) {
        if(s[i] == 'm' || s[i] == 'w') {
            ans = 0;
            break;
        }
        if(s[i] == 'u' || s[i] == 'n') {
            int j = 1;
            while(i+j < n && s[i+j] == s[i]) j++;
            ans = 1LL*ans*f[j]%mod;
            i += j;
        }
        else i++;
    }
    printf("%d\n", ans);
    return 0;
}

