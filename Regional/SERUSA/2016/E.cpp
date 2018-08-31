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
const int maxn = 2e3+10;
int x[maxn], y[maxn];
vector<int> G[maxn];
int dfn[maxn], scc[maxn], low[maxn];
int idx, cnt;
stack<int> sk;
int n, r, k;

void dfs(int u, int f)
{
    sk.push(u);
    low[u] = dfn[u] = ++idx;
    for(auto v : G[u]){
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
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
    for(int i = 0; i < 2*k; i++){
        if(!dfn[i])dfs(i, -1);
    }
}

int main()
{
    scanf("%d%d%d", &n, &r, &k);
    for(int i = 0; i < k; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            if(x[i] == x[j] && ABS(y[i]-y[j]) < 2*r)G[i].pb(j+k), G[j].pb(i+k);
            if(y[i] == y[j] && ABS(x[i]-x[j]) < 2*r)G[i+k].pb(j), G[j+k].pb(i);
        }
    }
    tarjan();
    bool flg = 1;
    for(int i = 0; i < k; i++){
        if(scc[i] == scc[i+k])flg = 0;
    }
    if(flg)putchar('1');
    else putchar('0');
    return 0;
}

