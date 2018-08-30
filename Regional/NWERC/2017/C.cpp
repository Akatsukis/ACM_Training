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
const int maxn = 20;
struct Point
{
    int x, y;
    Point(){}
    Point(int x, int y):x(x), y(y){}
    void output(){printf("(%d,%d)\n", x, y);}
}p[4];
typedef Point Vector;
int mp[maxn][maxn];
int px[maxn], py[maxn];
Vector operator - (Vector A, Vector B){return Vector(A.x-B.x, A.y-B.y);}
int Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
int Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y;}
bool OnSegment(Point p, Point a1, Point a2)
{
    return Cross(a1-p, a2-p) == 0 && Dot(a1-p, a2-p) < 0;
}

bool SegmentIntersection(Point a1, Point a2, Point b1, Point b2)
{
    if(OnSegment(a1, b1, b2) || OnSegment(a2, b1, b2))return 1;
    int c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1),
        c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return c1*c2 < 0 && c3*c4 < 0;
}

int main()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            int x; sc(x);
            mp[i][j] = x;
            px[x] = i, py[x] = j;
        }
    }
    int ans = 0;
    for(int i = 1; i <= 16;){
        printf("i=%d\n", i);
        ans++;
        if(i == 16)break;
        int dx = px[i+1]-px[i], dy = py[i+1]-py[i];
        printf("dx=%d, dy=%d\n", dx, dy);
        if(i != 1){
            p[2] = Point(px[i], py[i]), p[3] = Point(px[i]-dx*10, py[i]-dy*10);
            p[2].output(), p[3].output();
            if(!SegmentIntersection(p[0], p[1], p[2], p[3]))ans++;
        }
        int j = 1;
        while(i+j <= 16 && px[i+j]-px[i+j-1] == dx && py[i+j]-py[i+j-1] == dy)j++;
        p[0] = Point(px[i+j-1], py[i+j-1]), p[1] = Point(px[i+j-1]+dx*10, py[i+j-1]+dy*10);
        p[0].output(), p[1].output();
        i += j;
    }
    printf("%d\n", ans);
    return 0;
}


