#include <bits/stdc++.h>
using namespace std;
typedef __int128 ll;
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
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}

void scan(__int128 &ret)
{
    char c; 
    int sgn;
    c = getchar();
    while (c != '-' && (c < '0' || c > '9'))c = getchar();
    sgn = (c=='-')?-1:1;
    ret = (c=='-')?0:(c - '0'); 
    while (c = getchar(), c >= '0' && c <= '9') 
    {
        ret = ret*10+(c-'0'); 
    }
    ret *= sgn;
}

void print(__int128 x)
{
    if(x > 9)print(x/10);
    putchar(x%10+'0');
}

struct Rat
{
    ll a, b;
    Rat(){}
    Rat(ll a, ll b):a(a), b(b){}
    Rat operator + (const Rat &rhs)const
    {
        Rat ret;
        ret.b = lcm(b, rhs.b);
        ret.a = ret.b/b*a+ret.b/rhs.b*rhs.a;
        ll d = gcd(ret.b, ret.a);
        ret.a /= d, ret.b /= d;
        return ret;
    }
    Rat operator - (const Rat &rhs)const
    {
        Rat ret;
        ret.b = lcm(b, rhs.b);
        ret.a = ret.b/b*a-ret.b/rhs.b*rhs.a;
        ll d = gcd(ret.a, ret.b);
        ret.a /= d, ret.b /= d;
        return ret;
    }
    Rat operator * (const Rat &rhs)const
    {
        Rat ret;
        ll d1 = gcd(a, rhs.b);
        ll d2 = gcd(b, rhs.a);
        ret.a = (a/d1)*(rhs.a/d2);
        ret.b = (b/d2)*(rhs.b/d1);
        ll d = gcd(ret.a, ret.b);
        ret.a /= d, ret.b /= d;
        return ret;
    }
    Rat operator / (const Rat &rhs)const
    {
        Rat ret;
        ll d1 = gcd(a, rhs.a);
        ll d2 = gcd(b, rhs.b);
        ret.a = (a/d1)*(rhs.b/d2);
        ret.b = (b/d2)*(rhs.a/d1);
        ll d = gcd(ret.a, ret.b);
        ret.a /= d, ret.b /= d;
        return ret;
    }
    bool operator < (const Rat &rhs)const
    {
        return a*rhs.b<b*rhs.a;
    }
    bool operator == (const Rat &rhs)const
    {
        return a==rhs.a&&b==rhs.b;
    }
    void output()
    {
        if(a < 0 || b < 0){
            putchar('-');
            a = ABS(a); b = ABS(b);
        }
        ll u = a/b, v = a%b;
        //print(a);
        //puts("");
        //print(b);
        //puts("");
        print(u);
        putchar('.');
        //printf("%lld.", u);
        for(int i = 0; i < 30; i++){
            v *= 10;
            print(v/b);
            //printf("%lld", v/b);
            v %= b;
        }
        puts("");
    }
};

struct Point
{
    Rat x, y, z;
    Point(){}
    Point(Rat x, Rat y, Rat z):x(x), y(y), z(z){}
    bool operator == (const Point &rhs)const{return x==rhs.x&&y==rhs.y&&z==rhs.z;}
}p[4];
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x+B.x, A.y+B.y, A.z+B.z);}
Vector operator - (Vector A, Vector B){return Vector(A.x-B.x, A.y-B.y, A.z-B.z);}
Vector operator * (Vector A, Rat p){return Vector(A.x*p, A.y*p, A.z*p);}
Rat Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y+A.z*B.z;}
int dcmp(Rat A)
{
    if(A.a == 0)return 0;
    else if(A.a*A.b > 0)return 1;
    else return -1;
}

bool LineDistanse3D(Point p1, Vector u , Point p2, Vector v, Rat &s)
{
    Rat b = Dot(u, u)*Dot(v, v)-Dot(u, v)*Dot(u, v);
    if(dcmp(b) == 0)return 0;
    Rat a = Dot(u, v)*Dot(v, p1-p2)-Dot(v, v)*Dot(u, p1-p2);
    s = a/b;
    return 1;
}
Vector Cross(Vector A, Vector B)
{
    return Vector(A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x);
}
Rat Length(Vector A){return Dot(A, A);}

Rat DistanceToSegment(Point P, Point A, Point B)
{
    if(A == B)return Length(P-A);
    Vector v1 = B-A, v2 = P-A, v3 = P-B;
    if(dcmp(Dot(v1, v2)) < 0)return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0)return Length(v3);
    else return Length(Cross(v1, v2))/Length(v1);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        for(int i = 0; i < 4; i++){
            ll a, b, c;
            scan(a); scan(b); scan(c);
            //scanf("%lld%lld%lld", &a, &b, &c);
            p[i] = Point(Rat(a, 1), Rat(b, 1), Rat(c, 1));
        }
        Rat ret;
        bool flg = LineDistanse3D(p[0], (p[1]-p[0]), p[2], (p[3]-p[2]), ret);
        if(flg){
            ret = DistanceToSegment(p[0]+(p[1]-p[0])*ret, p[2], p[3]);
        }
        else{
            ret = DistanceToSegment(p[0], p[2], p[3]);
            ret = min(ret, DistanceToSegment(p[1], p[2], p[3]));
            ret = min(ret, DistanceToSegment(p[2], p[0], p[1]));
            ret = min(ret, DistanceToSegment(p[3], p[0], p[1]));
        }
        ret.output();
    }
    return 0;
}


