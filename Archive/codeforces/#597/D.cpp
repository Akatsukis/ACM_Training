#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
int par[maxn];
int x[maxn], y[maxn], c[maxn], k[maxn];
struct edge {
    int u, v;
    long long w;
    edge(){}
    edge(int u, int v, long long w): u(u), v(v), w(w){}
    bool operator < (const edge &rhs) const {
        return w < rhs.w;
    }
}es[maxn*maxn+maxn];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x != y) {
        par[x] = y;
        return 1;
    }
    return 0;
}

int main()
{
    int n, m = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
        es[m++] = edge(0, i, c[i]);

    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            es[m++] = edge(i, j, 1LL*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])));
        }
    }
    iota(par, par+n+1, 0);
    sort(es, es+m);
    vector<int> power;
    vector<pair<int, int>> conn;
    long long ans = 0;
    for(int i = 0; i < m; i++) {
        if(unite(es[i].u, es[i].v)) {
            ans += es[i].w;
            if(es[i].u == 0) power.push_back(es[i].v);
            else conn.push_back(make_pair(es[i].u, es[i].v));
        }
    }
    printf("%lld\n", ans);
    printf("%d\n", (int)power.size());
    for(int i = 0; i < (int)power.size(); i++) {
        printf("%d%c", power[i], " \n"[i==(int)power.size()-1]);
    }
    printf("%d\n", (int)conn.size());
    for(int i = 0; i < (int)conn.size(); i++) {
        printf("%d %d\n", conn[i].first, conn[i].second);
    }
    return 0;
}

