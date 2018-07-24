#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define pii pair<int, int> 
#define mk make_pair
#define fi first
#define se second
#define lson k*2+1
#define rson k*2+2
const int mod = 1e9+7;
const int maxn = 1e6+10;
int val[maxn];
int tr[maxn*4], id[maxn*4];
int inv[maxn];
int n, ans;

void init()
{
    inv[1] = 1;
    for(int i = 2; i < maxn; i++)inv[i] = 1LL*(mod-mod/i)*inv[mod%i]%mod;
}

void build(int k, int l, int r)
{
    if(l == r-1){
        tr[k] = val[l];
        id[k] = l;
        return;
    }
    int m = (l+r)/2;
    build(lson, l, m);
    build(rson, m, r);
    tr[k] = max(tr[lson], tr[rson]);
    if(tr[lson] >= tr[rson])id[k] = id[lson];
    else id[k] = id[rson];
}

int query(int a, int b, int k, int l, int r)
{
    //printf("query(%d,%d,%d,%d,%d)\n", a, b, k, l, r);
    if(a >= r || b <= l)return -1;
    else if(a <= l && b >= r)return id[k];
    int m = (l+r)/2;
    int u = query(a, b, lson, l, m);
    int v = query(a, b, rson, m, r);
    if(u == -1)return v;
    else if(v == -1)return u;
    else if(val[u] >= val[v])return u;
    else return v;
}

void dfs(int l, int r)
{
    //printf("dfs(%d,%d)\n", l, r);
    if(l >= r-1)return;
    ans = 1LL*ans*inv[r-l]%mod;
    int m = query(l, r, 0, 0, n);
    dfs(l, m);
    dfs(m+1, r);
}

int main()
{
    int T; sc(T);
    init();
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++)sc(val[i]);
        build(0, 0, n);
        ans = 1LL*n*inv[2]%mod;
        dfs(0, n);
        printf("%d\n", ans);
    }
}
