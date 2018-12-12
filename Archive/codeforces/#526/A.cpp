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
const int maxn = 3e5+10;
vector<pii> G[maxn];
int gas[maxn], fa[maxn];
ll dp[maxn];
int n;

void dfs(int u, int f)
{
    fa[u] = f;
    for(auto v : G[u]){
        if(v.fi == f)continue;
        dfs(v.fi, u);
        if(dp[v.fi]+gas[u]-v.se > dp[u]){
            dp[u] = dp[v.fi]+gas[u]-v.se;
        }
    }
}

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++)sc(gas[i]), dp[i] = gas[i];
    for(int i = 1; i < n; i++){
        int u, v, w;
        sc(u); sc(v); sc(w);
        G[u].pb(mk(v, w)); G[v].pb(mk(u, w));
    }
    dfs(1, 0);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        //printf("dp[%d]=%lld\n", i, dp[i]);
        ll ans1 = 0, ans2 = 0;
        for(auto v : G[i]){
            if(v.fi == fa[i])continue;
            if(dp[v.fi]-v.se > ans1){
                ans2 = ans1;
                ans1 = dp[v.fi]-v.se;
            }
            else if(dp[v.fi]-v.se > ans2){
                ans2 = dp[v.fi]-v.se;
            }
        }
        ans = max(ans, ans1+ans2+gas[i]);
        //printf("ans1=%lld, ans2=%lld, ans2=%lld\n", ans1, ans2, ans);
    }
    printf("%lld\n", ans);
    return 0;
}

