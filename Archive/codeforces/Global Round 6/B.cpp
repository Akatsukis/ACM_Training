#include <bits/stdc++.h>
using namespace std;
vector<int> vec = {15, 16, 17, 18, 19, 20};

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        long long n;
        scanf("%lld", &n);
        bool flg = 0;
        int base = 14;
        for(auto v: vec) {
            if(n >= v && (n-v)%base == 0) {
                flg = 1;
            }
        }
        if(flg) puts("YES");
        else puts("NO");
    }
    return 0;
}

