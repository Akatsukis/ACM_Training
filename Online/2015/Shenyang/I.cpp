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
const int maxh = 20;
struct Node
{
    int to, del;
    Node(int x):to(x), del(0){}
    bool operator < (const Node &rhs)const
    {
        if(to != rhs.to)return to < rhs.to;
        else return del > rhs.del;
    }
};
vector<Node> G[maxn];
int par[maxn];
int beg[maxn], ed[maxn], idx;
int dep[maxn], anc[maxn][maxh];
int bit[maxn];
vector<int> ans;
vector<VI> qry;
int n, m;

void init()
{
    for(int i = 1; i <= n; i++){
        G[i].clear();
        par[i] = i;
        bit[i] = beg[i] = 0;
    }
    ans.clear();
    qry.clear();
    idx = 0;
}

void add(int u, int val)
{
    while(u <= n){
        bit[u] += val;
        u += u&(-u);
    }
}

void modify(int x, int y, int val)
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
    beg[u] = ++idx;
    anc[u][0] = f;
    dep[u] = dep[f]+1;
    if(f){
        G[u].erase(lower_bound(ALL(G[u]), Node(f)));
    }
    for(Node &v : G[u]){
        if(!beg[v.to] && !v.del){
            v.del = 1;
            dfs(v.to, u);
        }   
    }
    ed[u] = idx;
    modify(beg[u], ed[u], 1);
}

void init_lca()
{
    for(int i = 1; i < maxh; i++){
        for(int j = 1; j <= n; j++){
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
}

int lca(int u, int v)
{
    if(dep[u] < dep[v])swap(u, v);
    for(int i = maxh-1; i >= 0; i--){
        if(dep[anc[u][i]] >= dep[v])u = anc[u][i];
    }
    if(u == v)return u;
    for(int i = maxh-1; i >= 0; i--){
        if(anc[u][i] != anc[v][i])u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}

int find(int x)
{
    return x==par[x] ? x : par[x] = find(par[x]);
}

void Link(int u, int f)
{
    u = find(u);
    while(u != f){
        int t = find(anc[u][0]);
        par[u] = t;
        modify(beg[u], ed[u], -1);
        u = t;
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
        for(Node u : G[i])if(!u.del)Merge(i, u.to);
    }
    for(VI vec : qry){
        if(vec[0] == 1){
            Merge(vec[1], vec[2]);
        }
        else{
            int u = beg[find(vec[1])], v = beg[find(vec[2])];
            int f = beg[find(lca(vec[1], vec[2]))];
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
        int q;
        sc(n); sc(m); sc(q);
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].pb(Node(v));
            G[v].pb(Node(u));
        }
        for(int i = 1; i <= n; i++)sort(ALL(G[i]));
        for(int i = 0; i < q; i++){
            int op, u, v;
            scanf("%d%d%d", &op, &u, &v);
            qry.pb(VI{op, u, v});
            if(op == 1){
                lower_bound(ALL(G[u]), Node(v))->del = 1;
                lower_bound(ALL(G[v]), Node(u))->del = 1;
            }
        }
        reverse(ALL(qry));
        solve();
        reverse(ALL(ans));
        printf("Case #%d:\n", kase++);
        for(int u : ans)printf("%d\n", u);
    }
    return 0;
}

