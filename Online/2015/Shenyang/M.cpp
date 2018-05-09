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
const double eps = 1e-10;
const int maxn = 110;
double cx[maxn], cy[maxn];
double cx2[maxn], cy2[maxn];
struct Point
{
    double x, y;
    Point(double x=0, double y=0):x(x), y(y){}
};
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Point A, Point B){return Vector(A.x-B.x, A.y-B.y);}
Vector operator * (Vector A, double p){return Vector(A.x*p, A.y*p);}
Vector operator + (Vector A, double p){return Vector(A.x/p, A.y/p);}
struct Line
{
    Point P;
    Vector v;
    double ang;
    Line(){}
    Line(Point P, Vector v):P(P), v(v){ang = atan2(v.y, v.x);}
    bool operator < (const Line &L)const
    {
        return ang < L.ang;
    }
}line[maxn];
double Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
bool OnLeft(Line L, Point p)
{
    return Cross(L.v, p-L.P) > 0;
}
Point GetIntersection(Line a, Line b)
{
    Vector u = a.P-b.P;
    double t = Cross(b.v, u)/Cross(a.v, b.v);
    return a.P+a.v*t;
}
double HalfplaneIntersection(Line* L, int n)
{
    sort(L, L+n);
    int first, last;
    Point *p = new Point[n];
    Line *q = new Line[n];
    q[first=last=0] = L[0];
    for(int i = 1; i < n; i++){
        while(first < last && !OnLeft(L[i], p[last-1]))last--;
        while(first < last && !OnLeft(L[i], p[first]))first++;
        q[++last] = L[i];
        if(fabs(Cross(q[last].v, q[last-1].v)) < eps){
            last--;
            if(OnLeft(q[last], L[i].P))q[last] = L[i];
        }
        if(first < last)p[last-1] = GetIntersection(q[last-1], q[last]);
    }
    while(first < last && !OnLeft(q[first], p[last-1]))last--;
    if(last-first <= 1)return 0;
    p[last] = GetIntersection(q[last], q[first]);
    vector<Point> vec;
    for(int i = first; i <= last; i++)vec.pb(p[i]);
    double ret = 0;
    for(int i = first+1; i < last; i++){
        ret += Cross(p[i]-p[first], p[i+1]-p[first]);
    }
    return fabs(ret/2);
}
double solve(int u, int n)
{   
    int m = 0;
    for(int i = 0; i < n; i++){
        if(i == u)continue;
        double A = 2*(cx[u]-cx[i]), B = 2*(cy[u]-cy[i]), C = -cx2[u]-cy2[u]+cx2[i]+cy2[i];
        Vector v(B, -A);
        Point p;
        if(fabs(A) > fabs(B))p = Point(-C/A, 0);
        else p = Point(0, -C/B); 
        line[m++] = Line(p, v);
    }
    line[m++] = Line(Point(0, 0), Vector(1, 0));
    line[m++] = Line(Point(4095, 0), Vector(0, 1));
    line[m++] = Line(Point(4095, 4095), Vector(-1, 0));
    line[m++] = Line(Point(0, 4095), Vector(0, -1));
    return HalfplaneIntersection(line, m);
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(cx, 0, sizeof(cx));
        memset(cx2, 0, sizeof(cx2));
        memset(cy, 0, sizeof(cy));
        memset(cy2, 0, sizeof(cy2));
        int n, m;
        sc(n); sc(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                double x, y;
                scanf("%lf%lf", &x, &y);
                cx[i] += x, cy[i] += y;
                cx2[i] += sqr(x), cy2[i] += sqr(y);
            }
        }
        printf("Case #%d: ", kase++);
        for(int i = 0; i < n; i++){
            printf("%.0f%c", solve(i, n), " \n"[i==n-1]);
        }
    }
    return 0;
}
