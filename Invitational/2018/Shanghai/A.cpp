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
const int maxn = 1e4+10;
struct Point
{
    ll x, y;
    Point(){}
    Point(ll x, ll y):x(x), y(y){}
}p[maxn];
typedef Point Vector;
Vector operator - (Vector a, Vector b){return Vector(a.x-b.x, a.y-b.y);}
int n, x;

ll Cross(Point a, Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool ok(int u, int v, int w)
{
    return Cross(p[u]-p[v], p[v]-p[w]) == 0;
}

int check(int u, int v)
{
    int ret = 2;
    for(int i = 0; i < n; i++){
        if(i == u || i == v)continue;
        if(ok(i, u, v))ret++;
    }
    return ret;
}

int main()
{
    srand(unsigned(time(NULL)));
    int T;
    sc(T);
    while(T--){
        scanf("%d 0.%d", &n, &x);
        for(int i = 0; i < n; i++)scanf("%lld%lld", &p[i].x, &p[i].y);
        if(n == 1){
            puts("Yes");
            continue;
        }
        bool flg = 0;
        for(int i = 0; i < 500; i++){
            int u = rand()%n, v = rand()%n;
            while(u == v)v = rand()%n;
            if(check(u, v)*10 >= x*n){
                flg = 1;
                break;
            }
        }
        if(flg)puts("Yes");
        else puts("No");
    }
    return 0;
}


