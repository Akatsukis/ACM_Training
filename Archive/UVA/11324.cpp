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
vector<int> G[maxn], G2[maxn];
stack<int> sk;
int low[maxn], dfn[maxn], scc[maxn];
int dp[maxn], deg[maxn], num[maxn];
int n, m, idx, cnt;

void init()
{
    for(int i = 1; i <= n; i++){
        G[i].clear(), G2[i].clear();
        low[i] = dfn[i] = scc[i] = dp[i] = deg[i] = num[i] = 0;
    }
    idx = cnt = 0;
}

void dfs(int u)
{
    dfn[u] = low[u] = ++idx;
    sk.push(u);
    for(auto v : G[u]){
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v])low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        cnt++;
        while(1){
            int x = sk.top(); sk.pop();
            scc[x] = cnt, num[cnt]++;
            if(x == u)break;
        }
    }
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i);
    }
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n); sc(m);
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
        }
        tarjan();
        for(int i = 1; i <= n; i++){
            for(auto v : G[i]){
                if(scc[i] != scc[v])deg[scc[v]]++, G2[scc[i]].pb(scc[v]);
            }
        }
        queue<int> q;
        int ans = 0;
        for(int i = 1; i <= cnt; i++){
            dp[i] = num[i];
            ans = max(ans, dp[i]);
            if(!deg[i])q.push(i);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto v : G2[u]){
                dp[v] = max(dp[v], num[v]+dp[u]);
                ans = max(ans, dp[v]);
                deg[v]--;
                if(!deg[v])q.push(v);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

