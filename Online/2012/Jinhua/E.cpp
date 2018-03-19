#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define sc(x) scanf("%d",&x)
#define sqr(x) ((x)*(x))
const double eps = 1e-5;
const int maxn = 1010;
struct point
{
    double x, y;
    point(){}
    point(double a, double b):x(a), y(b){}
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    friend point operator +(const point &a, const point &b)
    {
        return point(a.x+b.x, a.y+b.y);
    }
    friend point operator -(const point &a, const point &b)
    {
        return point(a.x-b.x, a.y-b.y);
    }
    friend point operator *(const double &a, const point &b)
    {
        return point(a*b.x, a*b.y);
    }
    friend point operator *(const point &a, const double &b)
    {
        return point(a.x*b, a.y*b);
    }
    friend point operator /(const point &a, const double &b)
    {
        return point(a.x/b, a.y/b);
    }
};
int dcmp(double k)
{
    return k<-eps?-1:k>eps?1:0;
}
double dot(const point &a, const point &b)
{
    return a.x*b.x+a.y*b.y;
}
double cross(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}
double abs(const point &o)
{
    return sqrt(dot(o, o));
}
point crosspt(const point &a, const point &b, const point &p, const point &q)
{
    double a1 = cross(b-a, p-a);
    double a2 = cross(b-a, q-a);
    return (p*a2-q*a1)/(a2-a1);
}
point res[maxn];
double r;
int n;
double mysqrt(double n)
{
    return sqrt(max(0.0, n));
}
double sector_area(const point &a, const point &b)
{
    double theta = atan2(a.y, a.x)-atan2(b.y, b.x);
    while(theta <= 0)theta += 2*PI;
    while(theta > 2*PI)theta -= 2*PI;
    theta = min(theta, 2*PI-theta);
    return r*r*theta/2;
}
void circle_cross_line(point a, point b, point o, double r, point ret[], int &num)
{
    double x0 = o.x, y0 = o.y;
    double x1 = a.x, y1 = a.y;
    double x2 = b.x, y2 = b.y;
    double dx = x2-x1, dy = y2-y1;
    double A = dx*dx+dy*dy;
    double B = 2*dx*(x1-x0)+2*dy*(y1-y0);
    double C = sqr(x1-x0)+sqr(y1-y0)-sqr(r);
    double delta = B*B-4*A*C;
    num = 0;
    if(dcmp(delta) >= 0){
        double t1 = (-B-mysqrt(delta))/(2*A);
        double t2 = (-B+mysqrt(delta))/(2*A);
        if(dcmp(t1-1)<=0 && dcmp(t1) >= 0){
            ret[num++] = point(x1+t1*dx, y1+t1*dy);
        }
        if(dcmp(t2-1)<=0&&dcmp(t2) >= 0){
            ret[num++] = point(x1+t2*dx, y1+t2*dy);
        }
    }
}
double calc(const point &a, const point &b)
{
    point p[2];
    int num = 0;
    int ina = dcmp(abs(a)-r) < 0;
    int inb = dcmp(abs(b)-r) < 0;
    if(ina){
        if(inb){
            return fabs(cross(a, b))/2.0;
        }
        else{
            circle_cross_line(a, b, point(0, 0), r, p, num);
            return sector_area(b, p[0])+fabs(cross(a, p[0]))/2.0;
        }
    }
    else{
        if(inb){
            circle_cross_line(a, b, point(0, 0), r, p, num);
            return sector_area(p[0], a)+fabs(cross(p[0], b))/2.0;
        }
        else{
            circle_cross_line(a, b, point(0, 0), r, p, num);
            if(num == 2){
                return sector_area(a, p[0])+sector_area(p[1], b)+fabs(cross(p[0], p[1]))/2.0;
            }
            else return sector_area(a, b);
        }
    }
}
double area()
{
    double ret = 0;
    for(int i = 0; i < n; i++){
        int sgn = dcmp(cross(res[i], res[i+1]));
        if(sgn != 0){
            ret += sgn*calc(res[i], res[i+1]);
        }
    }
    return ret;
}
int main()
{
    double inp[10];
    while(scanf("%lf", &inp[0]) != EOF){
        for(int i = 1; i < 7; i++){
            scanf("%lf", &inp[i]);
        }
        bool flag = 0;
        for(int i = 0; i < 7; i++){
            if(dcmp(inp[i]) != 0)break;
            if(i == 6)flag = 1;
            //printf("in[%d]:%f\n", i, inp[i]);
        }
        if(flag)break;
        r = inp[6];
        sc(n);
        double x0 = inp[0]+inp[2]*cos(inp[3]*PI/180)*inp[4];
        double y0 = inp[1]-1.0/2.0*inp[5]*sqr(inp[4])+inp[2]*sin(inp[3]*PI/180)*inp[4];
        for(int i = 0; i < n; i++){
            res[i].input();
            res[i].x -= x0;
            res[i].y -= y0;
        }
        res[n] = res[0];
        double ans = area();
        printf("%.2f\n", ans);
    }
    return 0;
}
