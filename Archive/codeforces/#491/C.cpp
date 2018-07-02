#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
int main()
{
    ll n;
    scanf("%lld", &n);
    ll l = 1, r = INF64, ans = 0;
    while(l <= r){
        ll m = (l+r)/2;
        ll rem = n, eat = 0;
        while(rem){
            ll now = min(rem, m);
            eat += now;
            rem -= now;
            rem -= rem/10;
        }
        if(eat*2 >= n){
            r = m-1;
            ans = m;
        }
        else l = m+1;
    }
    printf("%lld\n", ans);
    return 0;
}
