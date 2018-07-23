#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
const int mod = 24*60;

int main()
{
    int T; sc(T);
    while(T--){
        int hh, mm;
        char s[10];
        scanf("%d%d%s", &hh, &mm, s);
        int sgn = s[3] == '+'?1:-1;
        double d;
        sscanf(s+4, "%lf", &d);
        int k = (int)(d*10+0.1);
        int ans = (hh-8)*60+mm+sgn*k*6;
        ans = (ans%mod+mod)%mod;
        printf("%02d:%02d\n", ans/60, ans%60);
    }
}
