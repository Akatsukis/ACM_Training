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
const double eps = 1e-3;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
struct Point
{
    double x, y;
}p[maxn];
int n;

Point CircumCenter(Point a, Point b, Point c)
{
    Point cp;
    double a1 = b.x-a.x, b1 = b.y-a.y, c1 = (a1*a1+b1*b1)/2;
    double a2 = c.x-a.x, b2 = c.y-a.y, c2 = (a2*a2+b2*b2)/2;
    double d = a1*b2-a2*b1;
    cp.x = a.x+(c1*b2-c2*b1)/d;
    cp.y = a.y+(a1*c2-a2*c1)/d;
    return cp;
}

double dis(Point a, Point b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

bool check(Point cp, double r)
{
    if(cp.x > 1e9 || cp.y > 1e9 || r > 1e9)return 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(abs(dis(cp, p[i])-r) < eps)cnt++;
    }
    return cnt >= (n+1)/2;
}

bool solve()
{
    int u = rand()%n, v = rand()%n, w = rand()%n;
    while(v == u)v= rand()%n;
    while(w == u || w == v)w = rand()%n;
    double dx1 = p[u].x-p[v].x, dx2 = p[u].x-p[w].x;
    double dy1 = p[u].y-p[v].y, dy2 = p[u].y-p[w].y;
    if(abs(dx1*dy2-dx2*dy1)<eps)return 0;
    Point cp = CircumCenter(p[u], p[v], p[w]);
    double r = dis(p[u], cp);
    if(check(cp, r)){
        printf("%f %f %f\n", cp.x, cp.y, r);
        return 1;
    }
    else return 0;
}

int main()
{
    srand(unsigned(time(NULL)));
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++){
            scanf("%lf%lf", &p[i].x, &p[i].y);
        }
        if(n <= 2){
            printf("%f %f %f\n", p[0].x, p[0].y, 0.0);
        }
        else if(n <= 4){
            double x = (p[0].x+p[1].x)/2, y = (p[0].y+p[1].y)/2;
            double r = dis(p[0], p[1])/2;
            printf("%f %f %f\n", x, y, r);
        }
        else{
            while(!solve());
        }
    }
    return 0;
}

