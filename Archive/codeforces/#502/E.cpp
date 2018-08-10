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
    Point(){}
    Point(ll x, ll y):x(x), y(y){}
    bool operator < (const Point &rhs)
    {
        if(x != rhs.x)return x < rhs.x;
        return y < rhs.y;
    }
}p[maxn], q[maxn], ret[2][maxn];
typedef Point Vector;
Vector operator - (Vector A, Vector B){return Vector(A.x-B.x, A.y-B.y);}
ll Cross(Vector A, Vector B){return A.x*B.y-A.y*B.x;}
ll Dot(Vector A, Vector B){return A.x*B.x+A.y*B.y;};
ll Length(Vector A){return Dot(A, A);}

int ConvexHull(Point *in, int n, Point *ch)
{
    sort(in, in+n);
    int m = 0;
    for(int i = 0; i < n; i++){
        while(m > 1 && Cross(ch[m-1]-ch[m-2], in[i]-ch[m-2]) <= 0)m--;
        ch[m++] = in[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--){
        while(m > k && Cross(ch[m-1]-ch[m-2], in[i]-ch[m-2]) <= 0)m--;
        ch[m++] = in[i];
    }
    if(n > 1)m--;
    return m;
}

int smallestRepresentation(vector<ll> &s)
{
    int n = s.size();
    int i = 0, j = 1, k = 0;
    while(i < n && j < n && k < n){
        if(s[(i+k)%n] == s[(j+k)%n])k++;
        else{
            if(s[(i+k)%n] > s[(j+k)%n])i += k+1;
            else j += k+1;
            if(i == j)j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 0; i < n; i++)scanf("%lld%lld", &p[i].x, &p[i].y);
    for(int i = 0; i < m; i++)scanf("%lld%lld", &q[i].x, &q[i].y);
    int k1 = ConvexHull(p, n, ret[0]);
    int k2 = ConvexHull(q, m, ret[1]);
    if(k1 != k2)puts("NO");
    else{
        vector<ll> v[2];
        for(int i = 0; i < k1; i++){
            v[0].pb(Dot(ret[0][i]-ret[0][(i+1)%k1], ret[0][(i+2)%k1]-ret[0][(i+1)%k1]));
            v[0].pb(Length(ret[0][i]-ret[0][(i+1)%k1]));
        }
        for(int i = 0; i < k2; i++){
            v[1].pb(Dot(ret[1][i]-ret[1][(i+1)%k1], ret[1][(i+2)%k1]-ret[1][(i+1)%k1]));
            v[1].pb(Length(ret[1][i]-ret[1][(i+1)%k2]));
        }
        int c1 = smallestRepresentation(v[0]);
        int c2 = smallestRepresentation(v[1]);
        bool flg = 1;
        for(int i = 0; i < 2*k1; i++){
            if(v[0][(i+c1)%(2*k1)] != v[1][(i+c2)%(2*k1)]){
                flg = 0;
                break;
            }
        }
        if(flg)puts("YES");
        else puts("NO");
    }
    return 0;
}


