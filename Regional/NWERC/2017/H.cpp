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
const int up = 20;

ll cal(ll u, ll v, ll w)
{
    return sqr(u)+sqr(v)+sqr(w)+7*min(u, min(v, w));
}

int main()
{
    int T; sc(T);
    while(T--){ 
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ll ans = 0;
        for(int i = 0; i <= min(up, d); i++){
            for(int j = 0; i+j <= min(up, d); j++){
                    int k = min(up, d)-i-j;
                    ans = max(ans, cal(a+i, b+j, c+k));
            }
        }
        ans = max(ans, cal(a+d, b, c));
        ans = max(ans, cal(a, b+d, c));
        ans = max(ans, cal(a, b, c+d));
        printf("%lld\n", ans);
    }
    return 0;
}


