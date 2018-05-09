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
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
ll cx[maxn], cy[maxn];
ll cx2[maxn], cy2[maxn];
int n, m;

typedef complex<double> point;
typedef pair<point, point> hpl;
const double eps = 1e-10;
inline int sgn(double x){return fabs(x)<eps?0:(x<0?-1:1);}
inline double cross(point a, point b){return (conj(a)*b).imag();}
inline double dot(point a, point b){return (conj(a)*b).real();}
inline bool satisfy(point a, hpl p){
    return sgn(cross(a-p.fi, p.se-p.fi)) <= 0;
}

point crosspoint(const hpl &a, const hpl &b)
{
    double k = cross(b.fi-b.se, a.fi-b.se);
    k = k/(k-cross(b.fi-b.se, a.se-b.se));
    return a.fi+(a.se-a.fi)*k;
}

bool cmp(const hpl &a, const hpl &b)
{
    int res = sgn(arg(a.se-a.fi)-arg(b.se-b.fi));
    return res == 0 ? satisfy(a.fi, b) : res < 0;
}

vector<point> hplintersection(vector<hpl> v)
{
    sort(ALL(v), cmp);
    deque<hpl> q;
    deque<point> ans;
    q.pb(v[0]);
    for(int i = 1; i < (int)v.size(); i++){
        if(sgn(arg(v[i].se-v[i].fi)-arg(v[i-1].se-v[i-1].fi))==0){
            continue;
        }
        while(ans.size() && !satisfy(ans.back(), v[i])){
            ans.pop_back();
            q.pop_back();
        }
        while(ans.size() && !satisfy(ans.front(), v[i])){
            ans.pop_front();
            q.pop_front();
        }
        ans.pb(crosspoint(q.back(), v[i]));
        q.pb(v[i]);
    }
    while(ans.size() && !satisfy(ans.back(), q.front())){
        ans.pop_back();
        q.pop_back();
    }
    while(ans.size() && !satisfy(ans.front(), q.back())){
        ans.pop_front();
        q.pop_front();
    }
    ans.pb(crosspoint(q.back(), q.front()));
    for(auto u : ans)printf("(%f,%f)\n", u.real(), u.imag());
    return vector<point>(ans.begin(), ans.end());
}

int solve(int u)
{
    vector<hpl> vec;
    for(int i = 0; i < n; i++){
        if(i == u)continue;
        int A = -2*(cx[u]-cx[i]), B = -2*(cy[u]-cy[i]), C = cx2[u]+cy2[u]-cx2[i]-cy2[i];
        printf("A=%d, B=%d, C=%d\n", A, B, C);
        if(A == 0){
            point p1(0, -1.0*C/B), p2(1, -1.0*C/B);
            if(B < 0)vec.pb(mk(p1, p2));
            else vec.pb(mk(p2, p1));
        }
        else if(B == 0){
            point p1(-1.0*C/A, 0), p2(-1.0*C/A, 1); 
            if(A > 0)vec.pb(mk(p1, p2));
            else vec.pb(mk(p2, p1));
        }
        else if(C == 0){
            point p1(0, 0), p2(1, -1.0*A/B);
            if(A*B > 0)vec.pb(mk(p2, p1));
            else vec.pb(mk(p1, p2));
        }
        else{
            point p1(0, -1.0*C/B), p2(-1.0*C/A, 0);
            if(A*B*C > 0)vec.pb(mk(p1, p2));
            else vec.pb(mk(p2, p1));
        }
    }
    vec.pb(mk(point(0, 1), point(0, 0)));
    vec.pb(mk(point(4095, 0), point(4095, 1)));
    vec.pb(mk(point(0, 0), point(1, 0)));
    vec.pb(mk(point(1, 4095), point(0, 4095)));
    //for(auto u : vec){
        //printf("(%f,%f)->(%f,%f)\n", u.fi.real(), u.fi.imag(), u.se.real(), u.se.imag());
    //}
    vector<point> ret = hplintersection(vec);
    //for(auto u : ret)printf("%f %f\n", u.real(), u.imag());
    double ans = 0;
    for(int i = 2; i < (int)ret.size(); i++){
        ans += cross(ret[i]-ret[0], ret[i-1]-ret[0]);
    }
    return floor(fabs(ans/2)+0.5);
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(cx, 0, sizeof(cx));
        memset(cx2, 0, sizeof(cx2));
        memset(cy, 0, sizeof(cy));
        memset(cy2, 0, sizeof(cy2));
        sc(n); sc(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ll x, y;
                scanf("%lld%lld", &x, &y);
                cx[i] += x, cy[i] += y;
                cx2[i] += sqr(x), cy2[i] += sqr(y);
            }
        }
        printf("Case #%d: ", kase++);
        for(int i = 0; i < n; i++){
            printf("%d%c", solve(i), " \n"[i==n-1]);
        }
    }
    return 0;
}

