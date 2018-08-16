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
const double eps = 1e-8;
const double PI = acos(-1.0);

int main()
{
    int T; sc(T);
    while(T--){
        int n;
        double r; 
        sc(n);
        scanf("%lf", &r);
        double ans = 2*PI*r;
        for(int i = 0; i < n; i++){
            double x, y, c;
            scanf("%lf%lf%lf", &x, &y, &c);
            double d = sqrt(sqr(x)+sqr(y));
            if(d > r+c || d < r-c)continue;
            double ang1 = 2*acos((r*r+d*d-c*c)/(2*r*d))*r;
            double ang2 = 2*acos((c*c+d*d-r*r)/(2*c*d))*c;
            ans += ang2-ang1;
        }
        printf("%.10f\n", ans);
    }
    return 0;
}


