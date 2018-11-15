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
char s[maxn];
int sum[maxn];
int n, q;

ll qpow(ll a, int n)
{
    ll ret = 1;
    while(n){
        if(n&1)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    sc(n); sc(q);
    scanf("%s", s+1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1]+(s[i]=='1');
    }
    for(int i = 0; i < q; i++){
        int l, r;
        sc(l); sc(r);
        ll one = sum[r]-sum[l-1], zero = (r-l+1)-one;
        ll pre = (qpow(2, one)-1+mod)%mod;
        ll ans = pre*qpow(2, zero)%mod;
        printf("%lld\n", ans);
    }
    return 0;
}

