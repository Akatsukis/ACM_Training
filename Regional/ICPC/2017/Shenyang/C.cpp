#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <bitset>
using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(A) A.begin(),A,end()
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x"=%d\n")
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",sdtin)
#define freout freopen("out.txt","w",stdout)
#define debug cout<<"???"<<endl
#define PI 3.14159265358979323846

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100;
const double zero = 1e-8;
struct Vector
{
    double x, y;
};

inline Vector operator - (Vector a, Vector b)
{
    Vector c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

inline double Sqr(double a)
{
    return a*a;
}

inline int Sign(double a)
{
    if(fabs(a)<=zero)return 0;
    return a < 0 ? -1 : 1;
}

inline bool operator < (Vector a, Vector b)
{
    return Sign(b.y-a.y) > 0 || Sign(b.y-a.y) == 0 && Sign(b.x-a.x) > 0;
}

inline double Max(double a, double b)
{
    return a > b ? a : b;
}

inline double Length(Vector a)
{
    return sqrt(Sqr(a.x)+Sqr(a.y));
}

inline double Cross(Vector a, Vector b)
{
    return a.x*b.y - a.y*b.x;
}

Vector dot[maxn], List[maxn];
double opt[maxn][maxn];
int seq[maxn];
int n, len;
double ans;

bool Compare(Vector a, Vector b)
{
    int temp = Sign(Cross(a, b));
    if(temp != 0)return temp > 0;
    temp = Sign(Length(b) - Length(a));
    return temp > 0;
}

void Solve(int vv)
{
    int t, i, j, _len;
    for(i = len = 0; i < n; i++)
        if(dot[vv] < dot[i])List[len++] = dot[i] - dot[vv];
    for(i = 0; i < len; i++)
        for(j = 0; j < len; j++)
            opt[i][j] = 0;
    sort(List, List + len, Compare);
    double v;
    for(t = 1; t < len; t++){
        _len = 0;
        for(i = t - 1; i >= 0 && Sign(Cross(List[t], List[i])) == 0; i--);
        while(i >= 0){
            v = Cross(List[i], List[t]) / 2;
            seq[_len++] = i;
            for(j = i - 1; j >= 0 && Sign(Cross(List[i] - List[t], List[j] - List[t])) > 0; j--);
            if(j >= 0)v += opt[i][j];
            ans = Max(ans, v);
            opt[t][i] = v;
            i = j;
        }
        for(i = _len - 2; i >= 0; i--)
            opt[t][seq[i]] = Max(opt[t][seq[i]], opt[t][seq[i+1]]);
    }
}
int i;

double Empty()
{
    ans = 0;
    for(i = 0; i < n; i++){
        Solve(i);
    }
    return ans;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(i = 0; i < n; i++){
            scanf("%lf%lf", &dot[i].x, &dot[i].y);
        }
        Empty();
        printf("%.1f\n", ans);
    }
    return 0;
}

