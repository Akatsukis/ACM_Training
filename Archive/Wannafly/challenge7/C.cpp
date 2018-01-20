#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-12;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    ll x, y, t;
    scanf("%lld%lld%lld", &x, &y, &t);
    double p=t/10000.0, q = 1-p;
    int rem = 0;
    ll ans = 0;
    for(int i = 1; i <= 1e7; i++){
        rem += x;
        int now = rem / y;
        rem -= now * y;
        ans += now * q;
    }
    printf("%.12f\n", ans/10000.0);
    return 0;
}

