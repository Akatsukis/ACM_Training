#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define mk make_pair
#define pb push_back
#define ABS(x) ((x)>=0?(x):(-(x)))
const int maxn = 6e3+10;
const int maxm = 6e5+10;
struct Point
{
    int x, y;
}pnt[maxn];
struct Edge
{
    int u, v, dis, nxt;
    Edge(){}
    Edge(int u, int v, int dis, int nxt):u(u), v(v), dis(dis), nxt(nxt){}
}es[maxm];
vector<int> G[maxn];
stack<int> sk;
int par[maxn], head[maxn], col[maxn];
bool mark[maxn];
int dx[2][2] = {0, 1, 0, 1}, dy[2][2] = {0, 1, 1, 0};
int n, m;

void init()
{
    for(int i = 0; i < n; i++){
        par[i] = i; head[i] = -1;
    }
}

void add_edge(int u, int v, int w, int id)
{
    es[id*2] = Edge(u, v, w, head[u]);
    head[u] = id*2;
    es[id*2+1] = Edge(v, u, w, head[v]);
    head[v] = id*2+1;
}

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    par[x] = y;
}

int cal(int u, int v)
{
    return ABS(pnt[u].x-pnt[v].x)+ABS(pnt[u].y-pnt[v].y);
}

bool dfs(int u, int c)
{
    if(col[u]+1)return col[u] == c;
    else col[u] = c;
    for(int i = head[u]; ~i; i = es[i].nxt){
        if(!dfs(es[i].v, ((cal(u, es[i].v)^es[i].dis^c)&1)))return 0;
    }
    return 1;
}

void init_twosat()
{
    memset(mark, 0, sizeof(mark));
    for(int i = 0; i < 2*n; i++)G[i].clear();
}

bool dfs(int u)
{
    if(mark[u^1])return 0;
    if(mark[u])return 1;
    mark[u] = 1;
    sk.push(u);
    for(auto v : G[u]){
        if(!dfs(v))return 0;
    }
    return 1;
}

bool twosat()
{
    for(int i = 0; i < 2*n; i += 2){
        if(!mark[i] && !mark[i^1]){
            while(!sk.empty())sk.pop();
            if(!dfs(i)){
                while(!sk.empty()){
                    int u = sk.top(); sk.pop();
                    mark[u] = 0;
                }
                if(!dfs(i^1))return 0;
            }
        }
    }
    return 1;
}

bool check(int u, int c)
{
    memset(col, -1, sizeof(col));
    if(!dfs(u, c))return 0;
    init_twosat();
    for(int i = 0; i < 2*m; i += 2){
        if(find(es[i].u) != u)continue;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                int u = es[i].u, v = es[i].v;
                int x1 = pnt[u].x+dx[col[u]][j], y1 = pnt[u].y+dy[col[u]][j];
                int x2 = pnt[v].x+dx[col[v]][k], y2 = pnt[v].y+dy[col[v]][k];
                if(ABS(x1-x2)+ABS(y1-y2) != es[i].dis){
                    G[u<<1|j].pb(v<<1|(k^1));
                    G[v<<1|k].pb(u<<1|(j^1));
                }
            }
        }
    }
    return twosat();
}

bool solve()
{
    for(int i = 0; i < n; i++){
        if(par[i] == i){
            if(!check(i, 0) && !check(i, 1))return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        init();
        for(int i = 0; i < n; i++){
            scanf("%d%d", &pnt[i].x, &pnt[i].y);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            unite(u, v);
            add_edge(u, v, w, i);
        }
        if(solve())puts("possible");
        else puts("impossible");
    }
    return 0;
}
