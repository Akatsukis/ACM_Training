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
vector<int> G[maxn];
int deg[maxn];
bool vis[maxn];
int n, m, k;

void init()
{
    for(int i = 0; i < n; i++)G[i].clear(), deg[i] = 0, vis[i] = 0;
}

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : G[u]){
        if(!vis[v])dfs(v);
    }
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n); sc(m); sc(k);
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            deg[u]++, deg[v]++;
            G[u].pb(v);
            G[v].pb(u);
        }
        int ans = -1, mx = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i])dfs(i), ans++;
            mx = max(mx, deg[i]);
        }
        ans = min(ans+mx+k, n-1);
        printf("%d\n", ans);
    }
    return 0;
}


