#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define VI vector<int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e4+10;
const int maxd = 20;
int par[maxn];
int dep[maxn], anc[maxn][maxd], idx;
int from[maxn], to[maxn];
int bit[maxn];
vector<VI> qry;
vector<int> ans;
struct Node
{
    int to;
    bool del;
    Node(int x):to(x), del(0){}
    bool operator < (const Node &rhs)const
    {
        if(to != rhs.to)return to < rhs.to;
        return del > rhs.del;
    }
};
vector<Node> G[maxn];
int n, m, q;

void init()
{
    for(int i = 1; i <= n; i++){
        par[i] = i;
        from[i] = bit[i] = 0;
        G[i].clear();
    }
    qry.clear();
    ans.clear();
    idx = 0;
}

void add(int u, int val)
{
    while(u <= n){
        bit[u] += val;
        u += u&(-u);
    }
}

void update(int x, int y, int val)
{
    add(x, val);
    add(y+1, -val);
}

int sum(int u)
{
    int ret = 0;
    while(u){
        ret += bit[u];
        u -= u&(-u);
    }
    return ret;
}

void dfs(int u, int f)
{
    if(f)G[u].erase(lower_bound(ALL(G[u]), Node(f)));
    from[u] = ++idx;
    dep[u] = dep[f]+1;
    anc[u][0] = f;
    for(auto &v : G[u])if(!v.del && !from[v.to]){
        v.del = 1;
        dfs(v.to, u);
    }
    to[u] = idx;
    update(from[u], to[u], 1);
}

void init_lca()
{
    for(int i = 1; i < maxd; i++){
        for(int j = 1; j < maxn; j++){
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
}

int lca(int u, int v)
{
    if(dep[u] > dep[v])swap(u, v);
    for(int i = maxd-1; i >= 0; i--){
        if(dep[anc[v][i]] >= dep[u])v = anc[v][i];
    }
    if(u == v)return u;
    for(int i = maxd-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

void Link(int u, int f)
{
    u = find(u);
    while(u != f){
        int v = find(anc[u][0]);
        par[u] = v;
        update(from[u], to[u], -1);
        u = v;
    }
}

void Merge(int u, int v)
{
    int f = find(lca(u, v));
    Link(u, f); Link(v, f);
}

void solve()
{
    dfs(1, 0);
    init_lca();
    for(int i = 1; i <= n; i++){
        for(auto &u : G[i])if(!u.del){
            Merge(i, u.to);
        }
    }
    for(int i = (int)qry.size()-1; i >= 0; i--){
        if(qry[i][0] == 1)Merge(qry[i][1], qry[i][2]);
        else{
            int u = from[qry[i][1]], v = from[qry[i][2]];
            int f = from[lca(qry[i][1], qry[i][2])];
            int ret = sum(u)+sum(v)-2*sum(f);
            ans.pb(ret);
        }
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(m); sc(q);
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(Node(v));
            G[v].pb(Node(u));
        }
        for(int i = 1; i <= n; i++)sort(ALL(G[i]));
        for(int i = 0; i < q; i++){
            int u, v, w;
            sc(w); sc(u); sc(v);
            qry.pb(VI{w, u, v});
            if(w == 2)continue;
            lower_bound(ALL(G[u]), Node(v))->del = 1;
            lower_bound(ALL(G[v]), Node(u))->del = 1;
        }
        solve();
        printf("Case #%d:\n", kase++);
        reverse(ALL(ans));
        for(auto u : ans)printf("%d\n", u);
    }
    return 0;
}

