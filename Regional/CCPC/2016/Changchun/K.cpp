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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100;
ll bit[maxn], high[maxn], low[maxn], pow2[maxn];
int len;

int get()
{
    ll ret = 0;
    for(int i = len-1; i >= 1; i--){
        if(bit[i])ret = (ret+low[i-1]+1)%mod;
        ret = (ret+1LL*high[i+1]*pow2[i-1]%mod)%mod;
    }
    return ret;
}

int getlcp()
{
    ll ret = 0;
    for(int i = len-1; i >= 1; i--){
        if(bit[i])ret = (ret+1LL*(low[i-1]+1)*(low[i-1]+1)%mod)%mod;
        ret = (ret+1LL*high[i+1]*pow2[i-1]%mod*pow2[i-1]%mod)%mod;
    }
    return ret;
}

int main()
{
    pow2[0] = 1;
    for(int i = 1; i < maxn; i++)pow2[i] = (pow2[i-1]<<1)%mod;
    int T, kase = 1;
    sc(T);
    while(T--){
        ll n;
        scanf("%lld", &n);
        ll ans = 0; 
        len = 1;
        for(ll now = n; now; now >>= 1)bit[len++] = now%2;
        high[len] = 0, low[0] = bit[0];
        for(int i = 1; i < len; i++)low[i] = (low[i-1]+bit[i]*(1LL<<(i-1)))%mod;
        for(int i = len-1; i >= 1; i--)high[i] = ((high[i+1]<<1)+bit[i])%mod;
        ans = (ans+(n+1)%mod*get())%mod;
        ans = (ans-getlcp()+mod)%mod;
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

