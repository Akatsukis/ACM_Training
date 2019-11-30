#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int b, w;
        scanf("%d%d", &b, &w);
        bool rev = 0;
        if(b > w) {
            swap(b, w);
            rev = 1;
        }
        if(w <= 3*b+1) {
            puts("YES");
            int x = 3-rev, y = 2;
            if(b < w) {
                printf("%d %d\n", x-1, y);
                w--;
            }
            while(b) {
                printf("%d %d\n", x, y);
                printf("%d %d\n", x+1, y);
                w--; b--;
                if(w > b) {
                    printf("%d %d\n", x, y-1);
                    w--;
                }
                if(w > b) {
                    printf("%d %d\n", x, y+1);
                    w--;
                }
                x += 2;
            }
        }
        else {
            puts("NO");
        }
    }
    return 0;
}

