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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
const int len = 19;
vector<pii> G[maxn];
int in[maxn];
int ans[maxn];
int anc[maxn][len];
int dep[maxn];
ll cost[maxn];
bool vis[maxn];
priority_queue<pair<ll, int> > pq;
struct edge
{
    int u, v, w, nxt;
}es[maxn*2];
int head[maxn];
int sz[maxn];
vector<pii> vec[maxn];
vector<pii> dmt[maxn];
int n, m, cnt;

void add_edge(int u, int v, int w)
{
    es[cnt].u = u, es[cnt].v = v, es[cnt].w = w, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].u = v, es[cnt].v = u, es[cnt].w = w, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

void spfa()
{
    memset(cost, 0x3f, sizeof(cost));
    memset(vis, 0 ,sizeof(vis));
    cost[1] = 0; vis[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
            int v = es[i].v;
            if(cost[v] > cost[u]+es[i].w){
                cost[v] = cost[u]+es[i].w;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        vis[u] = 0;
    }
}

int lca(int u, int v)
{
    if(dep[u]<dep[v])swap(u, v);
    for(int i = len-1; i >= 0; i--){
        if(dep[anc[u][i]] >= dep[v])u = anc[u][i];
    }
    if(u == v)return u;
    for(int i = len-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}

void dfs(int u)
{
    sz[u]++;
    for(int i = 0; i < (int)dmt[u].size(); i++){
        int v = dmt[u][i].fi;
        //printf("%d->%d id=%d\n", u, v, dmt[u][i].se);
        dfs(v);
        //printf("sz[%d]:%d\n", v, sz[v]);
        sz[u] += sz[v];
        if(dmt[u][i].se != -1){
            ans[dmt[u][i].se] = sz[v];
            //printf("ans[%d]=%d\n", dmt[u][i].se, sz[v]);
        }
    }
}

void solve()
{
    queue<int> q;
    q.push(1);
    dep[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i].fi;
            in[v]--;
            vec[v].pb(mk(u, G[u][i].se));
            if(!in[v]){
                int fa = vec[v][0].fi;
                for(int j = 1; j < (int)vec[v].size(); j++){
                    fa = lca(fa, vec[v][j].fi);
                }
                anc[v][0] = fa;
                dep[v] = dep[fa]+1;
                for(int j = 1; j < len; j++){
                    anc[v][j] = anc[anc[v][j-1]][j-1];
                }
                q.push(v);
                if(vec[v].size() == 1)dmt[fa].pb(mk(v, vec[v][0].se));
                else dmt[fa].pb(mk(v, -1));
            }
        }
    }
    dfs(1);
}

int main()
{
    memset(head, -1, sizeof(head));
    sc(n); sc(m);
    for(int i = 0; i < m; i++){
        int u, v, w;
        sc(u); sc(v); sc(w);
        add_edge(u, v, w);
    }
    spfa();
    for(int i = 0; i < cnt; i++){
        int u = es[i].u, v = es[i].v, w = es[i].w;
        if(cost[v] == cost[u]+w){
            G[u].pb(mk(v, i/2));
            in[v]++;
        }
    }
    solve();
    for(int i = 0; i < m; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}
