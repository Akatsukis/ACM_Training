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
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1.0);
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int main()
{
    double r1, r2, d;
    while(scanf("%lf%lf%lf", &r1, &r2, &d) != EOF){
        double ang1 = (sqr(r1)+sqr(d)-sqr(r2))/(2*r1*d);
        double ang2 = (sqr(r2)+sqr(d)-sqr(r1))/(2*r2*d);
        double ans = 2*PI*(sqr(r1)*(1+ang1)+sqr(r2)*(1+ang2));
        printf("%.10f\n", ans);
    }
    return 0;
}

