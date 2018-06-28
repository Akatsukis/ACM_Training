#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 2e3+10;
const int maxm = 1e6+10;
const int INF = 0x3f3f3f3f;
int mp[maxn][maxn];
int head[maxn], iter[maxn], lev[maxn];
struct edge
{
    int to, cap, nxt;
}es[maxm];
int n, b, cnt;

void add_edge(int u, int v, int cap)
{
    //printf("add_edge(%d,%d,%d)\n", u, v, cap);
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

void init()
{
    memset(head, -1, sizeof(head));
    cnt = 0;
    //puts("");
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
            edge &e = es[i];
            if(e.cap && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    int ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.cap && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap , f-ret));
            if(d){
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
                if(ret == f)break;
            }
        }
    }
    if(!ret)lev[v] = 0;
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

bool solve(int m)
{
    //printf("m=%d\n", m);
    for(int i = 1; i+m-1 <= b; i++){
        init();
        int src = n+b+1, dst = src+1;
        for(int u = 1; u <= n; u++){
            add_edge(src, u, 1);
        }
        for(int u = 1; u <= b; u++){
            add_edge(u+n, dst, mp[n+1][u]);
        }
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < m; k++){
                add_edge(j, n+mp[j][i+k], 1);
            }
        }
        if(max_flow(src, dst) == n)return 1;
    }
    return 0;
}

int main()
{
    while(scanf("%d%d", &n, &b) != EOF){
        for(int i = 1; i <= n+1; i++){
            for(int j = 1; j <= b; j++){
                scanf("%d", &mp[i][j]);
            }
        }
        int l = 1, r = b, ans = -1;
        while(l <= r){
            int m = (l+r)>>1;
            if(solve(m)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

