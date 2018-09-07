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
const int INF = 0x3f3f3f3f;
const int maxn = 5e5+10;
int a[maxn];

int main()
{
    int n; sc(n);
    int u = 0, v = 0;
    int mx = -INF, mn = INF;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        sc(a[i]);
        if(a[i] >= 0)u++, mn = min(mn, a[i]);
        if(a[i] <= 0)v++, mx = max(mx, a[i]);
        ans += ABS(a[i]);
    }
    if(n == 1){
        printf("%d\n", a[1]);
        return 0;
    }
    if(!v)ans -= mn*2;
    else if(!u)ans += mx*2;
    printf("%lld\n", ans);
    return 0;
}

