#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define pb push_back
const int INF = 0x3f3f3f3f;
const int maxn = 210;
vector<int> G[maxn];
int mtx[maxn], mty[maxn];
int dx[maxn], dy[maxn], dis;
bool vis[maxn];
int n, m;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(mtx, 0, sizeof(mtx));
    memset(mty, 0, sizeof(mty));
}

bool bfs()
{
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    dis = INF;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!mtx[i])q.push(i), dx[i] = 0;
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G[u]){
            if(dy[v] == -1){
                dy[v] = dx[u]+1;
                if(!mty[v])dis = dy[v];
                else{
                    dx[mty[v]] = dy[v]+1;
                    q.push(mty[v]);
                }
            }
        }
    }
    return dis < INF;
}

bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v] && dy[v] == dx[u]+1){
            vis[v] = 1;
            if(mty[v] && dy[v] == dis)continue;
            else if(!mty[v] || dfs(mty[v])){
                mty[v] = u, mtx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int mac_match()
{
    int ret = 0;
    while(bfs()){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            if(!mtx[i] && dfs(i))ret++;
        }
    }
    return ret;
}

int max_match()
{
    int ret = 0;
    while(bfs()){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            if(!mtx[i] && dfs(i))ret++;
        }
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        scanf("%d%d", &n, &m);
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(v);
        }
        int ans = n-max_match();
        printf("%d\n", ans);
    }
    return 0;
}
