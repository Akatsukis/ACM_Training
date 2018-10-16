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
bool hate[maxn][maxn];
vector<int> G[maxn], bcc[maxn];
int dfn[maxn], low[maxn], rev[maxn], col[maxn], odd[maxn];
stack<pii> sk;
int n, m, idx, cnt;

void init()
{
    memset(hate, 0, sizeof(hate));
    for(int i = 1; i <= n; i++){
        dfn[i] = low[i] = rev[i] = odd[i] = 0;
        G[i].clear(), bcc[i].clear();
    }
    idx = cnt = 0;
}

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    for(auto v : G[u]){
        if(!dfn[v]){
            sk.push(mk(u, v));
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){
                cnt++;
                while(1){
                    pii p = sk.top(); sk.pop();
                    if(rev[p.fi] != cnt){
                        bcc[cnt].pb(p.fi);
                        rev[p.fi] = cnt;
                    }
                    if(rev[p.se] != cnt){
                        bcc[cnt].pb(p.se);
                        rev[p.se] = cnt;
                    }
                    if(p.fi == u && p.se == v)break;
                }
            }
        }
        else if(dfn[v] < dfn[u] && v != f){
            sk.push(mk(u, v));
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}

bool get_col(int u, int t)
{
    for(auto v : G[u]){
        if(rev[v] != t)continue;
        if(col[v] == col[u])return 0;
        if(!col[v]){
            col[v] = 3-col[u];
            if(!get_col(v, t))return 0;
        }
    }
    return 1;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && n){
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            hate[u][v] = hate[v][u] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)continue;
                if(!hate[i][j])G[i].pb(j);
            }
        }
        tarjan();
        for(int i = 1; i <= cnt; i++){
            memset(col, 0, sizeof(col));
            for(auto u : bcc[i])rev[u] = i;
            int u = bcc[i][0];
            col[u] = 1;
            if(!get_col(u, i)){
                for(auto u : bcc[i])odd[u] = 1;
            }
        }
        int ans = n;
        for(int i = 1; i <= n; i++)if(odd[i])ans--;
        printf("%d\n", ans);
    }
    return 0;
}

