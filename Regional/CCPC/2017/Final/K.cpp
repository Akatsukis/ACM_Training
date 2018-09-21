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
int tb[5] = {1, 9, 41, 109, 205};

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        ull n;
        scanf("%lld", &n);
        printf("Case #%d: ", kase++);
        if(n <= 4)printf("%d\n", tb[n]);
        else{
            ull ans = (120+(n-5)*14)*(n-4)+tb[4];
            printf("%llu\n", ans);
        }
    }
    return 0;
}

