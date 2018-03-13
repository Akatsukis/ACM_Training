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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
int dfn[maxn], low[maxn], scc[maxn];
stack<int> S;
vector<pii> G[maxn];
int idx, cnt;
int n, m;

void init()
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(scc, 0, sizeof(scc));
    for(int i = 0; i <= n; i++)G[i].clear();
    idx = cnt = 0;
}

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    S.push(u);
    bool flag = 1;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i].fi;
        if(v == f && flag){
            flag = 0;
            continue;
        }
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        if(!scc[v])low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]){
        cnt++;
        while(1){
            int x = S.top(); S.pop();
            scc[x] = cnt;
            if(x == u)break;
        }
    }
}

void tarjan()
{
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            printf("0\n");
            return;
        }
    }
    int ans = INF;
    for(int i = 1; i <= n; i++){
        int u = scc[i];
        for(int j = 0; j < (int)G[i].size(); j++){
            int v = scc[G[i][j].fi];
            if(u != v)ans = min(ans, G[i][j].se);
        }
    }
    if(ans == INF)printf("-1\n");
    else printf("%d\n", ans);
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && (n||m)){
        init();
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            if(!w)w++;
            G[u].pb(mk(v, w));
            G[v].pb(mk(u, w));
        }
        tarjan();
    }
    return 0;
}

