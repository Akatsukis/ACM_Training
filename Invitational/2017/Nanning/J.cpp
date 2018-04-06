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
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
const int maxnode = 5e6+10;
int val[maxn];
int root[maxn];
int nxt[maxnode][2];
vector<int> G[maxn];
vector<pii> qry[maxn];
int ans[maxn];
int idx;

void init(int n)
{
    memset(root, 0, sizeof(root));
    memset(nxt, 0, sizeof(nxt));
    for(int i = 0; i <= n; i++)G[i].clear(), qry[i].clear();
    idx = 0;
}

void Insert(int &rt, int x)
{
    if(!rt)rt = ++idx;
    int np = rt;
    for(int i = 30; i >= 0; i--){
        int p = ((1<<i)&x)>>i;
        if(!nxt[np][p])nxt[np][p] = ++idx;
        np = nxt[np][p];
    }
}

void Merge(int &ls, int &rs)
{
    if(!ls){
        ls = rs;
        return;
    }
    else if(!rs){
        rs = ls;
        return;
    }
    Merge(nxt[ls][0], nxt[rs][0]);
    Merge(nxt[ls][1], nxt[rs][1]);
}

int query(int rt, int x)
{
    int ret = 0;
    for(int i = 30; i >= 0; i--){
        int p = ((1<<i)&x)>>i;
        if(nxt[rt][!p]){
            ret += (1<<i);
            rt = nxt[rt][!p];
        }
        else rt = nxt[rt][p];
    }
    return ret;
}

void dfs(int u)
{
    Insert(root[u], val[u]);
    for(auto v : G[u]){
        dfs(v);
        Merge(root[u], root[v]);
    }
    for(auto v : qry[u]){
        ans[v.se] = query(root[u], v.fi);
    }
}

int main()
{
    int n, q;
    while(scanf("%d%d", &n, &q) != EOF){
        init(n);
        for(int i = 1; i <= n; i++)sc(val[i]);
        for(int i = 2; i <= n; i++){
            int f;
            sc(f);
            G[f].pb(i);
        }
        for(int i = 1; i <= q; i++){
            int u, x;
            sc(u); sc(x);
            qry[u].pb(mk(x, i));
        }
        dfs(1);
        for(int i = 1; i <= q; i++)printf("%d\n", ans[i]);
    }
    return 0;
}

