#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
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
const int maxn = 1e5+10;
vector<int> G[maxn];
int dfn[maxn], low[maxn];
int par[maxn], fa[maxn];
int n, m, q;
int ans, idx;

void init()
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(fa, 0, sizeof(fa));
    for(int i = 0; i <= n; i++)par[i] = i, G[i].clear();
    ans = idx = 0;
}

int find(int x)
{   
    return par[x]==x?x:par[x]=find(par[x]);
}

bool unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y)return false;
    par[x] = y;
    return true;
}

void dfs(int u, int f)
{
    fa[u] = f;
    dfn[u] = low[u] = ++idx;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u])ans++;
            else unite(u, v);
        }
        if(dfn[v] < dfn[u])low[u] = min(low[u], dfn[v]);
    }   
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}

void lca(int u, int v)
{
    if(dfn[u] < dfn[v])swap(u, v);
    while(dfn[u] > dfn[v]){
        if(unite(u, fa[u]))ans--;
        u = fa[u];
    }
    while(u != v){
        if(unite(v, fa[v]))ans--;
        v = fa[v];
    }
}

int main()
{
    int kase = 1;
    while(scanf("%d%d", &n, &m) != EOF && (n||m)){
        init();
        printf("Case %d:\n", kase++);
        int u, v;
        for(int i = 0; i < m; i++){
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        tarjan();
        sc(q);
        for(int i = 0; i < q; i++){
            sc(u); sc(v);
            lca(u, v);
            printf("%d\n", ans);
        }
        puts("");
    }
    return 0;
}

