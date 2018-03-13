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
int mp[maxn][maxn], mat[maxn], rmat[maxn];
bool used[maxn];
int dfn[maxn], low[maxn], scc[maxn];
vector<int> G[maxn];
stack<int> S;
int idx, cnt;
int vn, vm;

void init()
{
    memset(mp, 0, sizeof(mp));
    memset(mat, 0, sizeof(mat));
    memset(rmat, 0, sizeof(rmat));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(scc, 0, sizeof(scc));
    for(int i = 0; i < maxn; i++)G[i].clear();
    idx = cnt = 0;
}

bool dfs(int u)
{
    for(int i = 1; i <= vm; i++){
        if(mp[u][i] && !used[i]){
            used[i] = 1;
            if(!mat[i] || dfs(mat[i])){
                mat[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungary()
{
    int ret = 0;
    for(int i = 1; i <= vn; i++){
        memset(used, 0, sizeof(used));
        if(dfs(i))ret++;
    }
    return ret;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++idx;
    S.push(u);
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v])low[u] = min(low[u], dfn[v]);
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

void solve()
{
    for(int i = 1; i <= vm; i++){
        if(!dfn[i])tarjan(i);
    }
}

int main()
{
    int T, kase = 1;
    int n, m;
    sc(T);
    while(T--){
        printf("Case #%d:\n", kase++);
        sc(n); sc(m);
        vn = n, vm = m;
        init();
        for(int i = 1; i <= n; i++){
            int k, v;
            sc(k);
            for(int j = 0; j < k; j++){
                sc(v);
                mp[i][v] = 1;
            }
        }
        int ret = hungary();
        vn = vm = n+m-ret;
        for(int i = n+1; i <= vn; i++){
            for(int j = 1; j <= vm; j++){
                mp[i][j] = 1;
            }
        }
        for(int i = 1; i <= vn; i++){
            for(int j = m+1; j <= vm; j++){
                mp[i][j] = 1;
            }
        }
        memset(mat, 0, sizeof(mat));
        hungary();
        for(int i = 1; i <= vm; i++){
            if(mat[i])rmat[mat[i]] = i;
        }
        for(int i = 1; i <= vn; i++){
            for(int j = 1; j <= vm; j++){
                if(mp[i][j] && j != rmat[i])G[rmat[i]].pb(j);
            }
        }
        solve();
        for(int i = 1; i <= n; i++){
            vector<int> ans;
            for(int j = 1; j <= m; j++){
                if(scc[rmat[i]] == scc[j] && mp[i][j])ans.pb(j);
            }
            int sz = ans.size();
            printf("%d", sz);
            for(int j = 0; j < sz; j++){
                printf(" %d", ans[j]);
            }
            puts("");
        }
    }
    return 0;
}

