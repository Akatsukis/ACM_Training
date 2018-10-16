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
const int maxn = 1e4+10;
int dfn[maxn], low[maxn], cut[maxn];
vector<int> G[maxn];
stack<pii> sk;
int n, m, idx;

void init()
{
    for(int i = 0; i < n; i++){
        dfn[i] = low[i] = cut[i] = 0;
        G[i].clear();
    }
    idx = 0;
}

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    int chd = 0;
    for(auto v: G[u]){
        if(v == f)continue;
        if(!dfn[v]){
            chd++;
            sk.push(mk(u, v));
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){
                cut[u]++;
                while(1){
                    pii p = sk.top(); sk.pop();
                    if(p.fi == u && p.se == v)break;
                }
            }
        }
        else if(dfn[v] < dfn[u]){
            sk.push(mk(u, v));
            low[u] = min(low[u], dfn[v]);
        }   
    }
    if(f == -1)cut[u]--;
}

void tarjan()
{
    for(int i = 0; i < n; i++){
        if(!dfn[i])dfs(i, -1);
    }
}


int main()
{
    while(scanf("%d%d", &n, &m) != EOF && n){
        init();
        int u, v;
        while(scanf("%d%d", &u, &v) != EOF && u != -1){
            G[u].pb(v); G[v].pb(u);
        }
        tarjan();
        vector<pii> ans;
        for(int i = 0; i < n; i++){
            ans.pb(mk(-cut[i]-1, i));
        }
        sort(ALL(ans));
        for(int i = 0; i < m; i++)printf("%d %d\n", ans[i].se, -ans[i].fi);
        puts("");
    }
    return 0;
}

