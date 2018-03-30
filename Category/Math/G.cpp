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
const ll mod = 200907;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 10;
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

int sz = 3;
Mat mul(Mat m1, Mat m2)
{
    Mat ret;
    ret.init();
    for(int i = 0; i < sz; i++){
        for(int k = 0; k < sz; k++){
            for(int j = 0; j < sz; j++){
                ret.a[i][j] = (ret.a[i][j]+m1.a[i][k]*m2.a[k][j])%mod;
            }
        }
    }
    return ret;
}

Mat mpow(Mat m, ll n)
{
    Mat ret;
    ret.set(sz);
    while(n){
        if(n&1LL)ret = mul(ret, m);
        m = mul(m, m);
        n >>= 1;
    }
    return ret;
}

int main()
{
    ll n;
    while(scanf("%lld", &n) != EOF && n){
        if(n == 1){
            printf("1\n");
            continue;
        }
        Mat ret;
        ret.init();
        ret.a[0][1] = 2, ret.a[0][0] = ret.a[0][2] = ret.a[1][0] = ret.a[2][2] = 1;
        ret = mpow(ret, n-2);
        printf("%lld\n", (2*ret.a[0][0]+ret.a[0][1]+ret.a[0][2])%mod);
    }
    return 0;
}

