#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = 2e5+10;
vector<int> G[maxn];
int rk[maxn], tme[maxn], bg[maxn], ed[maxn];
int root[maxn];
int ls[maxn*30], rs[maxn*30];
long long sum[maxn*30], ans[maxn];
int n, idx, cnt;

void build(int &rt, int l, int r)
{
    rt = ++cnt;
    sum[rt] = 0;
    if(l == r-1)return;
    int m = (l+r)>>1;
    build(ls[rt], l, m); build(rs[rt], m, r);
}

void update(int &rt, int l, int r, int last, int pos, int x)
{
    rt = ++cnt;
    ls[rt] = ls[last], rs[rt] = rs[last]; sum[rt] = sum[last]+x;
    if(l == r-1)return;
    int m = (l+r)>>1;
    if(pos < m)update(ls[rt], l, m, ls[last], pos, x);
    else update(rs[rt], m, r, rs[last], pos, x);
}

long long query(int ss, int tt, int l, int r, int a)
{
    if(l >= a)return 0;
    if(r <= a)return sum[tt]-sum[ss];
    int m = (l+r)>>1;
    long long v1 = query(ls[ss], ls[tt], l, m, a);
    long long v2 = query(rs[ss], rs[tt], m, r, a);
    return v1+v2;
}

void dfs(int u)
{
    bg[u] = ++idx;
    root[idx] = root[idx-1];
    for(auto v : G[u])dfs(v);
    ed[u] = ++idx;
    ans[u] = query(root[bg[u]], root[ed[u]-1], 1, maxn, rk[u]);
    update(root[idx], 1, maxn, root[idx-1], rk[u], tme[u]);
}

int main()
{
    scanf("%d", &n);
    int rt = 0;
    for(int i = 1; i <= n; i++){
        int f;
        scanf("%d%d%d", &f, &rk[i], &tme[i]);
        if(f == -1)rt = i;
        else G[f].pb(i);
    }
    build(root[0], 1, maxn);
    dfs(rt);
    for(int i = 1; i <= n; i++)printf("%lld\n", ans[i]);
}
