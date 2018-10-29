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
const int mod = 1e9+7;
const int maxn = 1e5+10;
ll val[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        ll n, k;
        scanf("%lld%lld", &n, &k);
        if((1+k)*k/2 > n)puts("-1");
        else{
            n -= (1+k)*k/2;
            for(int i = 1; i <= k; i++){
                val[i] = i+n/k;
            }
            n %= k;
            ll ans = 1;
            for(int i = k; i >= 1; i--){
                if(n)val[i]++, n--;
                ans = ans*val[i]%mod*(val[i]-1)%mod;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}

