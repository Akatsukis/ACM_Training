#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}

int main()
{
    int n, q;
    sc(n); sc(q);
    ll u = (n+1)/2, v = n/2;
    ll tot = n/2*(u+v)+(n%2)*u;
    for(int i = 0; i < q; i++){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        ll ans = 0;
        if(x%2 == y%2){
            ans = ((x-1)/2)*(u+v);
            if(x%2)ans += (y+1)/2;
            else ans += u+y/2;
        }
        else{
            ans = tot+((x-1)/2)*(2*n-u-v);
            if(x%2)ans += y/2;
            else ans += n-u+(y+1)/2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


