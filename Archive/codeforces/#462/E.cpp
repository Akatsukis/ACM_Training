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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define sqr(x) ((x)*(x))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5;
double x[maxn], y[maxn], r[maxn];
int vis[maxn];
int n;

double dis(int u, int v)
{
    return sqr(x[u]-x[v])+sqr(y[u]-y[v]);
}

bool its(int u, int v)
{
    return dis(u, v)<=sqr(r[u]+r[v])&&dis(u,v)>=sqr(r[u]-r[v]);
}

struct Point
{
    double x, y;
    bool operator == (const Point& rbs)const
    {
        return fabs(x-rbs.x)<eps&&fabs(y-rbs.y)<eps;
    }
    Point(){}
    Point(double _x, double _y):x(_x), y(_y){}
}p[maxn*maxn*2];

bool cmp(Point u, Point v)
{
    return fabs(u.x-v.x)<eps?u.y<v.y:u.x<v.x;
}

int main()
{
    int E = 0, V = 0, C = 0;
    sc(n);
    for(int i = 0; i < n; i++){
        scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i!=j && its(i, j))break;
            if(j == n-1)C++;
        }
    }
    if(C != n)C++;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(its(i, j)){
                double d = sqrt(dis(i, j));
                double a = atan2(y[j]-y[i], x[j]-x[i]);
                double da = acos((r[i]*r[i]+d*d-r[j]*r[j])/(2*r[i]*d));
                Point p1 = Point(x[i]+r[i]*cos(a-da), y[i]+r[i]*sin(a-da)), p2 = Point(x[i]+r[i]*cos(a+da), y[i]+r[i]*sin(a+da));
                p[cnt++] = p1, p[cnt++] = p2;
            }
        }
    }
    sort(p, p+cnt, cmp);
    V = unique(p, p+cnt) - p;
    for(int i = 0; i < V; i++){
        for(int j = 0; j < n; j++){
            if(fabs(sqr(p[i].x-x[j])+sqr(p[i].y-y[j])-sqr(r[j]))<eps)E++;
        }
    }
    printf("%d\n", E-V+C+1);
    return 0;
}

