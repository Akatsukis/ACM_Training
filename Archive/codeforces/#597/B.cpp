#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e2+10;
char s[maxn], t[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        int a[3];
        scanf("%d", &n);
        for(int i = 0; i < 3; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%s", s);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            t[i] = 0;
            if(s[i] == 'R') {
                if(a[1]) ans++, a[1]--, t[i] = 'P';
            }
            else if(s[i] == 'P') {
                if(a[2]) ans++, a[2]--, t[i] = 'S';
            }
            else {
                if(a[0]) ans++, a[0]--, t[i] = 'R';
            }
        }
        for(int i = 0; i < n; i++) {
            if(!t[i]) {
                for(int j = 0; j < 3; j++) {
                    if(a[j]) {
                        if(j == 0) t[i] = 'R';
                        else if(j == 1) t[i] = 'P';
                        else t[i] = 'S';
                        a[j]--;
                        break;
                    }

                }
            }
        }
        if(ans >= (n+1)/2) {
            t[n] = 0;
            puts("YES");
            printf("%s\n", t);
        }
        else puts("NO");
    }
    return 0;
}

