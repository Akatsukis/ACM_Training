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
const int maxn = 6e2+10;
int dfn[maxn], low[maxn], scc[maxn];
vector<int> G[maxn];
stack<int> sk;
int n, cnt, idx;

void init()
{
    for(int i = 1; i <= 2*n; i++){
        dfn[i] = low[i] = scc[i] = 0;
        G[i].clear();
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
    for(int i = 1; i <= 2*n; i++){
        if(!dfn[i])dfs(i);
    }
}

int main()
{
    while(sc(n) != EOF && n){
        init();
        int u, v;
        while(scanf("%d%d", &u, &v) != EOF && u){
            G[u].pb(v+n);
            G[v].pb(u+n);
            G[u+n].pb(v);
            G[v+n].pb(u);
        }
        tarjan();
        bool ok = 1;
        for(int i = 1; i <= n; i++){
            if(scc[i] == scc[i+n]){
                ok = 0;
                break;
            }
        }
        if(ok)puts("YES");
        else puts("NO");
    }
    return 0;
}

