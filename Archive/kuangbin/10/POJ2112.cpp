#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+10;
const int maxm = 1e5+10;
int mp[maxn][maxn];
struct edge
{
    int to, cap, nxt;
}es[maxm];
int head[maxn], lev[maxn], iter[maxn];
int k, c, m, cnt;

void add_edge(int u, int v, int cap)
{
    //printf("add_edge(%d,%d,%d)\n", u, v, cap);
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
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
            int d = dfs(e.to, t, min(e.cap, f-ret));
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

bool solve(int mid)
{
    //printf("mid=%d\n", mid);
    memset(head, -1, sizeof(head));
    cnt = 0;
    int src = k+c, dst = src+1;
    for(int i = 0; i < c; i++){
        add_edge(src, i+k, 1);
    }
    for(int i = 0; i < k; i++){
        add_edge(i, dst, m);
    }
    for(int i = 0; i < k; i++){
        for(int j = k; j < k+c; j++){
            if(mp[i][j] <= mid){
                add_edge(j, i, 1);
            }
        }
    }
    //printf("ans=%d\n", max_flow(src, dst));
    return max_flow(src, dst) == c;
}


int main()
{
    while(scanf("%d%d%d", &k, &c, &m) != EOF){
        for(int i = 0; i < k+c; i++){
            for(int j = 0; j < k+c; j++){
                scanf("%d", &mp[i][j]);
                if(!mp[i][j])mp[i][j] = INF;
            }
        }
        for(int h = 0; h < k+c; h++){
            for(int i = 0; i < k+c; i++){
                for(int j = 0; j < k+c; j++){
                    mp[i][j] = min(mp[i][j], mp[i][h]+mp[h][j]);
                }
            }
        }
        int l = 0, r = INF, ans = 0;;
        while(l <= r){
            int mid = (l+r)>>1;
            if(solve(mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
