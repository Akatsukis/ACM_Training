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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int dp[maxn][12][2];
string s;
int n, m;

int main()
{
    cin >> n >> m >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i){
            for(int j = 0; j <= m; j++){
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
            }
        }
        if(s[i] == 'a'){
            for(int j = 0; j <= m; j++){
                dp[i][j][0]++;
                if(i&&j)dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][1]+1);
                ans = max(ans, dp[i][j][0]);
            }
        }
        else{
            for(int j = 1; j <= m; j++){
                if(dp[i][j][1])dp[i][j][1]++;
                if(i&&j&&dp[i-1][j-1][0])dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0]+1);
                ans = max(ans, dp[i][j][1]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

