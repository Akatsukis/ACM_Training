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
const int maxn = 1e3+10;
int a[maxn];
int dp[maxn][maxn][2];
int n;

bool solve(int l, int r, int f, int val)
{
    if(l == r)return 1;
    if(dp[l][r][f] != -1)return dp[l][r][f];
    for(int i = l; i < r; i++){
        if(gcd(a[i], val) == 1)continue;
        if(solve(l, i, 0, a[i]) && solve(i+1, r, 1, a[i]))return (dp[l][r][f] = 1);
    }
    return (dp[l][r][f] = 0);
}

int main()
{
    sc(n);
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++)sc(a[i]);
    for(int i = 0; i < n; i++){
        if(solve(0, i, 0, a[i]) && solve(i+1, n, 1, a[i])){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}


