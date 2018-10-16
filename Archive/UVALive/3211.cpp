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
const int INF = 0x3f3f3f3f;
const int maxn = 4e3+10;
int dfn[maxn], low[maxn], scc[maxn];
vector<int> G[maxn];
stack<int> sk;
pii pt[maxn];
int n, idx, cnt;

void init()
{
    for(int i = 1; i <= 2*n; i++){
        dfn[i] = low[i] = scc[i] = 0;
        G[i].clear();
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

void add_edge(int u, int v)
{
    G[u].pb(v);
}


bool check(int gap)
{
    init();
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            if(i == j)continue;
            if(pt[j].fi >= pt[i].fi && pt[j].fi < pt[i].fi+gap)add_edge(i, j+n), add_edge(j, i+n);
            if(pt[j].se >= pt[i].fi && pt[j].se < pt[i].fi+gap)add_edge(i, j), add_edge(j+n, i+n);
            if(pt[j].fi >= pt[i].se && pt[j].fi < pt[i].se+gap)add_edge(i+n, j+n), add_edge(j, i);
            if(pt[j].se >= pt[i].se && pt[j].se < pt[i].se+gap)add_edge(i+n, j), add_edge(j+n, i);
        }
    }
    tarjan();
    for(int i = 1; i <= n; i++){
        if(scc[i] == scc[i+n])return 0;
    }
    return 1;
}

int main()
{
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &pt[i].fi, &pt[i].se);            
        }
        int l = 0, r = INF, ans = 0;
        while(l <= r){
            int m = (l+r)>>1;
            if(check(m)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

