#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define sc(x) scanf("%d", &x)
#define pb push_back
const int maxn = 2e5+10;
vector<int> G[maxn];
int sz[maxn];
int n, k;

void dfs(int u, int f)
{
    sz[u] = 1;
    for(auto v : G[u]){
        if(v == f)continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n); sc(k);
        for(int i = 1; i <= n; i++)G[i].clear();
        for(int i = 0; i < n-1; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1, 0);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(sz[i] >= k && n-sz[i] >= k)ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
