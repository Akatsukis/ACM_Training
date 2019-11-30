#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
constexpr int maxd = 8e2+10;
struct edge {
    int u, v, w;
    edge(){}
    edge(int u, int v, int w): u(u), v(v), w(w) {}
    bool operator < (const edge &rhs) const {
        return w < rhs.w;
    }
}es[maxn];
long long mat[maxd][maxd];

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
    }
    sort(es, es+m);
    map<int, int> mp, rev;
    int idx = 0;
    for(int i = 0; i < k; i++) {
        int u = es[i].u, v = es[i].v;
        if(!mp.count(u)) {
            mp[u] = ++idx;
            rev[idx] = u;
        }
        if(!mp.count(v)) {
            mp[v] = ++idx;
            rev[idx] = v;
        }
    }
    for(int i = 1; i <= idx; i++) {
        for(int j = 1; j <= idx; j++) {
            if(i == j) mat[i][j] = 0;
            else mat[i][j] = 1e18;
        }
    }
    for(int i = 0; i < k; i++) {
        int u = mp[es[i].u], v = mp[es[i].v];
        mat[u][v] = mat[v][u] = min(mat[u][v], 1LL*es[i].w);
    }
    for(int k = 1; k <= idx; k++) {
        for(int i = 1; i <= idx; i++) {
            for(int j = 1; j <= idx; j++) {
                if(mat[i][j] > mat[i][k]+mat[k][j]) {
                    mat[i][j] = mat[i][k]+mat[k][j];
                }
            }
        }
    }
    vector<long long> ans;
    for(int i = 1; i <= idx; i++) {
        for(int j = 1; j <= idx; j++) {
            if(rev[i] < rev[j]) {
                ans.push_back(mat[i][j]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    printf("%lld\n", ans[k-1]);
    return 0;
}

