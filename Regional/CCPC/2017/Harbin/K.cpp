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
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 4e5+10;
struct atom
{
    int s, t, a, b;
    bool operator < (const atom &rhs)const
    {
        if(s != rhs.s)return s < rhs.s;
        else return t < rhs.t;
    }
}tb[maxn];
bool tag[maxn];
double bit[maxn];
int n, t;

void update(int x, double v)
{
    while(x){
        bit[x] = min(bit[x], v);
        x -= x&-x;
    }
}

double query(int x)
{
    if(!x)return 0;
    double ret = 1e9;
    while(x <= t){
        ret = min(ret, bit[x]);
        x += x&-x;
    }
    return ret;
}

bool judge(double m)
{
    double sum = 0;
    int r = 0;
    for(int i = 1; i <= t; i++)bit[i] = 1e9;
    for(int i = 1; i <= n; i++){
        if(m*tb[i].b-tb[i].a >= 0){
            tag[i] = 1;
            sum += m*tb[i].b-tb[i].a;
            if(tb[i].s-1 <= r)r = max(r, tb[i].t);
        }
        else tag[i] = 0;
    }
    update(r,  0);
    for(int i = 1; i <= n; i++){
        if(tag[i]){
            double val = query(tb[i].s-1);
            update(tb[i].t, val);
        }
        else{
            double val = query(tb[i].s-1)-(m*tb[i].b-tb[i].a);
            update(tb[i].t, val);
        }
    }
    //printf("m=%f, sum=%f, query(t)=%f\n", m, sum, query(t));
    return sum >= query(t);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n); sc(t);
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d%d", &tb[i].s, &tb[i].t, &tb[i].a, &tb[i].b);
        }
        sort(tb+1, tb+1+n);
        double l = 0, r = 1e3, ans = 0;
        while(l+eps <= r){
            double m = (l+r)/2;
            if(judge(m)){
                ans = m;
                r = m-eps;
            }
            else l = m+eps;
        }
        printf("%.3f\n", ans);
    }
    return 0;
}

