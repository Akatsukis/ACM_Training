#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
const int maxm = maxn*maxn;
struct edge
{
    int to, nxt, id;
    bool type;
}es[2*maxm];
int head[maxn], dfn[maxn], low[maxn];
bool vis[maxn], used[maxm], cut[maxm];
int n, m, idx, cnt;

void init()
{
    for(int i = 1; i <= n; i++){
        dfn[i] = low[i] = vis[i] = 0;
        head[i] = -1;
    }
    for(int i = 1; i <= m; i++)used[i] = cut[i] = 0;
    idx = cnt = 0;
}

void add_edge(int u, int v, int w, int id)
{
    es[cnt] = edge{v, head[u], id, w==2};
    head[u] = cnt++;
}

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    for(int i = head[u]; ~i; i = es[i].nxt){
        int v = es[i].to;
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u])cut[es[i].id] = 1;
        }
        else low[u] = min(low[u], dfn[v]);
    }
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for(int i = head[u]; ~i; i = es[i].nxt){
        int v = es[i].to, id = es[i].id;
        if(used[id])continue;
        else used[id] = 1;
        if(es[i].type){
            if(cut[id])printf("%d %d 2\n", u, v);
            else printf("%d %d 1\n", u, v);
        }
        if(!vis[v])dfs(v);
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(int i = 1; i <= m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if(w == 1)add_edge(u, v, w, i);
            else add_edge(u, v, w, i), add_edge(v, u, w, i);
        }
        tarjan();
        for(int i = 1; i <= n; i++){
            if(!vis[i])dfs(i);
        }
    }
    return 0;
}
