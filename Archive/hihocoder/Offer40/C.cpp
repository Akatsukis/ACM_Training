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
const int maxn = 1010;
int a[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    int n, m;
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        char s[maxn];
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] == '0')a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    for(int i = 0; i < m; i++)dp[0][i] = 1;
    for(int i = 0; i < n; i++)dp[i][0] = 1;
    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(a[i][j] != a[i-1][j] && a[i][j] != a[i][j-1]){
                int step = min(dp[i-1][j], dp[i][j-1]);
                if(a[i-step][j-step] == a[i][j])dp[i][j] = step+1;
                else dp[i][j] = step;
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

