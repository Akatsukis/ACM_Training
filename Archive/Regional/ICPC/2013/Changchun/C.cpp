#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fst fi
#define scd se
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100;
double dp[maxn][maxn * 1000];
int a[maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        int n;
        double p;
        scanf("%d%lf", &n, &p);
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sc(a[i]);
            sum += a[i];
        }
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1.0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j + a[i]] += 0.5 * dp[i - 1][j];
                //printf("dp[%d][%d] += dp[%d][%d] = %f\n", i, j + a[i], i - 1, j, dp[i - 1][j]);
                //printf("dp[%d][%d]=%f\n", i, j + a[i], dp[i][j + a[i]]);
                dp[i][j] += 0.5 * dp[i - 1][j];
            }
        }
        double now = 0;
//        for(int i = 0; i <= n; i++){
//            for(int j = 0; j <= sum; j++){
//                printf("dp[%d][%d]:%f\n", i, j, dp[i][j]);
//            }
//        }
        for(int i = 0; i <= sum; i++){
            now += dp[n][i];
            if(now >=  p){
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}


