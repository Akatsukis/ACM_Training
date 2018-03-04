#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000009;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
int t[maxn];
ll f[maxn];

void init()
{
    f[0] = 1;
    for(int i = 1; i < maxn; i++)f[i] = f[i-1]*i%mod;
}

ll qpow(ll a, ll n)
{   
    ll res = 1;
    while(n){
        if(n%2)res = res*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return res;
}

ll inv(ll a)
{
    return qpow(a, mod-2);
}

ll C(int m, int n)
{
    if(m > n)return 0;
    return f[n]*inv(f[m])%mod*inv(f[n-m])%mod;
}

int main()
{
    init();
    int n, m, k;
    sc(n);sc(m);sc(k);
    for(int i = 0; i < n; i++){
        int x;
        sc(x);
        t[x%k]++;
    }
    ll ans = 0;
    for(int i = 0; i < k; i++){
        ans += C(m, t[i]);
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}

