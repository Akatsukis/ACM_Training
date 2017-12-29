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
const int maxn = 2e5+10;
vector<vector<int> > G(maxn);
queue<int> q;
int dp[maxn];
int pre[maxn];
bool vis[maxn];
vector<pii> vp;
int n, from, to;
ll ans;

void dfs(int u, int f)
{
    dp[u] = dp[f] + 1;
    pre[u] = f;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v != f)dfs(v, u);
    }
}

void solve(int u, int f, int d)
{
    if(vis[u])d++;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v != f)solve(v, u, d);
    }
    if(!vis[u]){
        if(dp[u]-1 > dp[u]+dp[to]-2*d){
            ans += dp[u]-1;
            vp.pb(mk(from, u));
        }
        else{
            ans += dp[u]+dp[to]-2*d;
            vp.pb(mk(to, u));
        }
    }
}

int main()
{
    sc(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc(u);sc(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) if(dp[i] > dp[from]) from = i;
    memset(dp, 0, sizeof(dp));
    dfs(from, 0);
    for(int i = 1; i <= n; i++) if(dp[i] > dp[to]) to = i;
    for(int u = to; u; u = pre[u])vis[u] = 1;
    solve(from, 0, 0);
    for(int u = to; u != from; u = pre[u]){
        ans += dp[u]-1;
        //printf("dp[%d]:%d\n", to, dp[to]);
        vp.pb(mk(from, u));
    }
    printf("%lld\n", ans);
    for(int i = 0; i < (int)vp.size(); i++){
        printf("%d %d %d\n", vp[i].fi, vp[i].se, vp[i].se);
    }
    return 0;
}

