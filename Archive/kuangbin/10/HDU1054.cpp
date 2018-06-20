#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define pb push_back
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+10;
vector<int> edge[maxn], G[maxn];
int totx, toty;
int mtx[maxn], mty[maxn];
int dx[maxn], dy[maxn], dis;
int id[maxn];
bool vis[maxn];

void init(int n)
{
    for(int i = 0; i <= n; i++)edge[i].clear(), G[i].clear();
    memset(mtx, 0, sizeof(mtx));
    memset(mty, 0, sizeof(mty));
    memset(vis, 0, sizeof(vis));
    totx = toty = 0;
}

void dfs(int u, int t)
{
    if(t)id[u] = ++totx;
    else id[u] = ++toty;
    //printf("id[%d]=%d\n", u, id[u]);
    for(auto v : edge[u]){
        dfs(v, (t+1)%2);
        if(t)G[id[u]].pb(id[v]);
        else G[id[v]].pb(id[u]);
    }
}

bool bfs()
{
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    queue<int> q;
    for(int i = 1; i <= totx; i++){
        if(!mtx[i])q.push(i), dx[i] = 0;
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dx[u] > dis)break;
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
            if(dy[v] == dis && mty[v])continue;
            else if(!mty[v] || dfs(mty[v])){
                mty[v] = u, mtx[u] = v;
                //printf("match(%d,%d)\n", u, v);
                return 1;
            }
        }
    }
    return 0;
}

int max_match()
{
    int ret = 0;
    while(bfs()){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= totx; i++){
            if(!mtx[i] && dfs(i))ret++;
        }
    }
    return ret;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        init(n);
        for(int i = 0; i < n; i++){
            int u, k;
            scanf("%d:(%d)", &u, &k);
            for(int j = 0; j < k; j++){
                int v; sc(v);
                edge[u].pb(v);
                vis[v] = 1;
            }
        }
        int root = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i])root = i;
        }
        dfs(root, 1);
        int ans = max_match();
        printf("%d\n", ans);
    }
    return 0;
}
