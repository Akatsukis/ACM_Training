#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 5e2+10;
bool G[maxn][maxn];
int mat[maxn];
bool vis[maxn];
int n, m;

bool dfs(int u)
{
    for(int i = 1; i <= n; i++){
        if(!G[u][i] || vis[i])continue;
        vis[i] = 1;
        if(!mat[i] || dfs(mat[i])){
            mat[i] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    while(scanf("%d%d", &n, &m) && (n||m)){
        memset(G, 0, sizeof(G));
        memset(mat, 0, sizeof(mat));
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u][v] = 1;
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(G[i][k] && G[k][j])G[i][j] = 1;
                }
            }
        }
        int ans = n;
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i))ans--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
