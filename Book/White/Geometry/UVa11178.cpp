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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
struct Point
{
    double x, y;
    Point(double x=0, double y=0):x(x), y(y){}
    void output()
    {
        printf("%f %f\n", x, y);
    }
}p[10];
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Point A, Point B){return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p){return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, double p){return Vector(A.x/p, A.y/p);}

double Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A, A));}
double Angle(Vector A, Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
Vector Rotate(Vector A, double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P-Q;
    double t = Cross(w, u)/Cross(v, w);
    return P+v*t;
}

Point solve(Point A, Point B, Point C)
{
    double a1 = Angle(A-B, C-B), a2 = Angle(B-C, A-C);
    Vector u = Rotate(C-B, a1/3), v = Rotate(B-C, -a2/3);
    return GetLineIntersection(B, u, C, v);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        for(int i = 0; i < 3; i++){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        for(int i = 0; i < 3; i++){
            p[i+3] = solve(p[i], p[(i+1)%3], p[(i+2)%3]);
        }
        for(int i = 3; i < 6; i++){
            printf("%f %f%c", p[i].x, p[i].y, " \n"[i==5]);
        }
    }
    return 0;
}

