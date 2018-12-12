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
#define lson k*2+1
#define rson k*2+2
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+10;
vector<int> G[maxn];
int dep[maxn], beg[maxn];
int tr[maxn][3];
int n, q, tot;

void dfs(int u, int d)
{
    beg[u] = ++tot; dep[tot] = d;
    for(auto v : G[u]){
        dfs(v, d+1);
        dep[++tot] = d;
    }
}

void build_id(int k, int l, int r)
{
    if(l == r-1){
        tr[k][0] = tr[k][1] = l;
        return;
    }
    int m = (l+r)>>1;
    build_id(lson, l, m);
    build_id(rson, m, r);
    tr[k][0] = beg[tr[lson][0]]<beg[tr[rson][0]]?tr[lson][0]:tr[rson][0];
    tr[k][1] = beg[tr[lson][1]]>beg[tr[rson][1]]?tr[lson][1]:tr[rson][1];
}

void build_dep(int k, int l, int r)
{
    if(l == r-1){
        tr[k][2] = dep[l];
        return;
    }
    int m = (l+r)>>1;
    build_dep(lson, l, m);
    build_dep(rson, m, r);
    tr[k][2] = min(tr[lson][2], tr[rson][2]);
}

pii query_id(int a, int b, int k, int l, int r)
{
    //printf("query_id(%d,%d,%d,%d,%d)\n", a, b, k, l, r);
    //fflush(stdout);
    if(l >= b || r <= a)return mk(INF, -INF);
    if(l >= a && r <= b)return mk(tr[k][0], tr[k][1]);
    int m = (l+r)>>1;
    pii v1 = query_id(a, b, lson, l, m);
    pii v2 = query_id(a, b, rson, m, r);
    pii ret;
    if(v1.fi == INF)ret.fi = v2.fi;
    else if(v2.fi == INF)ret.fi = v1.fi;
    else ret.fi = beg[v1.fi]<beg[v2.fi]?v1.fi:v2.fi;
    if(v1.se == -INF)ret.se = v2.se;
    else if(v2.se == -INF)ret.se = v1.se;
    else ret.se = beg[v1.se]>beg[v2.se]?v1.se:v2.se;
    return ret;
}

int query_dep(int a, int b, int k, int l, int r)
{
    if(l >= b || r <= a)return INF;
    if(l >= a && r <= b)return tr[k][2];
    int m = (l+r)>>1;
    int v1 = query_dep(a, b, lson, l, m);
    int v2 = query_dep(a, b, rson, m, r);
    //printf("dep[%d,%d)=min(%d,%d)\n", l, r, v1, v2);
    return min(v1, v2);
}

int solve(int l, int r, int k)
{
    printf("solve(%d,%d,%d)\n", l, r, k);
    //pii p = query_id(l, k, 0, 1, n+1);
    //pii q = query_id(k+1, r+1, 0, 1, n+1);
    //printf("p(%d,%d)\n", p.fi, p.se);
    //printf("q(%d,%d)\n", q.fi, q.se);
    int v1 = query_dep(beg[l], beg[k], 0, 1, 2*n);
    int v2 = query_dep(beg[k]+1, beg[r]+1, 0, 1, 2*n);
    printf("v1=%d, v2=%d\n", v1, v2);
    return min(v1, v2);
    //if(p.fi != INF)v1 = query_dep(beg[p.fi], beg[p.se]+1, 0, 1, 2*n);
    //if(q.fi != INF)v2 = query_dep(beg[q.fi], beg[q.se]+1, 0, 1, 2*n);
    //printf("ret=%d\n", min(v1, v2));
    //return min(v1, v2);
}

int main()
{
    sc(n); sc(q);
    for(int i = 2; i <= n; i++){
        int p; sc(p);
        G[p].pb(i);
    }
    dfs(1, 0);
    build_id(0, 1, n+1);
    build_dep(0, 1, 2*n);
    for(int i = 0; i < q; i++){
        int l, r;
        sc(l); sc(r);
        pii id = query_id(l, r+1, 0, 1, n+1);
        printf("(%d,%d)\n", id.fi, id.se);
        int d1 = solve(id.fi, id.se, id.fi), d2 = solve(id.fi, id.se, id.se);
        printf("(%d,%d)\n", d1, d2);
        if(d1 > d2)printf("%d %d\n", id.fi, d1);
        else printf("%d %d\n", id.se, d2);
    }
    return 0;
}

