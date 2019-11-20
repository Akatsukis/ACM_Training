#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1.5e5+10;
constexpr int threshold = static_cast<int>(sqrt(maxn));
constexpr int mod = 998244353;
vector<int> G[maxn], son[maxn];
int st[maxn], ed[maxn];
int weight[maxn], bit[maxn];
int fa[maxn], sz[maxn];
int idx;
 
int qpow(long long a, int n) {
    long long ret = 1;
    while(n) {
        if(n&1) ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}
 
void dfs(int u) {
    st[u] = ++idx; sz[u] = 1;
    for(auto v: G[u]) {
        if(v == fa[u])continue;
        fa[v] = u;
        dfs(v);
        son[u].push_back(st[v]);
        sz[u] += sz[v];
    }
    ed[u] = idx;
    if(fa[u])G[u].erase(find(G[u].begin(), G[u].end(), fa[u]));
}
 
void upd(int x, int d) {
    if(!x)return;
    for(int i = x; i < maxn; i += i&-i) {
        bit[i] = (bit[i]+d)%mod;
    }
}
 
int qry(int x) {
    int ret = 0;
    for(int i = x; i; i -= i&-i) {
        ret = (ret+bit[i])%mod;
    }
    return ret;
}
 
void rupd(int l, int r, int val) {
    upd(l, val);
    upd(r+1, mod-val);
}
 
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    vector<int> heavy;
    for(int i = 1; i <= n; i++) {
        if(G[i].size() >= threshold) heavy.push_back(i);
    }
    int inv_n = qpow(n, mod-2);
    for(int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            int u, d;
            scanf("%d%d", &u, &d);
            weight[u] = (weight[u]+d)%mod;
            if(G[u].size() < threshold) {
                for(auto v: G[u]) {
                    if(v == fa[u])continue;
                    rupd(st[v], ed[v], 1LL*(n-sz[v])*d%mod*inv_n%mod);
                }
                if(u == 1)continue;
                rupd(1, st[u]-1, 1LL*sz[u]*d%mod*inv_n%mod);
                rupd(ed[u]+1, n, 1LL*sz[u]*d%mod*inv_n%mod);
            }
        }
        else {
            int v;
            scanf("%d", &v);
            int ans = (weight[v]+qry(st[v]))%mod;
            for(auto u: heavy) {
                if(u == v || !weight[u])continue;
                if(st[v] < st[u] || st[v] > ed[u]) {
                    ans = (ans+1LL*sz[u]*weight[u]%mod*inv_n%mod)%mod;
                }
                else {
                    int id = upper_bound(son[u].begin(), son[u].end(), st[v])-son[u].begin()-1;
                    int w = G[u][id];
                    ans = (ans+1LL*(n-sz[w])*weight[u]%mod*inv_n%mod)%mod;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
 
