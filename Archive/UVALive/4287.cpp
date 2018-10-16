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
const int maxn = 2e4+10;
vector<int> G[maxn];
stack<int> sk;
int dfn[maxn], low[maxn], scc[maxn];
int in[maxn], out[maxn];
int n, m, cnt, idx;

void init()
{
    for(int i = 1; i <= n; i++){
        G[i].clear();
        dfn[i] = low[i] = scc[i] = 0;
        in[i] = out[i] = 0;
    }
    cnt = idx = 0;
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
            scc[x] = cnt;
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
                if(scc[i] != scc[v])out[scc[i]]++, in[scc[v]]++;
            }
        }
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i <= cnt; i++){
            if(!in[i])ans1++;
            if(!out[i])ans2++;
        }
        int ans = cnt==1?0:max(ans1, ans2);
        printf("%d\n", ans);
    }
    return 0;
}

