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
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 20;
double a[maxn], b[maxn], c[maxn], solve[maxn];
bool vis[maxn];
double ans;

void wp(int k, int n)
{
    if(n == 0){
//        for(int i = 1; i <= 12; i++){
//            printf("vis[%d]:%d\n", i, vis[i]);
//        }
        double res = 1;
        for(int i = 1; i <= 12; i++){
            if(vis[i])res *= solve[i];
            else res *= 1-solve[i];
            //printf("%f\n", res);
        }
        ans += res;
    }
    else{
        for(int i = k; i <= 12; i++){
            if(!vis[i]){
                vis[i] = 1;
                wp(i+1, n-1);
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= 12; i++){
        scanf("%lf", &a[i]);
    }
    for(int i = 1; i <= 12; i++){
        scanf("%lf", &b[i]);
    }
    for(int i = 1; i <= 12; i++){
        scanf("%lf", &c[i]);
    }
    for(int i = 1; i <= 12; i++){
        solve[i] = a[i]+(1-a[i])*b[i]+(1-a[i])*(1-b[i])*c[i];
        //printf("solve[%d]:%f\n", i, solve[i]);
    }
    for(int i = 0; i <= 12; i++){
        ans = 0;
        wp(1, i);
        printf("%.6f\n", ans);
    }
    return 0;
}

