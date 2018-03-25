#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll l, r;
    while(scanf("%lld%lld", &l, &r) != EOF){
        ll ans = 0;
        if(r == 0 || r == 1)ans = 0;
        else if(r == 2)ans = 1;
        else if(l == 0)ans = (r+1)/2;
        else if(r <= l+1)ans = 2;
        else ans = (r-l)/2+1;
        printf("%lld\n", ans);
    }
    return 0;
}
