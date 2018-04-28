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
#define debug cout<<">>>STOP"<<endl
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e6+10;
int f[maxn];
ll n;
int mod;

int solve()
{
    f[0] = 10%mod;
    f[1] = 98%mod;
    for(int i = 2; i < maxn; i++){
        f[i] = (f[i-1]*10-f[i-2]+mod)%mod;
        if(f[i] == f[1] && f[i-1] == f[0])return i-1;
    }
    return 0;
}

int qpow(int a, int n, int x)
{
    int ret = 1;
    while(n){
        if(n&1)ret = ret*a%x;
        a = a*a%x;
        n >>= 1;
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%lld%d", &n, &mod);
        int x = solve();
        int ans = (f[qpow(2, n, x)]-1+mod)%mod;
        printf("Case #%d: %d\n", kase++, ans);

    }
    return 0;
}

