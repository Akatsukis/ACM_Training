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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
int n;
double x[maxn];
double y[maxn];

double sqr(double t)
{
    return t*t;
}

double dis(int u, int v)
{
    return sqrt(sqr(x[u]-x[v])+sqr(y[u]-y[v]));
}

int main()
{
    sc(n);
    double tot = 0;
    for(int i = 0; i < n; i++){
        scanf("%lf%lf", &x[i], &y[i]);
        if(i)tot += dis(i, i-1);
    }
    tot /= 2;
    for(int i = 0; i < n-1; i++){
        double cnt = dis(i, i+1);
        if(cnt >= tot){
            double ansx = x[i] + tot/cnt*(x[i+1]-x[i]);
            double ansy = y[i] + tot/cnt*(y[i+1]-y[i]);
            printf("%.1f %.1f\n", ansx, ansy);
            return 0;
        }
        else tot -= cnt;
    }
    return 0;
}

