#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
const int maxn = 1e5+10;
map<int, int> mp;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++){
        int x; sc(x);
        mp[x]++;
    }
    int l = 1, r = 10000, ans = 0;
    while(l <= r){
        int m = (l+r)/2;
        int now = 0;
        for(auto u : mp)now += u.second/m;
        if(now >= n){
            ans = m;
            l = m+1;
        }
        else r = m-1;
    }
    printf("%d\n", ans);
}
