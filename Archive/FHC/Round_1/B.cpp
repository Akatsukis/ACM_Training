#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sc(x) scanf("%d", &x)
const int maxn = 2e3+10;
int a[maxn], b[maxn];
int col[maxn];
bool vis[maxn];
vector<int> G[maxn];
vector<int> vec[2];

void init(int n)
{
    vec[0].clear(); vec[1].clear();
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++)G[i].clear();
}

void pre(int u)
{
    vec[0].pb(u);
    if(a[u])pre(a[u]);
    if(b[u])pre(b[u]);
}

void post(int u)
{
    if(a[u])post(a[u]);
    if(b[u])post(b[u]);
    vec[1].pb(u);
}

void dfs(int u, int k)
{
    vis[u] = 1;
    col[u] = k;
    for(auto v : G[u]){
        if(!vis[v])dfs(v, k);
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n, k;
        sc(n); sc(k);
        init(n);
        for(int i = 1; i <= n; i++){
            sc(a[i]); sc(b[i]);
        }
        pre(1);
        post(1);
        for(int i = 0; i < n; i++){
            G[vec[0][i]].pb(vec[1][i]);
            G[vec[1][i]].pb(vec[0][i]);
            //printf("%d %d\n", vec[0][i], vec[1][i]);
        }
        int now = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                now = min(now+1, k);
                dfs(i, now);
            }
        }
        if(now < k)printf("Case #%d: Impossible\n", kase++);
        else{
            printf("Case #%d: ", kase++);
            for(int i = 1; i <= n; i++)printf("%d%c", col[i], " \n"[i==n]);
        }

    }
}
