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

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        ll base = n-k+1;
        ll scr = m/base+1;
        ll ans = scr*n;
        ans -= n-k-m%base;
        printf("%lld\n", ans);
    }
    return 0;
}

