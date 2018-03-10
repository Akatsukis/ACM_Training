#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
const int maxe = 410;
struct edge
{
    int v, w, nxt;
}es[maxe];
bool used[maxe];
int head[maxn];
int path[maxn][maxn];
int mincost[maxn];
bool vis[maxn];
int pre[maxn];
int id[maxn];
int n, m, cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w)
{
    es[cnt].v = v, es[cnt].w = w, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].v = u, es[cnt].w = w, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

int prim()
{
    memset(mincost, INF, sizeof(mincost));
    memset(vis, 0, sizeof(vis));
    memset(used, 0, sizeof(used));
    memset(path, 0, sizeof(path));
    mincost[1] = 0;
    int ret = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && mincost[i] != INF && (u == -1 || mincost[i] < mincost[u]))u = i;
        }
        if(u == -1)break;
        ret += mincost[u];
        vis[u] = 1;
        if(u != 1)used[id[u]] = used[id[u]^1] = 1;
        for(int i = head[u]; ~i; i = es[i].nxt){
            if(mincost[es[i].v] > es[i].w){
                mincost[es[i].v] = es[i].w;
                pre[es[i].v] = u;
                id[es[i].v] = i;
            }
        }
        for(int i = 1; i <= n; i++){
            if(vis[i] && i != u){
                path[i][u] = path[u][i] = max(path[i][pre[u]], mincost[u]);
            }
        }
    }
    for(int i = 1; i <= n; i++)if(!vis[i])return INF;
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        init();
        sc(n); sc(m);
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            add_edge(u, v, w);
        }
        int ans1 = prim(), ans2 = INF;
        if(ans1 == INF){
            printf("Case #%d : No way\n", kase++);
            continue;
        }
        for(int i = 1; i <= n; i++){
            for(int j = head[i]; ~j; j = es[j].nxt){
                if(!used[j]){
                    ans2 = min(ans2, ans1-path[i][es[j].v]+es[j].w);
                }
            }
        }
        if(ans2 == INF)printf("Case #%d : No second way\n", kase++);
        else printf("Case #%d : %d\n", kase++, ans2);
    }
    return 0;
}

