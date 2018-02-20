#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x:"%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

double sqr(double x)
{
    return x*x;
}

double dis(double x1, double y1, double x2, double y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

int main()
{
    int R, x1, x2, y1, y2;
    scanf("%d%d%d%d%d", &R, &x1, &y1, &x2, &y2);
    if(x1==x2&&y1==y2){
        double x = x1+(double)R/2;
        double y = y1;
        double r = (double)R/2;
        printf("%lf %lf %lf\n", x, y, r);
        return 0;
    }
    double d = dis(x1, y1, x2, y2);
    if(d >= R){
        printf("%d %d %d\n", x1, y1, R);
    }
    else{
        double r = (d+R)/2;
        double x = x2+(x1-x2)/d*r;
        double y = y2+(y1-y2)/d*r;
        printf("%.10f %.10f %.10f\n", x, y, r);
    }
    return 0;
}

