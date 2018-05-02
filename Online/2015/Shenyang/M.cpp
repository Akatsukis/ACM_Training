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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
ll cx[maxn], cy[maxn];
ll cx2[maxn], cy2[maxn];

typedef complex<double> point;
typedef pair<point, point> hpl;
const double eps = 1e-10;
const double INF = 1e4;
inline int sgn(double x){return x < -eps ? -1 : x > eps;}
inline double cross(point a, point b){return (conj(a)*b).imag();}
inline double dot(point a, point b){return (conj(a)*b).real();}
inline double satisfy(point a, hpl p){
    return sgn(cross(a-p.fi, p.se-p.fi)) <= 0;
}

point crosspoint(const hpl &a, const hpl &b)
{
    double k = cross(b.fi-b.se, a.fi-b.se);
    k = k/(k-cross(b.fi-b.se, a.se-b.se));
    return a.fi+(a.se-a.fi)*k;
}

bool cmp(const hpl &a, const hpl &b)
{
    int res = sgn(arg(a.se-a.fi)-arg(b.se-b.fi));
    return res == 0 ? satisfy(a.fi, b) : res < 0;
}



int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ll x, y;
                scanf("%lld%lld", &x, &y);
                cx[i] += x, cy[i] += y;
                cx2[i] += sqr(x), cy2[i] += sqr(y);
            }
        }
        printf("Case #%d: ", kase++);
        for(int i = 0; i < n; i++){
            printf("%d%c", solve(i), " \n"[i==n-1]);
        }
    }
    return 0;
}

