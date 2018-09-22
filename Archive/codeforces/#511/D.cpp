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
int tb1[6] = {0, 0, 0, 0, 2, 4};
int tb2[8] = {0, 0, 0, 4, 8, 10, 12, 12};

int main()
{
    ll n, m;
    scanf("%lld%lld", &n, &m);
    if(n > m)swap(n, m);
    ll ans = 0;
    if(n == 1)ans = m/6*6+tb1[m%6];
    else if(n == 2 && m <= 7)ans = tb2[m];
    else ans = n*m/2*2;
    printf("%lld\n", ans);
    return 0;
}

