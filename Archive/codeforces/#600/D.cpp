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
vector<vector<int>> G;
vector<bool> vis;

void dfs(int u, int &t) {
    vis[u] = 1;
    t = max(u, t);
    for(auto v: G[u]) {
        if(!vis[v]) dfs(v, t);
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vis.resize(n);
    G.resize(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    int s = 0;
    while(s < n) {
        int t = s;
        dfs(s, t);
        for(int i = s; i <= t; i++) {
            if(!vis[i]) {
                ans++;
                dfs(i, t);
            }
        }
        s = t+1;
    }
    printf("%d\n", ans);
    return 0;
}

