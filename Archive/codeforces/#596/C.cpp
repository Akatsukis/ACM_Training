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
constexpr int maxn = 2e3+10;
constexpr int mod = 1e9+7;
char s[maxn][maxn];
int rm[maxn][maxn], cm[maxn][maxn];
int row[maxn][maxn], col[maxn][maxn];
long long dp[maxn][maxn][2];
long long rs[maxn][maxn], cs[maxn][maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", s[i]+1);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = m-1; j >= 1; j--) {
            rm[i][j] = rm[i][j+1]+(s[i][j+1]!='R');
        }
        int r = 0;
        for(int j = 1; j <= m; j++) {
            int nr = j+rm[i][j];
            if(nr > r) {
                for(int k = r+1; k <= nr; k++) {
                    row[i][k] = j;
                }
                r = nr;
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int j = n-1; j >= 1; j--) {
            cm[j][i] = cm[j+1][i]+(s[j+1][i]!='R');
        }
        int r = 0;
        for(int j = 1; j <= n; j++) {
            int nr = j+cm[j][i];
            if(nr > r) {
                for(int k = r+1; k <= nr; k++) {
                    col[k][i] = j;
                }
                r = nr;
            }
        }
    }
    dp[1][1][0] = dp[1][1][1] = 1;
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= m; y++) {
            dp[x][y][0] += (rs[x][y-1]-rs[x][row[x][y]-1]);
            dp[x][y][0] = (dp[x][y][0]%mod+mod)%mod;
            dp[x][y][1] += (cs[x-1][y]-cs[col[x][y]-1][y]);
            dp[x][y][1] = (dp[x][y][1]%mod+mod)%mod;
            rs[x][y] = (rs[x][y-1]+dp[x][y][1])%mod;
            cs[x][y] = (cs[x-1][y]+dp[x][y][0])%mod;
        }
    }
    int ans = (dp[n][m][0]+dp[n][m][1])%mod;
    if(n == 1 && m == 1)ans--;
    printf("%d\n", ans);
    return 0;
}

