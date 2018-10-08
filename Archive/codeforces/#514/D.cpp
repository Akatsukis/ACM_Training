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
#define double long double
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const double eps = 1e-12;
const int maxn = 1e5+10;
struct Point
{
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
}pnt[maxn];
int n, state, flg;

bool check(double m)
{
    double l = -1e15, r = 1e15;
    for(int i = 0; i < n; i++){
        if(abs(pnt[i].y) > 2*m)return 0;
        double d = sqrt(abs(pnt[i].y)*(2*m-abs(pnt[i].y)));
        l = max(l, pnt[i].x-d);
        r = min(r, pnt[i].x+d);
    }
    return l <= r;
}

int main()
{
    sc(n);
    state = 0, flg = 1;
    for(int i = 0; i < n; i++){
        scanf("%Lf%Lf", &pnt[i].x, &pnt[i].y);
        if(pnt[i].y > eps){
            if(state == -1)flg = 0;
            else state = 1;
        }
        else if(pnt[i].y < -eps){
            if(state == 1)flg = 0;
            else state = -1;
        }
    }
    if(!flg){
        printf("-1\n");
        return 0;
    }
    double l = 0, r = 1e14, ans = 0;
    for(int i = 0; i < 100; i++){
        double m = (l+r)/2;
        if(check(m)){
            ans = m;
            r = m-eps;
        }
        else l = m+eps;
    }
    printf("%.10Lf\n", ans);
    return 0;
}

