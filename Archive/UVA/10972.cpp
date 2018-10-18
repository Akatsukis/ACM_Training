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
int dfn[maxn], low[maxn], scc[maxn], bcc[maxn], deg[maxn];
vector<int> G[maxn];
set<pii> st;
int n, m, idx, cnt;

void init()
{
    for(int i = 1; i <= n; i++){
        dfn[i] = low[i] = scc[i] = bcc[i] = deg[i] = 0;
        G[i].clear();
    }
    st.clear();
    idx = cnt = 0;
}

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    for(auto v : G[u]){
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u])st.insert(mk(u, v));
        }
        else if(dfn[v] < dfn[u])low[u] = min(low[u], dfn[v]);
    }
}

void dfs2(int u)
{
    bcc[u] = cnt;
    for(auto v : G[u]){
        if(!st.count(mk(u, v)) && !st.count(mk(v, u)) && !bcc[v])dfs2(v);
    }
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
    for(int i = 1; i <= n; i++){
        if(!bcc[i]){
            cnt++;
            dfs2(i);
        }       
    }
    //for(int i = 1; i <= n; i++)printf("bcc[%d]=%d\n", i, bcc[i]);
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v); G[v].pb(u);
        }
        tarjan();
        for(auto p : st){
            if(bcc[p.fi] != bcc[p.se])deg[bcc[p.fi]]++, deg[bcc[p.se]]++;
        }
        int p = 0, q = 0;
        for(int i = 1; i <= cnt; i++){
            if(deg[i] == 0)p++;
            if(deg[i] == 1)q++;
        }
        printf("%d\n", cnt==1?0:p+(q+1)/2);
    }
    return 0;
}

