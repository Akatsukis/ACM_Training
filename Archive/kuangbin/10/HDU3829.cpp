#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 1e3+10;
struct atom
{
    int u, v;
}tb[maxn];
vector<int> G[maxn];
bool vis[maxn];
int mat[maxn];

void init(int n)
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(mat, 0, sizeof(mat));
}

bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v]){
            vis[v] = 1;
            if(!mat[v] || dfs(mat[v])){
                mat[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int p, q, n;
    while(scanf("%d%d%d", &p, &q, &n) != EOF){
        init(n);
        for(int i = 1; i <= n; i++){
            char c1, c2;
            int u1, u2;
            scanf(" %c%d %c%d ", &c1, &u1, &c2, &u2);
            if(c1 == 'C')u2 += p;
            else u1 += p;
            tb[i].u = u1, tb[i].v = u2;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j)continue;
                if(tb[i].u == tb[j].v || tb[i].v == tb[j].u)G[i].pb(j);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i))ans++;
        }
        ans = (2*n-ans)/2;
        printf("%d\n", ans);
    }
    return 0;
}
