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
const int maxn = 2e5+10;
int fac[maxn], inv[maxn];

int qpow(int a, int n)
{
    int re = 1;
    while(n){
        if(n&1)re = 1LL*re*a%mod;
        a = 1LL*a*a%mod;
        n >>= 1;
    }
    return re;
}

void init()
{
    fac[0] = 1;
    for(int i = 1; i < maxn; i++)fac[i] = 1LL*fac[i-1]*i%mod;
    inv[maxn-1] = qpow(fac[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--)inv[i] = 1LL*inv[i+1]*(i+1)%mod;
}

int C(int n, int m)
{
    return 1LL*fac[n]*inv[m]%mod*inv[n-m]%mod;
}

int main()
{
    init();
    int n, m;
    sc(n); sc(m);
    ll ans = 1;
    for(int i = 2; i*i <= m; i++){
        if(m%i == 0){
            int t = 0;
            while(m%i == 0)m /= i, t++;
            ans = ans*C(n+t-1, t)%mod;
        }
    }
    if(m != 1)ans = ans*C(n, 1)%mod;
    printf("%lld\n", ans);
    return 0;
}

