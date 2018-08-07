#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 5e3+10;
int a[maxn];
int dp[maxn][maxn][3];

int dis(int u, int v)
{
    if(a[u] > a[v])return 0;
    else return a[v]-a[u]+1;
}

int main()
{
    memset(dp, 0x3f, sizeof(dp));
    int n; sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]), dp[i][0][0] = 0;
    dp[1][0][0] = dp[1][1][2] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= (i+1)/2; j++){
            dp[i][j][0] = min(dp[i-1][j][0], dp[i-1][j][1]);
            dp[i][j][1] = dp[i-1][j][2]+dis(i-1, i);
            dp[i][j][2] = min(dp[i-1][j-1][0]+dis(i, i-1), dp[i-1][j-1][1]+max(0, min(a[i-1], a[i-2]-1)-a[i]+1));
        }
    }
    for(int i = 1; i <= (n+1)/2; i++){
        printf("%d%c", min(dp[n][i][0], min(dp[n][i][1], dp[n][i][2])), " \n"[i==(n+1)/2]);
    }
    return 0;
}


