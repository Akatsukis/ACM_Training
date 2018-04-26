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

int main()
{
    ll n, k, m, d;
    scanf("%lld%lld%lld%lld", &n, &k, &m, &d);
    ll ans = 0;
    for(int i = 1; i <= d; i++){
        __int128 times = (__int128)(i-1)*k+1;
        ll per = n/times;
        per = min(per, m);
        //printf("per=%lld\n", per);
        ans = max(ans, per*i);
        //printf("ans=%lld\n", ans);
    }
    printf("%lld\n", ans);
    return 0;
}

