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
const int maxn = 2e5+10;
bool vis[maxn];
vector<int> G[maxn];
int sz[maxn];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : G[u]){
        if(vis[v])continue;
        sz[v]++;
        if(sz[v] >= (SZ(G[v])+1)/2)dfs(v);
    }
}

int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(t);
    if(vis[s])puts("leave");
    else puts("stay");
    return 0;
}


