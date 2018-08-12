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

int main()
{
    int T; sc(T);
    while(T--){
        int n, m, q;
        sc(n); sc(m); sc(q);
        ll ans = 0;
        for(int i = 0; i < q; i++){
            int x, y;
            sc(x); sc(y);
            int now = INF;
            now = min(now, ABS(x));
            now = min(now, ABS(y));
            now = min(now, ABS(n-x));
            now = min(now, ABS(m-y));
            ans += now;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


