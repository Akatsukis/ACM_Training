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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int sz = 2;
int mod;
struct Mat
{
    ll a[sz][sz];
    Mat()
    {
        memset(a, 0, sizeof(a));
    }
    void set()
    {
        memset(a, 0, sizeof(a));
        for(int i = 0; i < sz; i++)a[i][i] = 1;
    }
    Mat operator * (const Mat &b)
    {
        Mat ret;
        for(int i = 0; i < sz; i++){
            for(int k = 0; k < sz; k++){
                for(int j = 0; j < sz; j++){
                    ret.a[i][j] = (ret.a[i][j]+a[i][k]*b.a[k][j])%mod;
                    ret.a[i][j] = (ret.a[i][j]+mod)%mod;
                }
            }
        }
        return ret;
    }
};

int qpow(ll a, int n, int y)
{
    ll ret = 1;
    while(n){
        if(n&1)ret = ret*a%y;
        a = a*a%y;
        n >>= 1;
    }
    return ret;
}

Mat mpow(Mat a, int n)
{
    Mat ret;
    ret.set();
    while(n){
        if(n&1)ret = ret*a;
        a = a*a;
        n >>= 1;
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int x;
        scanf("%d%d", &x, &mod);
        int n = qpow(2, x, (mod+1)*(mod-1))+1;
        Mat ret;
        ret.a[0][0] = 10, ret.a[0][1] = -1, ret.a[1][0] = 1;
        ret = mpow(ret, n-2);
        int ans = (ret.a[0][0]*98+ret.a[0][1]*10-1)%mod;
        ans = (ans+mod)%mod;
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

