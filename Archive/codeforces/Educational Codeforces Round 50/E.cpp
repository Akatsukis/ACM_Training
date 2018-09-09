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
const int maxn = 1e3+10;
struct Point
{
    ll x, y;
    Point(){}
    Point(ll x, ll y):x(x), y(y){}
    bool operator < (const Point &rhs)const
    {
        return x < rhs.x;
    }
}pnt[maxn][2];
typedef Point Vector;
Vector operator + (Vector A, Vector B){return Vector(A.x+B.x, A.y+B.y);}
Vector operator - (Vector A, Vector B){return Vector(A.x-B.x, A.y-B.y);}
ll Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
ll Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y;}
set<Point> st;

bool OnSegment(Point p, Point a1, Point a2)
{
    return Cross(a1-p, a2-p) == 0 && Dot(a1-p, a2-p) <= 0;
}

bool Intersection(Point a1, Point a2, Point b1, Point b2)
{
    ll c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1),
       c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return c1*c2 < 0 && c3*c4 < 0;
}

bool check(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P-Q;
    ll t1 = Cross(w, u), t2 = Cross(v, w);
    if(v.x*t1%t2 == 0 && v.y*t1%t2 == 0){
        Point tmp = P+Point(v.x*t1/t2, v.y*t1/t2);
        if(!st.count(tmp)){
            st.insert(tmp);
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n; sc(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++)scanf("%lld%lld", &pnt[i][j].x, &pnt[i][j].y);
        ans += gcd(ABS(pnt[i][0].x-pnt[i][1].x), ABS(pnt[i][0].y-pnt[i][1].y))+1;
    }
    for(int i = 0; i < n; i++){
        st.clear();
        for(int j = i+1; j < n; j++){
            bool flg = 0;
            for(int k = 0; k < 2; k++){
                if(OnSegment(pnt[i][k], pnt[j][0], pnt[j][1])){
                    if(!st.count(pnt[i][k]))st.insert(pnt[i][k]), ans--;
                    flg = 1;
                    break;
                }
            }
            for(int k = 0; k < 2; k++){
                if(OnSegment(pnt[j][k], pnt[i][0], pnt[i][1])){
                    if(!st.count(pnt[j][k]))st.insert(pnt[j][k]), ans--;
                    flg = 1;
                    break;
                }
            }
            if(flg)continue;
            else if(Intersection(pnt[i][0], pnt[i][1], pnt[j][0], pnt[j][1])){
                ans -= check(pnt[i][0], pnt[i][1]-pnt[i][0], pnt[j][0], pnt[j][1]-pnt[j][0]);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}

