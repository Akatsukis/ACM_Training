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
const int mod = 998244353;
const int maxn = 1e3+10;
struct Data
{
    int x, y, val;
    Data(){}
    Data(int x, int y, int val):x(x), y(y), val(val){}
    bool operator < (const Data &rhs)const
    {
        return val < rhs.val;
    }
}tb[maxn*maxn];
ll dp[maxn*maxn];
ll sx[maxn*maxn], sy[maxn*maxn], sx2[maxn*maxn], sy2[maxn*maxn], sum[maxn*maxn];
int n, m;

int get(int u, int v)
{
    return (u-1)*m+v;
}

int qpow(ll a, ll n)
{
    ll ret = 1;
    while(n){
        if(n&1LL)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

void add(ll &x, ll y)
{
    x = (x+y%mod)%mod;
}

int main()
{
    sc(n); sc(m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int x; sc(x);
            tb[get(i, j)] = Data(i, j, x);
        }
    }
    sort(tb+1, tb+n*m+1);
    for(int i = 1; i <= n*m; i++){
        ll x = tb[i].x, y = tb[i].y, val = tb[i].val;
        ll t = lower_bound(tb+1, tb+n*m+1, Data(0, 0, val))-(tb+1);
        //printf("x=%lld, y=%lld, t=%lld\n", x, y, t);
        add(dp[i], sum[t]);
        add(dp[i], t*x*x%mod);
        add(dp[i], t*y*y%mod);
        add(dp[i], sx2[t]);
        add(dp[i], sy2[t]);
        //printf("dp[%d]=%lld\n", i, dp[i]);
        add(dp[i], -2LL*x*sx[t]%mod);
        add(dp[i], -2LL*y*sy[t]%mod);
        dp[i] = dp[i]*qpow(t, mod-2)%mod;
        add(sum[i], sum[i-1]+dp[i]);
        add(sx[i], sx[i-1]+x); add(sy[i], sy[i-1]+y);
        add(sx2[i], sx2[i-1]+sqr(x)); add(sy2[i], sy2[i-1]+sqr(y));
        //printf("dp[%d]=%lld\n", i, dp[i]);
        //printf("sx[%d]=%lld, sy[%d]=%lld\n", i, sx[i], i, sy[i]);
        //printf("sx2[%d]=%lld, sy2[%d]=%lld\n", i, sx2[i], i, sy2[i]);
    }
    int u, v;
    sc(u); sc(v);
    for(int i = 1; i <= n*m; i++){
        if(tb[i].x == u && tb[i].y == v){
            printf("%lld\n", (dp[i]+mod)%mod);
            return 0;
        }
    }
    return 0;
}

