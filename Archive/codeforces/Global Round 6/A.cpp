#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 200;
char s[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        bool zero = 0, even = 0;
        int sum = 0;
        int n = strlen(s);
        for(int i = 0; i < n; i++) {
            int v = s[i]-'0';
            if(v == 0) {
                if(!zero) {
                    zero = 1;
                }
                else {
                    even = 1;
                }
            }
            else if(v%2 == 0) {
                even = 1;
            }
            sum += v;
        }
        if(zero && even && sum%3 == 0) puts("red");
        else puts("cyan");
    }
    return 0;
}

