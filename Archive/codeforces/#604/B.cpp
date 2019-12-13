#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a > b) {
        if(c+d == 0 && a == b+1) {
            puts("YES");
            for(int i = 0; i < b; i++) {
                printf("%d %d ", 0, 1);
            }
            printf("0\n");
        }
        else puts("NO");
        return 0;
    }
    if(d > c) {
        if(a+b == 0 && d == c+1) {
            puts("YES");
            for(int i = 0; i < c; i++) {
                printf("%d %d ", 3, 2);
            }
            printf("3\n");
        }
        else puts("NO");
        return 0;
    }
    int l = min(a, b), r = min(c, d);
    a -= l; b -= l;
    c -= r; d -= r;
    if(b == c) {
        puts("YES");
        int m = b;
        for(int i = 0; i < l; i++) {
            printf("%d %d ", 0, 1);
        }
        for(int i = 0; i < m; i++) {
            printf("%d %d ", 2, 1);
        }
        for(int i = 0; i < r; i++) {
            printf("%d %d ", 2, 3);
        }
    }
    else if(b == c+1) {
        puts("YES");
        int m = c;
        for(int i = 0; i < l; i++) {
            printf("%d %d ", 1, 0);
        }
        printf("1 ");
        for(int i = 0; i < m; i++) {
            printf("%d %d ", 2, 1);
        }
        for(int i = 0; i < r; i++) {
            printf("%d %d ", 2, 3);
        }
    }
    else if(c == b+1) {
        puts("YES");
        int m = b;
        for(int i = 0; i < l; i++) {
            printf("%d %d ", 0, 1);
        }
        for(int i = 0; i < m; i++) {
            printf("%d %d ", 2, 1);
        }
        printf("2 ");
        for(int i = 0; i < r; i++) {
            printf("%d %d ", 3, 2);
        }

    }
    else puts("NO");
    return 0;
}

