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
const long long INF = 0xafafafafafafafaf;
const int maxn = 1e5+10;
vector<int> G[maxn];
long long dp[maxn][3];
int a[maxn];

void dfs(int u, int f) {
    for(auto v: G[u]) {
        if(v == f)continue;
        dfs(v, u);
    }

    dp[u][0] = a[u];
    for(auto v: G[u]) {
        if(v == f)continue;
        dp[u][0] += max(max(dp[v][0], dp[v][1]), dp[v][2]+a[v]);
    }

    dp[u][1] = a[u];
    bool flg = 0;
    long long mn = LONG_LONG_MAX;
    for(auto v: G[u]) {
        if(v == f)continue;
        if(dp[v][0] >= max(dp[v][1], dp[v][2]))flg = 1;
        else {
            mn = min(mn, max(dp[v][1], dp[v][2])-dp[v][0]);
        }
        dp[u][1] += max(dp[v][0], max(dp[v][1], dp[v][2]));
    }
    if(!flg) {
        if(mn == LONG_LONG_MAX)dp[u][1] = INF;
        else dp[u][1] -= mn;
    }

    dp[u][2] = 0;
    for(auto v: G[u]) {
        if(v == f)continue;
        dp[u][2] += max(dp[v][1], dp[v][2]);
    }
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        memset(dp, 0xaf, sizeof(dp));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            G[i].clear();
        }
        for(int i = 0; i < n-1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v); G[v].pb(u);
        }
        dfs(1, 0);
        long long ans = max(dp[1][0], max(dp[1][1], dp[1][2]));
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

