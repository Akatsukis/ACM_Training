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
    int n, h, a, b, k;
    scanf("%d%d%d%d%d", &n, &h, &a, &b, &k);
    for(int i = 0; i < k; i++){
        int ta, fa, tb, fb;
        scanf("%d%d%d%d", &ta, &fa, &tb, &fb);
        int ans = 0;
        if(ta == tb)ans = ABS(fa-fb);
        else{
            if(fa < a && fa < a)ans = ABS(fa-a)+ABS(fb-a)+ABS(ta-tb);
            else if(fa > b && fb > b)ans = ABS(fa-b)+ABS(fb-b)+ABS(ta-tb);
            else ans = ABS(fa-fb)+ABS(ta-tb);
        }
        printf("%d\n", ans);
    }
    return 0;
}


