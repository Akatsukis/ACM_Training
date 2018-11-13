#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 6e5+10;
ll ans[maxn], tr[maxn];
int dep[maxn];
vector<int> G[maxn];
vector<pii> qry[maxn];
int n, m;

void add(int x, int v)
{
    while(x <= 2*n){
        tr[x] += v;
        x += x&-x;
    }
}

ll sum(int x)
{
    ll ret = 0;
    while(x){
        ret += tr[x];
        x -= x&-x;
    }
    return ret;
}

void dfs(int u, int f)
{
    dep[u] = dep[f]+1;
    for(auto p : qry[u]){
        add(dep[u], p.se);
        add(dep[u]+p.fi+1, -p.se);
    }
    ans[u] = sum(dep[u]);
    for(auto v : G[u]){
        if(v == f)continue;
        dfs(v, u);
    }
    for(auto p : qry[u]){
        add(dep[u], -p.se);
        add(dep[u]+p.fi+1, p.se);
    }
}

int main()
{
    sc(n);
    for(int i = 1; i < n; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v); G[v].pb(u);
    }
    sc(m);
    for(int i = 0; i < m; i++){
        int v, d, x;
        scanf("%d%d%d", &v, &d, &x);
        qry[v].pb(mk(d, x));
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)printf("%lld%c", ans[i], " \n"[i==n]);
    return 0;
}

