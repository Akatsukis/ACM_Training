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
const int maxn = 63;
int odd[maxn], even[maxn];

int main()
{
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    for(int i = 0; i < n; i++){
        ll x;
        scanf("%lld", &x);
        for(int j = maxn-1; j >= 0; j--){
            if(x>>j&1)odd[j]++;
            else even[j]++;
        }
    }
    long long ans = 0, val = 0;
    for(int i = maxn-1; i >= 0; i--){
        //printf("i=%d, (%d,%d)\n", i, even[i], odd[i]);
        if(even[i] > odd[i]){
            if(val+(1LL<<i) <= k){
                ans += 1LL*even[i]*(1LL<<i);
                val += 1LL<<i;
            }
            else ans += 1LL*odd[i]*(1LL<<i);
        }
        else ans += 1LL*odd[i]*(1LL<<i);
        //printf("val=%lld\n", val);
    }
    printf("%lld\n", ans);
    return 0;
}

