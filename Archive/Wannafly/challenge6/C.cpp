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
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

ll qp(ll p, ll n)
{
    ll res = 1;
    while(n){
        if(n%2)res = res*p%mod;;
        p = p*p%mod;
        n /= 2;
    }
    return res;
}

int main()
{
    ll n;
    scanf("%lld", &n);
    ll ans;
    if(n <= 1)ans = 0;
    else if(n == 2)ans = 1;
    else{
        ans = ((n-1)%mod)*(n%mod)%mod*qp(2, n-3)%mod;
    }
    printf("%lld\n", ans);
    return 0;
}
