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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-12;
const int maxn = 1e4+10;
const int iter = 100;
struct Point
{
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
}pnt[maxn], poly[10];
typedef Point Vector;
int n, m;

Vector operator + (Vector A, Vector B){return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B){return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p){return Vector(A.x*p, A.y*p);}
int dcmp(double x){return x<-eps?-1:x>eps;}
double Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
double Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y;}
Vector rotate(Vector A, double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}

void build(int num, double r)
{
    m = num;
    poly[0] = Point(r, 0);
    for(int i = 1; i < m; i++){
        poly[i] = rotate(poly[i-1], 2*PI/num);
    }
}

double Area()
{
    double ret = 0;
    for(int i = 1; i < m-1; i++){
        ret += Cross(poly[i]-poly[0], poly[i+1]-poly[0]);
    }
    return fabs(ret/2);
}

bool InPolygon(int id)
{
    Point p = pnt[id];
    int wn = 0;
    for(int i = 0; i < m; i++){
        if(OnSegment(p, poly[i], poly[(i+1)%m]))return 1;
        int k = dcmp(Cross(poly[(i+1)%m]-poly[i], p-poly[i]));
        int d1 = dcmp(poly[i].y-p.y);
        int d2 = dcmp(poly[(i+1)%m].y-p.y);
        if(k > 0 && d1 <= 0 && d2 > 0)wn++;
        if(k < 0 && d2 <= 0 && d1 > 0)wn--;
    }
    if(wn)return 1;
    else return 0;
}

bool check1(int num, double r)
{
    build(num, r);
    for(int i = 0; i < n; i++){
        if(InPolygon(i))return 0;
    }
    return 1;
}

bool check2(int num, double r)
{
    build(num, r);
    for(int i = 0; i < n; i++){
        if(!InPolygon(i))return 0;
    }
    return 1;
}

int main()
{
    sc(n);
    for(int i = 0; i < n; i++)scanf("%lf%lf", &pnt[i].x, &pnt[i].y);
    double mx = 0;
    int ans = 0;
    for(int i = 3; i <= 8; i++){
        double l = 0, r = INF, in = 0, out = 0;
        for(int j = 0; j < iter; j++){
            double m1 = (l+r)/2;
            if(check1(i, m1)){
                in = m1;
                l = m1+eps;
            }
            else r = m1-eps;
        }
        l = 0, r = INF, out = 0;
        for(int j = 0; j < iter; j++){
            double m2 = (l+r)/2;
            if(check2(i, m2)){
                out = m2;
                r = m2-eps;
            }
            else l = m2+eps;
        }
        build(i, in);
        double area1 = Area();
        build(i, out);
        double area2 = Area();
        double now = area1/area2;
        if(now > mx){
            mx = now;
            ans = i;
        }
    }
    printf("%d %.10f\n", ans, mx);
    return 0;
}


