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
ll gcd(ll a, ll b){return b?gcd(b, a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a, b)*b;}
const ll INF = 0x3f3f3f3f;
const int maxn = 1e3+10;
char ans[maxn];
int pt = 0;

void scan(ll &ret)
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

void print(ll x)
{
    if(x > 9)print(x/10);
    ans[pt++] = x%10+'0';
}

struct Rat
{
    ll a = 0, b = 1;
    Rat(){}
    Rat(ll _a, ll _b)
    {
        a = _a, b = _b;
        ll d = gcd(a, b);
        a /= d, b /= d;
    }
    Rat operator + (const Rat &rhs)const
    {
        Rat ret;
        ret.b = lcm(b, rhs.b);
        ret.a = ret.b/b*a+ret.b/rhs.b*rhs.a;
        ll d = gcd(ret.a, ret.b);
        if(d != 1)ret.a /= d, ret.b /= d;
        return ret;
    }
    Rat operator - (const Rat &rhs)const
    {
        Rat ret;
        ret.b = lcm(b, rhs.b);
        ret.a = ret.b/b*a-ret.b/rhs.b*rhs.a;
        ll d = gcd(ret.a, ret.b);
        if(d != 1)ret.a /= d, ret.b /= d;
        return ret;
    }
    Rat operator * (const Rat &rhs)const
    {
        Rat ret;
        ret.a = a*rhs.a;
        ret.b = b*rhs.b;
        ll d = gcd(ret.a, ret.b);
        if(d != 1)ret.a /= d, ret.b /= d;
        return ret;
    }
    Rat operator / (const Rat &rhs)const
    {
        Rat ret;
        ret.a = a*rhs.b;
        ret.b = b*rhs.a;
        ll d = gcd(ret.a, ret.b);
        if(d != 1)ret.a /= d, ret.b /= d;
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
        ll u = a/b, v = a%b;
        pt = 0;
        print(u);
        ans[pt++] = '.';
        //printf("%lld.", u);
        for(int i = 0; i < 30; i++){
            v *= 10;
            ans[pt++] = v/b+'0';
            //printf("%lld", v/b);
            v %= b;
        }
        ans[pt] = 0;
        if(v*10/b >= 5)ans[pt-1]++;
        while(ans[pt-1] > '9'){
            ans[pt-1] = '0';
            pt--;
            ans[pt-1]++;
        }
        puts(ans);
        //puts("");
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

Vector GetPointOnLine(Point A, Point B, Rat t)
{
    return Vector(A.x+t*(B.x-A.x), A.y+t*(B.y-A.y), A.z+t*(B.z-A.z));
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
        Rat s, t, ret(INF, 1);
        bool flg = 0;
        if(LineDistanse3D(p[0], p[1]-p[0], p[2], p[3]-p[2], s)){
            if(s.a > 0 && s.b > 0 && s.a < s.b && LineDistanse3D(p[2], p[3]-p[2], p[0], p[1]-p[0], t)){
                if(t.a > 0 && t.b > 0 && t.a < t.b){
                    flg = 1;
                    Vector p1 = GetPointOnLine(p[0], p[1], s);
                    Vector p2 = GetPointOnLine(p[2], p[3], t);
                    ret = Length(p1-p2);
                }
            }
        }
        if(!flg){
            ret = min(ret, DistanceToSegment(p[0], p[2], p[3]));
            ret = min(ret, DistanceToSegment(p[1], p[2], p[3]));
            ret = min(ret, DistanceToSegment(p[2], p[0], p[1]));
            ret = min(ret, DistanceToSegment(p[3], p[0], p[1]));
        }
        //print(ret.a), putchar(' '), print(ret.b), putchar('\n');
        ret.output();
    }
    return 0;
}


