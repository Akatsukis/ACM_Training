#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF64 = 1e18;
const ll mod = 1e9+7;
int res[3] = {1, 2, 4};


ll calc(ll n)
{
    ll ret = 0, x = 1;
    while(n){
        ret += (n+1)/2*x;
        if(ret > INF64)return ret;
        x++;
        n >>= 1;
    }
    return ret;
}

int main()
{
    //ll test;
    //while(scanf("%lld", &test) != EOF)printf("%lld\n", calc(test));
    int T;
    scanf("%d", &T);
    while(T--){
        ll n;
        scanf("%lld", &n);
        n--;
        if(n <= 2){
            printf("%d\n", res[n]);
            continue;
        }
        ll l = n/2, r = n/2+100, x = 0;
        while(l <= r){
            ll m = (l+r)/2;
            if(calc(m) <= n){
                x = m;
                l = m+1;
            }
            else r = m-1;
        }
        ll ans = 1, gap = 1;
        //printf("x=%lld\n", x);
        while(x >= gap){
            ll l = gap, r = x/gap*gap;
            ll u = (l+r);
            ll v = (r-l)/gap+1;
            //printf("add:(%lld+%lld)*%lld/2\n", l, r, v);
            if(u%2==0)u /= 2;
            else v /= 2;
            u %= mod, v %= mod;
            ans = (ans+u*v%mod)%mod;
            gap *= 2;
        }
        ans = (ans+(n-calc(x))%mod*(x+1))%mod;
        printf("%lld\n", ans);
    }
}
