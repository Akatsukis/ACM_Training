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
const int maxn = 5;
const int sz = 2;
struct Mat
{
    ll a[maxn][maxn];
    void init()
    {
        memset(a, 0, sizeof(a));
    }
    void set(int n)
    {
        init();
        for(int i = 0; i < n; i++)a[i][i] = 1;
    }
};

Mat mul(Mat a, Mat b)
{
    Mat ret;
    ret.init();
    for(int i = 0; i < sz; i++){
        for(int k = 0; k < sz; k++){
            for(int j = 0; j < sz; j++){
                ret.a[i][j] = (ret.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
            }
        }
    }
    return ret;
}

Mat mpow(Mat a, int n)
{
    Mat ret;
    ret.set(sz);
    while(n){
        if(n&1)ret = mul(ret, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ret;
}

ll get(int t)
{
    if(t == 1)return 1;
    if(t == 2)return 3;
    Mat ret;
    ret.init();
    ret.a[0][0] = ret.a[0][1] = ret.a[1][0] = 1;
    ret = mpow(ret, t-2);
    //printf("get(%d)\n", t);
    //for(int i = 0; i < sz; i++){
    //    for(int j = 0; j < sz; j++)printf("%lld ", ret.a[i][j]);
    //    puts("");
    //}
    return (ret.a[0][0]*3%mod+ret.a[0][1])%mod;
}

ll euler(int t)
{
    ll ret = t;
    for(ll i = 2; i*i <= t; i++){
        if(t%i == 0){
            ret = ret/i*(i-1);
            while(t%i == 0)t /= i;
        }
    }
    if(t != 1)ret = ret/t*(t-1);
    return ret;
}

int qpow(ll a, int n)
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
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 1){
            printf("2\n");
            continue;
        }
        ll ans = 0;
        for(ll i = 1; i*i <= n; i++){
            if(n%i == 0){
                ans = (ans+get(i)*euler(n/i)%mod)%mod;
                if(i*i != n)ans = (ans+get(n/i)*euler(i)%mod)%mod;
                //printf("euler(%lld)=%d get(%lld)=%d\n", n/i, euler(n/i), i, get(i));
                //printf("ans=%lld\n", ans);
            }
        }
        ans = ans*qpow(n, mod-2)%mod;
        printf("%lld\n", ans);
    }
    return 0;
}

