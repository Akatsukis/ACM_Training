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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int sz = 4;
struct Mat
{
    ll a[sz][sz];
    void init()
    {
        memset(a, 0, sizeof(a));
    }
    void set()
    {
        init();
        for(int i = 0; i < sz; i++)a[i][i] = 1;
    }
};

Mat mul(Mat a, Mat b)
{
    Mat ret;
    ret.init();
    for(int i = 0; i < sz; i++){
        for(int k = 0; k < sz; k++){
            for(int j = 0; j < sz; j++){
                ret.a[i][j] = ((ret.a[i][j]+a.a[i][k]*b.a[k][j]%mod)%mod+mod)%mod;
            }
        }
    }
    return ret;
}

Mat mpow(Mat a, ll n)
{
    Mat ret;
    ret.set();
    while(n){
        if(n&1LL)ret = mul(ret, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ret;
}

int main()
{
    ll n;
    while(scanf("%lld", &n) != EOF){
        if(n == 1)printf("1\n");
        else if(n == 2)printf("5\n");
        else if(n == 3)printf("11\n");
        else if(n == 4)printf("36\n");
        else{
            Mat ret;
            ret.init();
            ret.a[0][0] = 1, ret.a[0][1] = 5, ret.a[0][2] = 1, ret.a[0][3] = -1;
            ret.a[1][0] = ret.a[2][1] = ret.a[3][2] = 1;
            ret = mpow(ret, n-4);
            ll ans = 0;
            ans = (ans+ret.a[0][0]*36)%mod;
            ans = (ans+ret.a[0][1]*11)%mod;
            ans = (ans+ret.a[0][2]*5)%mod;
            ans = (ans+ret.a[0][3])%mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}

