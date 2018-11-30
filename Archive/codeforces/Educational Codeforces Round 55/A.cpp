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
    int T;
    sc(T);
    while(T--){
        int n, d, x, y;
        sc(n); sc(x); sc(y); sc(d);
        int ans = INF;
        if(ABS(x-y)%d == 0)ans = ABS(x-y)/d;
        else{
            int tmp1 = (x-1+d-1)/d;
            if((y-1)%d == 0)ans = min(ans, tmp1+(y-1)/d);
            int tmp2 = (n-x+d-1)/d;
            if((n-y)%d == 0)ans = min(ans, tmp2+(n-y)/d);
        }
        if(ans == INF)ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

