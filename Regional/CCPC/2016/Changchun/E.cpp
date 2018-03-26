#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define pb push_back
typedef long long ll;
int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        ll n;
        scanf("%lld", &n);
        ll ans = n*(n+1)/2-1;
        printf("Case #%d: %lld\n", kase++, ans);
    }
}
