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
const int maxn = 1e5+10;
const int maxm = 15;
int a[maxn], b[maxm];
int dp[maxn][maxm], tl[maxn][maxm], tr[maxn][maxm];
int n, m;

int solve(int x, int y)
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            tl[i][j] = tl[i-1][j];
            tr[i][j] = tr[i-1][j];
            if(a[i] == b[j]){
                dp[i][j]++;
                if(j == x && !tl[i][j])tl[i][j] = i;
                if(j == y)tr[i][j] = i;
            }
            if(dp[i][j-1] > dp[i][j]){
                dp[i][j] = dp[i][j-1];
                tl[i][j] = tl[i][j-1];
                tr[i][j] = tr[i][j-1];
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n);
        int fr = 9, to = 0;
        for(int i = 1; i <= n; i++){
            scanf("%1d", &a[i]);
            fr = min(fr, a[i]);
            to = max(to, a[i]);
        }
        m = 0;
        for(int i = 0; i <= 9; i++)b[++m] = i;
        int ans = solve(1, 1), x = 1, y = 1;
        for(int i = fr; i <= to; i++){
            for(int j = i; j <= to; j++){
                m = 0;
                for(int k = 0; k <= i; k++)b[++m] = k;
                for(int k = j; k >= i; k--)b[++m] = k;
                for(int k = j; k <= 9; k++)b[++m] = k;
                int now = solve(i+2, j+2);
                if(now > ans && tl[n][m] && tr[n][m])ans = now, x = tl[n][m], y = tr[n][m];
            }
        }
        printf("%d %d %d\n", ans, x, y);
    }
    return 0;
}


