#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define sqr(x) ((x)*(x))
const int maxn = 1e5+10;
vector<int> G[maxn];
int a[maxn];
int deg[maxn];
bool vis[maxn];

void init(int n)
{
    memset(vis, 0, sizeof(vis));
    memset(deg, 0, sizeof(deg));
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= n; i++)G[i].clear();
}

void dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(!vis[v])dfs(v);
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        init(n);
        for(int i = 1; i <= n; i++){
            sc(a[i]);
        }
        if(!m){
            int ans = 0;
            for(int i = 1; i <= n; i++){
                ans = max(ans, a[i]);
            }
            printf("%d\n", ans);
            continue;
        }
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
            deg[u]++, deg[v]++;
        }
        int root = 0;
        for(int i = 1; i <= n; i++){
            if(G[i].size()){
                root = i;
                break;
            }
        }
        dfs(root);
        bool flag = 1;
        for(int i = 1; i <= n; i++)if(!vis[i] && G[i].size()){
            flag = 0;
            break;
        }
        if(!flag){
            printf("Impossible\n");
            continue;
        }
        int ans = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            if(deg[i]%2==1){
                if(deg[i]%4==1)ans ^= a[i];
                cnt++;
            }
            else{
                if(deg[i]%4==2){
                    ans ^= a[i];
                    //printf("ans=%d\n", ans);
                }
            }
        }
        //printf("cnt=%d\n", cnt);
        if(cnt == 2){
            printf("%d\n", ans);
        }
        else if(cnt == 0){
            int mx = 0;
            for(int i = 1; i <= n; i++){
                mx = max(mx, ans^a[i]);
            }
            printf("%d\n", mx);
        }
        else printf("Impossible\n");
    }
    return 0;
}
