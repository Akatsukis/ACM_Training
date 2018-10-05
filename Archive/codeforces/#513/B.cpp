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

int f(ll x)
{
    int ret = 0;
    while(x){
        ret += x%10;
        x /= 10;
    }
    return ret;
}

int main()
{
    ll x;
    scanf("%lld", &x);
    ll a = 1, b = 0;
    while(a*10-1 <= x)a *= 10;
    a--, b = x-a;
    int ans = f(a)+f(b);
    printf("%d\n", ans);
    return 0;
}

