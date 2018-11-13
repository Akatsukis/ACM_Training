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
    sc(T);
    while(T--){
        int d; sc(d);
        if(d*d-4*d < 0){
            puts("N");
            continue;
        }
        long double delta = sqrt(d*d-4*d);
        long double x1 = (d+delta)/2, x2 = (d-delta)/2;
        if(x1 >= 0 && x2 >= 0)printf("Y %.10Lf %.10Lf\n", x1, x2);
        else puts("N");
    }
    return 0;
}

