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
const int maxn = 1e2+10;
char s[maxn];
int dp[maxn][maxn], mx[maxn][maxn];

int main()
{
    scanf("%s", s+1);
    int n = strlen(s+1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 26; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(s[i] == j-1+'a')dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    }
    printf("%d\n", 26-dp[n][26]);
    return 0;
}


