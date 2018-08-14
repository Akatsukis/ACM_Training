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
#define mid (l+r)/2
#define lson k<<1
#define rson k<<1|1
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
const int maxm = 1e6+10;
struct Query
{
    int xl, xr, yl, yr, id;
    Query(){}
    Query(int xl, int xr, int yl, int yr, int id):xl(xl), xr(xr), yl(yl), yr(yr), id(id){}
};
struct Node
{
    int mn, mx, t;
    Node(){}
    Node(int mn, int mx, int t):mn(mn), mx(mx), t(t){}
}ans[maxm], tr[maxn*4];
int y[maxn], w[maxn];
vector<Query> vec[maxn*4];
vector<Query> tmp[maxn];
int n, m, mod;

void init()
{
    for(int i = 1; i <= m; i++)ans[i] = Node(INF, -INF, 1);
    for(int i = 1; i <= 4*n; i++)tr[i] = Node(INF, -INF, 1), vec[i].clear();
}

void insert(int k, int l, int r, Query t)
{
    if((t.xl <= mid && t.xr > mid) || (l == r))vec[k].pb(t);
    else if(t.xl <= mid)insert(lson, l, mid, t);
    else insert(rson, mid+1, r, t);
}

Node merge(Node a, Node b)
{
    Node ret;
    ret.mn = min(a.mn, b.mn);
    ret.mx = max(a.mx, b.mx);
    ret.t = 1LL*a.t*b.t%mod;
    return ret;
}

void update(int a, int k, int l, int r, Node nd)
{
    if(l == r){
        tr[k] = merge(tr[k], nd);
        return;
    }
    if(a <= mid)update(a, lson, l, mid, nd);
    else update(a, rson, mid+1, r, nd);
    tr[k] = merge(tr[lson], tr[rson]);
}

void change(int a, int k, int l, int r, Node nd)
{
    if(l == r){
        tr[k] = nd;
        return;
    }
    if(a <= mid)change(a, lson, l, mid, nd);
    else change(a, rson, mid+1, r, nd);
    tr[k] = merge(tr[lson], tr[rson]);
}

Node query(int a, int b, int k, int l, int r)
{
    if(l == a && r == b)return tr[k];
    else if(b <= mid)return query(a, b, lson, l, mid);
    else if(a >= mid+1)return query(a, b, rson, mid+1, r);
    else return merge(query(a, mid, lson, l, mid), query(mid+1, b, rson, mid+1, r));
}


void solve(int k, int l, int r)
{
    for(int i = l; i <= r; i++)tmp[i].clear();
    for(auto u : vec[k]){
        tmp[u.xl].pb(u);
        if(u.xl != u.xr)tmp[u.xr].pb(u);
    }
    for(int i = mid; i >= l; i--){
        update(y[i], 1, 1, n, Node(w[i], w[i], w[i]));
        for(auto q : tmp[i]){
            ans[q.id] = merge(ans[q.id], query(q.yl, q.yr, 1, 1, n));
        }
    }
    for(int i = mid; i >= l; i--)change(y[i], 1, 1, n, Node(INF, -INF, 1));
    for(int i = mid+1; i <= r; i++){
        update(y[i], 1, 1, n, Node(w[i], w[i], w[i]));
        for(auto q : tmp[i]){
            ans[q.id] = merge(ans[q.id], query(q.yl, q.yr, 1, 1, n));
        }
    }
    for(int i = mid+1; i <= r; i++)change(y[i], 1, 1, n, Node(INF, -INF, 1));
    if(l == r)return;
    solve(lson, l, mid);
    solve(rson, mid+1, r);
}


int main()
{
    int T; sc(T);
    while(T--){
        sc(n);
        for(int i = 1; i <= n; i++)sc(y[i]), sc(w[i]);
        ll A, B, C, D, P, Q, R, MOD;
        scanf("%d%lld%lld%lld%lld", &m, &A, &B, &C, &D);
        scanf("%lld%lld%lld%lld%d", &P, &Q, &R, &MOD, &mod);
        init();
        for(int i = 1; i <= m; i++){
            ll tA = (P*A+Q*B+R)%MOD, tB = (P*B+Q*A+R)%MOD;
            ll tC = (P*C+Q*D+R)%MOD, tD = (P*D+Q*C+R)%MOD;
            int xl = min(tA%n, tB%n)+1, xr = max(tA%n, tB%n)+1; 
            int yl = min(tC%n, tD%n)+1, yr = max(tC%n, tD%n)+1; 
            A = tA, B = tB, C = tC, D = tD;
            insert(1, 1, n, Query(xl, xr, yl, yr, i));
        }
        solve(1, 1, n);
        ll ret = 0;
        for(int i = 1; i <= m; i++)if(ans[i].mn != INF)ret += ans[i].mn^ans[i].mx^ans[i].t;
        printf("%lld\n", ret);
    }
    return 0;
}


