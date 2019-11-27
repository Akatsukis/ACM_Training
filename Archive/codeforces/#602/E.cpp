#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(auto &x: a) scanf("%d", &x);
    vector<string> ans(n+1, string(n, '0'));
    int pos = 0;
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < n; j++) {
            if(a[j] == i) {
                for(int k = 0; k < i; k++) {
                    ans[(pos+k)%(n+1)][j] = '1';
                }
                pos++;
            }
        }
    }
    printf("%d\n", n+1);
    for(auto s: ans) printf("%s\n", s.c_str());
    return 0;
}

