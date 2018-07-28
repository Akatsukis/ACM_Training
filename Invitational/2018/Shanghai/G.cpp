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
const double eps = 1e-6;
const double PI = acos(-1.0);
struct Point
{
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
}p[4], q[4];
typedef Point Vector;
Vector operator * (Vector A, double p){return Vector(A.x*p, A.y*p);}

Vector Rotate(Vector A, double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        for(int i = 0; i < 4; i++){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        bool flg = 0;
        for(double i = 0; i <= PI; i += PI/360){
            for(int j = 0; j < 4; j++)q[j] = Rotate(p[j], i);
            double mn[2], mx[2];
            mn[0] = mx[0] = q[0].x;
            mn[1] = mx[1] = q[0].y;
            for(int j = 1; j < 4; j++){
                mn[0] = min(mn[0], q[j].x);
                mx[0] = max(mx[0], q[j].x);
                mn[1] = min(mn[1], q[j].y);
                mx[1] = max(mx[1], q[j].y);
            }
            //printf("x(%f,%f)\n", mn[0], mx[0]);
            //printf("y(%f,%f)\n", mn[1], mx[1]);
            bool now = 1;
            for(int j = 0; j < 4; j++){
                //printf("(%f,%f)\n", q[j].x, q[j].y);
                if(fabs(mn[0]-q[j].x) > eps && fabs(mx[0]-q[j].x) > eps)now = 0;
                if(fabs(mn[1]-q[j].y) > eps && fabs(mx[1]-q[j].y) > eps)now = 0;
            }
            if(now){
                flg = 1;
                break;
            }
        }
        if(flg)printf("Case %d: Yes\n", kase++);
        else printf("Case %d: No\n", kase++);
    }
    return 0;
}


