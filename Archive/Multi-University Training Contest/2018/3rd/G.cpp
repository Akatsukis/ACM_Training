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
const int maxn = 2e5+10;
struct Point
{
    ll x, y;
    int id;
    Point(){}
    Point(ll x, ll y, int id):x(x), y(y), id(id){}
    bool operator < (const Point &rhs){
        if(x != rhs.x)return x < rhs.x;
        else if(y != rhs.y)return y < rhs.y;
        else return id < rhs.id;
    }
    Point operator -(const Point &rhs){return Point(x-rhs.x, y-rhs.y, 0);}
}pnt[maxn], q[maxn];
typedef Point Vector;
ll Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
set<pair<ll, ll> > st;

int ConvexHull(Point *p, int n, Point *ch)
{
    sort(p, p+n);
    int m = 0;
    for(int i = 0; i < n; i++){
        if(m <= 1)ch[m++] = p[i];
        else{
            while(m > 1){
                ll ret = Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]);
                if((ret == 0 && p[i].id > ch[m-1].id) || ret < 0)break;
                m--;
            }
            ch[m++] = p[i];
        }
    }
    return m;
}

int main()
{
    int T; sc(T);
    while(T--){
        st.clear();
        int n; sc(n);
        int tot = 0;
        for(int i = 0; i < n; i++){
            Point in;
            scanf("%lld%lld", &in.x, &in.y);
            in.id = i+1;
            if(!st.count(mk(in.x, in.y))){
                pnt[tot++] = in;
                st.insert(mk(in.x, in.y));
            }
        }
        int ans = ConvexHull(pnt, tot, q);
        for(int i = 0; i < ans; i++)printf("%d%c", q[i].id, " \n"[i==ans-1]);
    }
    return 0;
}


