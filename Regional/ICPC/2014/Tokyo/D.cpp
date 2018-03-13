#include <cstdio>
#include <iostream>
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
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n",x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",stdin)
#define freout freopen("out.txt","w",stdout)
#define PI 3.14159265358979323846
#define debug cout<<"???"<<endl;

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

const int maxn = 1e3+100;
int d, n, b;
int xx[maxn],h[maxn];

int sgn(double x)
{
    if ( x < -eps ) return -1;
    else if ( x > eps ) return 1;
    else return 0;
}


int cal2_1(double A,double B,double C,double &x1,double &x2)
{
    double delta  = B*B -4*A*C;
    if ( sgn(delta)<0 ){
        return 0;
    }
    x1 = -B+sqrt(delta);
    x2 = -B-sqrt(delta);
    x1 /= 2*A;
    x2 /= 2*A;
    return 1;
}

int judge_valid(double vy,double vx,double len)
{
    for (int i=0; i<n; i++) {
        double x = xx[i]*1.0 - (int)(xx[i]*1.0/len)*len;
        double t = x/vx;
        double y = vy*t - 1/2.0*t*t;
        if ( sgn(y-h[i])<0 )
            return 0;
    }
    return 1;
}

int cal(double v, int k)
{
    double c = sqrt(v*v+d/(1.0*k));
    double b = d/(1.0*k);
    double len = b;
    double x1,x2;//,vx,vy;
    if (cal2_1(2.0,-2.0*c,b,x1,x2) == 0){
        return 0;
    }
    //vy = x1;    vx = c - x1;
    return judge_valid(x1,c-x1,len) || judge_valid(x2,c-x2,len);
}

int check(double v)
{
     for(int i = 0; i <= b; i++){
        if(cal(v,i+1)) return 1;
     }
     return 0;
}

int main()
{
    while(sc(d) != EOF){
        sc(n); sc(b);
        double l = 0, r = 1e9;
        for(int i=0; i<n; i++) {
            sc(xx[i]); sc(h[i]);
        }
        double mid;
        while(l + eps < r){
            mid = (l+r)/2.0;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%.6f\n", r);
    }
    return 0;
}
