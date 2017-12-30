#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1000+10;
int x[maxn];
double ans[maxn];
int n, r;
//
//double dis(int a, double xx, double yy)
//{
//    double res = (p[a].fi-xx)*(p[a].fi-xx)+(p[a].se-yy)*(p[a].se-yy);
//    return sqrt(res);
//}
//
//bool check(double m, int id)
//{
//    for(int i = 0; i < id; i++){
//        if(dis(i, x[id], m) < 2*r+eps)return 0;
//    }
//    return 1;
//}

int main()
{
    sc(n);sc(r);
    for(int i = 0; i < n; i++){
        sc(x[i]);
    }
    for(int i = 0; i < n; i++){
        ans[i] = r;
        for(int j = 0; j < i; j++){
            if(x[i]-x[j]<=2*r){
                double tmp = ans[j]+sqrt((2*r)*(2*r)-(x[i]-x[j])*(x[i]-x[j]));
                ans[i] = max(ans[i], tmp);
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%.10f%c", ans[i], " \n"[i==n-1]);
    }
    return 0;
}

