#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define pb push_back
const int maxn = 1e6+10;
vector<int> G[maxn];
int f[maxn], sz[maxn];
int n;

void dfs(int u, int fa)
{
    sz[u] = 1;
    for(auto v: G[u]){
        if(v == fa)continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    f[n/__gcd(n, sz[u])]++;
}

int main()
{
    sc(n);
    for(int i = 1; i < n; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1, 0);
    for(int i = n; i >= 1; i--){
        for(int j = 2*i; j <= n; j += i)f[j] += f[i];
    }
    vector<int> ans;
    for(int i = 2; i <= n; i++){
        if(f[i] >= i)ans.pb(i-1);
    }
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d%c", ans[i], " \n"[i==(int)ans.size()-1]);
    }
    return 0;
}
