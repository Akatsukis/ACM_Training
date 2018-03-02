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
const int maxn = 2000+10;
int dp[maxn][4];
int n;

int main()
{
    sc(n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int t;
        sc(t);
        if(t == 1){
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][2] = max(dp[i-1][2]+1, dp[i-1][1]+1);
            dp[i][3] = max(dp[i-1][2], dp[i-1][3]);
        }
        else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1]+1, dp[i-1][0]+1);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]);
            dp[i][3] = max(dp[i-1][3]+1, dp[i-1][2]+1);
        }
        int u = max(dp[i][0], dp[i][1]), v = max(dp[i][2], dp[i][3]);
        ans = max(ans, max(u, v));
        //printf("%d %d %d %d\n", dp[i][0], dp[i][1], dp[i][2], dp[i][3]);
    }
    printf("%d\n", ans);
    return 0;
}

