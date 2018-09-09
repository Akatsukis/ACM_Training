#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define PB push_back
#define fst first
#define sec second
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ms(a,x) memset(a,x,sizeof(a))
#define pi pair < int ,int >
#define MP make_pair
using namespace std;
typedef long long LL;  
typedef unsigned long long ULL;  
typedef vector <int> VI;  
const int INF = 0x3f3f3f3f;  
const double eps = 1e-10;  
const double dou = 1e-4;
const int MAXN = 310;  
const double PI = acos(-1.0);  
#define sqr(x) ((x)*(x))  
const int N = 310;
double area[N];  
map<pair<int, int>, int> mp;
int n;  
  
int dblcmp(double d){ return d<-eps?-1:d>eps;}  
struct point
{
    double x,y;
    double ang;
    int d;
    point(){}
    point(double x,double y):x(x),y(y){}
    point(double _x,double _y,double _ang,int _d)
    {
    x = _x;
    y = _y;
    ang = _ang;
    d = _d;
    }
    void input()
    {
        int u, v;
        scanf("%d%d", &u, &v);
        int t = mp[MP(u, v)];
        x = u+t*dou, y = v+t*dou;
        mp[MP(u, v)]++;
    }
    double angle(){ return atan2(y,x);}
    point operator + (const point &rhs)const{ return point(x+rhs.x,y+rhs.y);}
    point operator - (const point &rhs)const{ return point(x-rhs.x,y-rhs.y);}
    point operator * (double t)const{ return point(t*x,t*y);}
    point operator / (double t)const{ return point(x/t,y/t);}
    double length() const { return sqrt(x*x+y*y);};
    point unit()const { double l = length();return point(x/l,y/l); }
}tp[N*2];
double cross (const point a,point b){ return a.x*b.y-a.y*b.x ;}
double dist(const point p1,point p2) { return (p1-p2).length();}
struct circle  
{ 
    point c;
    double r;
    int d; 
    void input()  
    {  
        c.input();
        d = 1;  
    }
    bool contain (const circle & cir)const{ return dblcmp(dist(cir.c,c)+cir.r-r)<=0;}
    bool interect (const circle & cir)const{ return dblcmp(dist(cir.c,c)-cir.r-r)<0;}
} cir[N];// tp[N * 2];  
  
double dis(point a, point b)  {return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));} 
int CirCrossCir(circle cir1,circle cir2, point &p1, point &p2)  
{  
    point m = cir2.c-cir1.c;
    point s = cir2.c+cir1.c;
    point m2 = point(sqr(m.x),sqr(m.y));
    double dis2 = m2.x + m2.y, d = -(dis2 - sqr(cir1.r - cir2.r)) * (dis2 - sqr(cir1.r + cir2.r));  
    if (d + eps < 0) return 0;  
    if (d < eps) d = 0;  
    else d = sqrt(d);
    double x = m.x * ((cir1.r + cir2.r) * (cir1.r - cir2.r) + m.x * s.x) + s.x * m2.y;  
    double y = m.y * ((cir1.r+ cir2.r) * (cir1.r - cir2.r) + m.y * s.y) + s.y * m2.x;  
    point dp = m*d;
    dis2 *= 2;
    p1 = point (x-dp.y,y+dp.x)/dis2;
    p2 = point (x+dp.y,y-dp.x)/dis2;
    if (d > eps) return 2;  
    else return 1;  
}  
bool circmp(const circle& u, const circle& v)  
{  
    return dblcmp(u.r - v.r) < 0;  
}  
bool cmp(const point& u, const point& v)  
{  
    if (dblcmp(u.ang - v.ang)) return u.ang < v.ang;  
    return u.d > v.d;  
}  
  
double calc(circle cir, point p1, point p2)  
{  
    double ans = (p2.ang - p1.ang) * sqr(cir.r)
         - cross ( (p1-cir.c),(p2-cir.c)) + cross( p1,p2);
    return ans *0.5; 
}  
  
void CirUnion(circle cir[], int n)  
{  
    circle cir1, cir2;  
    point p1,p2;
    sort(cir, cir + n, circmp);  
    for (int i = 0; i < n; ++i)  
        for (int j = i + 1; j < n; ++j)  
        if (cir[j].contain(cir[i]))
                cir[i].d++;  
    for (int i = 0; i < n; ++i)  
    {  
        int tn = 0, cnt = 0;  
        for (int j = 0; j < n; ++j)  
        {  
            if (i == j) continue;  
            if (CirCrossCir(cir[i],cir[j],p2, p1) < 2) continue;  
        p1.ang = (p1-cir[i].c).angle();
        p2.ang = (p2-cir[i].c).angle();
            p1.d = 1;  
            tp[tn++] = p1;  
            p2.d = -1;  
            tp[tn++] = p2;  
            if (dblcmp(p1.ang - p2.ang) > 0) cnt++;  
        }  
        tp[tn++] = point(cir[i].c.x - cir[i].r, cir[i].c.y, PI, -cnt);  
        tp[tn++] = point(cir[i].c.x - cir[i].r, cir[i].c.y, -PI, cnt);  
        sort(tp, tp + tn, cmp);  
        int p, s = cir[i].d + tp[0].d;  
        for (int j = 1; j < tn; ++j)  
        {  
            p = s;  
            s += tp[j].d;  
            area[p] += calc(cir[i], tp[j - 1], tp[j]);  
        }  
    }  
}  
bool solve(int n, int s, double p)  
{  
    for(int i = 0; i < n; i++)cir[i].r = p;
    memset(area, 0, sizeof(area[0])*(n+1));
    for(int i = 0; i <= n+1; i++)area[i] = 0;
    CirUnion(cir, n);  
    for (int i = 1; i <= n; ++i)  
    {  
        area[i] -= area[i + 1];  
    }  
    for(int i = s; i <= n; i++)if(area[i] > eps)return 1;
    return 0;
}  
  
int main()  
{  
    int T;
    scanf("%d", &T);
    while(T--){
        mp.clear();
        int n, s, R;
        scanf("%d%d", &n, &s);
        for(int i = 0; i < n; i++)cir[i].input();
        scanf("%d", &R);
        double l = 0, r = 1e5, ans = -1;
        while(r-l > 1e-5){
            double m = (l+r)/2;
            if(solve(n, s, m)){
                ans = m;
                r = m-eps;
            }
            else l = m+eps;
        }
        if(ans < 0)puts("The cake is a lie.");
        else printf("%.4f\n", ans+R);
    }
    return 0;  
}



