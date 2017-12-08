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
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 998244353;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e3+10;
int a[maxn];
int b[maxn];
int dp[maxn][2];
int sum[maxn][2];
int n, m;

int main()
{
    int T;
    sc(T);
    while(T--){
        memset(dp, 0, sizeof(dp));
        memset(sum, 0, sizeof(sum));
        sc(n);sc(m);
        for(int i = 1; i <= n; i++){
            sc(a[i]);
        }
        for(int i = 1; i <= m; i++){
            sc(b[i]);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            int num1 = 1, num0 = 0;
            for(int j = 1; j <= m; j++){
                dp[j][0] = dp[j][1] = 0;
                if(a[i] == b[j]){
                    dp[j][0] = num1;
                    dp[j][1] = num0;
                    ans = ((num0+num1)%mod+ans)%mod;
                }
                else if(a[i] < b[j])num1 = (num1+sum[j][1])%mod;
                else if(a[i] > b[j])num0 = (num0+sum[j][0])%mod;
            }
            for(int j = 1; j <= m; j++){
                sum[j][0] = (sum[j][0]+dp[j][0])%mod;
                sum[j][1] = (sum[j][1]+dp[j][1])%mod;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

