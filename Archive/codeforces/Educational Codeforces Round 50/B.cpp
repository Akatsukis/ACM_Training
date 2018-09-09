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
    int T; sc(T);
    while(T--){
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        if(k < max(n, m))printf("-1\n");
        else{
            ll ans = min(n, m);
            k -= min(n, m);
            //printf("ans=%lld, k=%lld\n", ans, k);
            if(k%2 == 1){
                if((n-m)%2 == 0)ans += k-2;
                else ans += k-1;
            }
            else{
                if((n-m)%2 == 0)ans += k;
                else ans += k-1;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}

