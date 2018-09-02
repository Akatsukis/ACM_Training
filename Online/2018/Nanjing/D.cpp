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
const int maxn = 1e4+10;
struct Point
{
    double x, y;
    Point (double x = 0, double y = 0):x(x), y(y){}
}pnt[maxn], ans[maxn];
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B){return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p){return Vector(A.x*p, A.y*p);}
Vector operator / (Vector A, double p){return Vector(A.x/p, A.y/p);}
struct Line
{
    Point P;
    Vector v;
    double ang;
    Line(){}
    Line(Point P, Vector v): P(P), v(v){ang = atan2(v.y, v.x);}
    bool operator < (const Line &L)const
    {
        return ang < L.ang;
    }
}ln[maxn];
double Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
bool Onleft(Line L, Point p){return Cross(L.v, p-L.P) > 0;}
Point GetIntersection(Line a, Line b)
{
    Vector u = a.P-b.P;
    double t = Cross(b.v, u)/Cross(a.v, b.v);
    return a.P+a.v*t;
}

int HalfplaneIntersection(Line* L, int n, Point *poly)
{
    sort(L, L+n);
    int first, last;
    Point *p = new Point[n];
    Line *q = new Line[n];
    q[first=last=0] = L[0];
    for(int i = 1; i < n; i++){
        while(first < last && !Onleft(L[i], p[last-1]))last--;
        while(first < last && !Onleft(L[i], p[first]))first++;
        q[++last] = L[i];
        if(fabs(Cross(q[last].v, q[last-1].v)) < eps){
            last--;
            if(Onleft(q[last], L[i].P))q[last] = L[i];
        }
        if(first < last)p[last-1] = GetIntersection(q[last-1], q[last]);
    }
    while(first < last && !Onleft(q[first], p[last-1]))last--;
    if(last-first <= 1)return 0;
    p[last] = GetIntersection(q[last], q[first]);
    int m = 0;
    for(int i = first ; i <= last; i++)poly[m++] = p[i];
    return m;
}

double area(Point a, Point b, Point c)
{
    double ret = Cross(a, b)+Cross(b, c)+Cross(c, a);
    return fabs(ret);
}

double rotate_calipers(Point *ch, int n)
{
    if(n <= 2)return 0;
    double ret = 0;
    int u = 1, v = 2;
    for(int i = 0; i < n; i++){
        while(area(ch[i], ch[u], ch[(v+1)%n]) > area(ch[i], ch[u], ch[v]))v = (v+1)%n;
        while(area(ch[i], ch[(u+1)%n], ch[v]) > area(ch[i], ch[u], ch[v]))u = (u+1)%n;
        ret = max(ret, area(ch[i], ch[u], ch[v]));
    }
    return ret;
}

int main()
{
    int T; sc(T);
    while(T--){
        int n, r;
        scanf("%d%d", &n, &r);
        for(int i = 0; i < n; i++){
            scanf("%lf%lf", &pnt[i].x, &pnt[i].y);
        }
        reverse(pnt, pnt+n);
        for(int i = 0; i < n; i++){
            Vector v = pnt[(i+1)%n]-pnt[i];
            double ang = atan2(v.y, v.x);
            Point p = Point(pnt[i].x-r*sin(ang), pnt[i].y+r*cos(ang));
            ln[i] = Line(p, v);
        }
        int m = HalfplaneIntersection(ln, n, ans);
        double ret = rotate_calipers(ans, m);
        printf("%.10f\n", ret);
    }
    return 0;
}

