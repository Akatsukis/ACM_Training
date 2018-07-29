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
const int maxn = 50;
const ll mod = 1e9+9;
int a[maxn], C[maxn];
struct Mat
{
    ll a[maxn][maxn];
    int sz;
    void init()
    {
        memset(a, 0, sizeof(a));
    }
    void set(int n)
    {
        init();
        sz = n;
        for(int i = 0; i < sz; i++)a[i][i] = 1;
    }
    Mat operator * (const Mat &rhs)const
    {
        Mat ret;
        ret.init();
        ret.sz = sz;
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                for(int k = 0; k < sz; k++){
                    ret.a[i][j] = (ret.a[i][j]+a[i][k]*rhs.a[k][j]%mod)%mod; 
                }
            }
        }   
        return ret;
    }
};

Mat mpow(Mat a, ll n)
{
    Mat ret;
    ret.set(a.sz);
    while(n){
        if(n&1LL)ret = ret*a;
        a = a*a;
        n >>= 1LL;
    }
    return ret;
}

int main()
{
    int n, c;
    ll m;
    scanf("%d%lld%d", &n, &m, &c);
    for(int i = 1; i <= n; i++)sc(a[i]);
    Mat ret;
    ret.init();
    ret.sz = n;
    for(int i = 1; i <= c; i++){
        int x; sc(x);
        ret.a[0][x-1]++;
    }
    for(int i = 1; i < n; i++)ret.a[i][i-1] = 1;
    if(m <= n){
        printf("%d\n", a[m]);
        return 0;
    }
    ret = mpow(ret, m-n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans+ret.a[0][i]*a[n-i])%mod;
    }
    printf("%lld\n", ans);
    return 0;
}


