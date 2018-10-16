#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
stack<int> S;
int dfn[maxn], low[maxn], scc[maxn], scc_cnt[maxn];
int in[maxn], dp[maxn];
vector<int> G[maxn];
vector<int> G2[maxn];
int idx, cnt;

void dfs(int u)
{
    dfn[u] = low[u] = ++idx;
    S.push(u);
    for(auto v : G[u]){
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v])low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        cnt++;
        while(1){
            int x = S.top(); S.pop();
            scc[x] = cnt;
            scc_cnt[cnt]++;
            if(x == u)break;
        }
    }
}

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i);
    }
    for(int i = 1; i <= n; i++){
        for(auto u : G[i]){
            if(scc[i] == scc[u])continue;
            G2[scc[i]].pb(scc[u]);
            in[scc[u]]++;
        }
    }
    queue<int> q;
    int ans = 0;
    for(int i = 1; i <= cnt; i++){
        if(!in[i])q.push(i), dp[i] = scc_cnt[i], ans = max(ans, dp[i]);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G2[u]){
            dp[v] = max(dp[v], dp[u]+scc_cnt[v]);
            ans = max(ans, dp[v]);
            in[v]--;
            if(!in[v])q.push(v);
        }
    }
    printf("%d\n", ans);
    return 0;
}

