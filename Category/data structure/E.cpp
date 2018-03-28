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
const int maxn = 2e5+10;
struct edge
{
    int u, v, w, id;
    bool operator < (const edge &rhs)const
    {
        return w<rhs.w;
    }
}es[maxn];
vector<edge> G[maxn];
int par[maxn];
int pid[maxn];
bool used[maxn];
int dep[maxn], anc[maxn][20], mx[maxn][20];
int ans[maxn];
int n, m;

void init_dsu()
{
    for(int i = 1; i <= n; i++)par[i] = i;
}

int find(int x)
{
    return x==par[x]?x:par[x]=find(par[x]);
}

bool unite(int x, int y)
{
    x = find(x); y = find(y);
    if(x == y)return false;
    par[x] = y;
    return true;
}

void kruskal()
{
    sort(es, es+m);
    for(int i = 0; i < m; i++){
        int u = es[i].u, v = es[i].v, w = es[i].w, id = es[i].id;
        if(unite(u, v)){
            used[es[i].id] = 1;
            G[u].pb((edge){u, v, w, id});
            G[v].pb((edge){v, u, w, id});
        }   
    }
}

void dfs(int u, int f)
{
    dep[u] = dep[f]+1;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i].v, w = G[u][i].w, id = G[u][i].id;
        if(v == f)continue;
        anc[v][0] = u;
        pid[v] = id;
        mx[v][0] = w;
        dfs(v, u);
    }
}

int lca(int u, int v)
{
    int ret = 0;
    if(dep[u] > dep[v])swap(u, v);
    for(int i = 17; i >= 0; i--){
        if(dep[anc[v][i]] >= dep[u]){
            ret = max(ret, mx[v][i]);
            v = anc[v][i];
        }
    }
    if(u == v)return ret;
    for(int i = 17; i >= 0; i--){
        if(anc[u][i] != anc[v][i]){
            ret = max(ret, max(mx[u][i], mx[v][i]));
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    ret = max(ret, max(mx[u][0], mx[v][0]));
    return ret;
}

int main()
{
    srand(unsigned(time(NULL)));
    sc(n); sc(m);
    init_dsu();
    for(int i = 0; i < m; i++){
        sc(es[i].u); sc(es[i].v); sc(es[i].w);
        es[i].id = i;
    }
    kruskal();
    dfs(rand()%n+1, 0);
    for(int i = 1; i < 18; i++){
        for(int j = 1; j <= n; j++){
            anc[j][i] = anc[anc[j][i-1]][i-1];
            mx[j][i] = max(mx[j][i-1], mx[anc[j][i-1]][i-1]);
        }
    }
    init_dsu();
    memset(ans, 0x3f, sizeof(ans));
    for(int i = 0; i < m; i++){
        int u = es[i].u, v = es[i].v, w = es[i].w, id = es[i].id;
        if(!used[id]){
            int ret = lca(u, v);
            ans[id] = ret;
            while(1){
                u = find(u); v = find(v);
                if(u == v)break;
                if(dep[u] > dep[v])swap(u, v);
                ans[pid[v]] = w;
                unite(v, anc[v][0]);
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(ans[i] == INF)ans[i] = 0;
        printf("%d%c", ans[i]-1, " \n"[i==m-1]);
    }
    return 0;
}

