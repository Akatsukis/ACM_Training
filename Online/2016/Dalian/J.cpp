#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n",x)
typedef long long ll;
const int maxn = 2e5+10;
int a[maxn], c[maxn];
vector<int> G[maxn];
bool vis[maxn];
int id[maxn], rev[maxn];
int rl[maxn], rr[maxn];
int root[maxn*40], ls[maxn*40], rs[maxn*40], sum[maxn*40];

int idx, cnt;

void init(int n)
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(vis, 0, sizeof(vis));
    idx = cnt = 0;
}

void dfs(int u)
{
    id[u] = ++idx;
    rev[idx] = u;
    rl[u] = idx;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        dfs(v);
    }
    rr[u] = idx;
    //printf("rl[%d],rr[%d]\n", rl[u], rr[u]);
}

void build(int &rt, int l, int r)
{
    rt = ++cnt;
    //printf("build(%d,%d,%d)\n", rt, l, r);
    sum[rt] = 0;
    if(l == r-1)return;
    int m = (l+r)>>1;
    build(ls[rt], l, m);
    build(rs[rt], m, r);
}

void update(int &rt, int l, int r, int last, int val)
{
    rt = ++cnt;
    //printf("udpate(%d,%d,%d,%d,%d)\n", rt, l, r, last, val);
    sum[rt] = sum[last]+1, ls[rt] = ls[last], rs[rt] = rs[last];
    if(l == r-1)return;
    int m = (l+r)>>1;
    if(val < m)update(ls[rt], l, m, ls[last], val);
    else update(rs[rt], m, r, rs[last], val);
}

int query(int ss, int tt, int qval, int l, int r)
{
    //printf("query(%d,%d,%d,%d,%d)\n", ss, tt, qval, l, r);
    if(qval >= r)return sum[tt]-sum[ss];
    if(qval < l)return 0;
    if(l == r-1)return sum[tt]-sum[ss];
    int ret = 0;
    int m = (l+r)>>1;
    ret += query(ls[ss], ls[tt], qval, l, m);
    ret += query(rs[ss], rs[tt], qval, m, r);
    return ret;
}

int main()
{
#ifdef Akatsuki
    //freopen("j.in","r",stdin);
    //freopen("j.out","w",stdout);
#endif // Akatsuki
    int n, T;
    ll k;
    sc(T);
    while(T--){
        scanf("%d%lld", &n, &k);
        init(n);
        for(int i = 1; i <= n; i++)sc(a[i]), c[i] = a[i];
        for(int i = 0; i < n-1; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            vis[v] = 1;
        }
        int rt = 0;
        for(int i = 1; i <= n; i++)if(!vis[i]){
            rt = i;
            break;
        }
        dfs(rt);
        sort(c+1, c+n+1);
        int tot = unique(c+1, c+n+1)-(c+1);
//        for(int i = 1; i <= tot; i++){
//            printf("c[%d]:%d\n", i, c[i]);
//        }
        build(root[0], 1, tot+1);
        for(int i = 1; i <= n; i++){
            //printf("rev[%d]:%d a[%d]:%d\n", i, rev[i], rev[i], a[rev[i]]);
            int val = lower_bound(c+1, c+tot+1, a[rev[i]])-c;
            //printf("val=%d\n", val);
            update(root[i], 1, tot+1, root[i-1], val);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            int ql = rl[rev[i]], qr = rr[rev[i]];
            if(!a[rev[i]]){
                ans += qr-ql;
                continue;
            }
            int qval = upper_bound(c+1, c+tot+1, 1LL*k/a[rev[i]])-(c+1);
            //printf("ql=%d, qr=%d qval=%d\n", ql, qr, qval);
            ans += query(root[ql], root[qr], qval, 1, tot+1);
            //printf("ans=%lld\n", ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
