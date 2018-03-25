#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define pii pair<int, int>
#define mk make_pair
#define sc(x) scanf("%d", &x)
#define fi first
#define se second
#define pb push_back
const int maxn = 1010;
const int maxm = 20010;
const int INF = 0x3f3f3f3f;
struct edge
{
    int v, w, nxt;
}es[maxm];
int dist[maxn];
int head[maxn];
int lev[maxn];
int iter[maxn];
vector<pii> G[maxn];
int cnt = 0;

void init()
{
    memset(head, -1, sizeof(head));
    for(int i = 0; i < maxn; i++)G[i].clear();
    cnt = 0;
}

void dijkstra(int s)
{
    memset(dist, INF, sizeof(dist));
    dist[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(mk(0, s));
    while(!q.empty()){
        int u = q.top().se, w = q.top().fi; q.pop();
        if(w > dist[u])continue;
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i].fi;
            w = G[u][i].se;
            if(dist[v] > dist[u]+1){
                dist[v] = dist[u]+1;
                q.push(mk(dist[v], v));
            }
        }
    }
}

void add_edge(int u, int v, int w)
{
    es[cnt].v = v, es[cnt].w = w, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].v = u, es[cnt].w = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

bool bfs(int s, int t)
{
    memset(lev, INF, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
            edge &e = es[i];
            //printf("u=%d v=%d w=%d\n", u, e.v, e.w);
            if(e.w && lev[e.v] > lev[u]+1){
                lev[e.v] = lev[u]+1;
                if(e.v == t)return true;
                q.push(e.v);
            }
        }
    }
    return false;
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    int ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.w && lev[e.v] == lev[v]+1){
            int d = dfs(e.v, t, min(e.w, f-ret));
            if(d){
                e.w -= d;
                es[i^1].w += d;
                ret += d;
                if(ret == f)break;
            }
        }
    }
    return ret;
}

int max_flow(int s, int t)
{
    int ret = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        ret += dfs(s, t, INF);
    }
    return ret;
}
int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            G[u].pb(mk(v, w));
            G[v].pb(mk(u, w));
        }
        dijkstra(1);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < (int)G[i].size(); j++){
                int u = G[i][j].fi, w = G[i][j].se;
                if(dist[i]+1 == dist[u]){
                    add_edge(i, u, w);
                    //printf("u=%d v=%d w=%d\n", i, u, w);
                }
            }
        }
        int ans = max_flow(1, n);
        printf("%d\n", ans);
    }
    return 0;
}
