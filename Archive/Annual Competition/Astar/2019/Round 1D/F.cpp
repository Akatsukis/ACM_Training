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
vector<vector<int>> mat;
vector<int> par;
struct Edge {
    int u, v, w;
    Edge(){}
    Edge(int u, int v, int w):u(u), v(v), w(w){}
    bool operator < (const Edge &rhs) const {
        return w > rhs.w;
    }
};

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

bool unite(int x, int y) {
    x = find(x); y = find(y);
    if(x == y)return 0;
    else {
        par[x] = y;
        return 1;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        mat = vector<vector<int>>(n+1, vector<int>(n+1, 0));
        par = vector<int>(n+1, 0);
        for(int i = 0; i < m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            mat[u][v]++, mat[v][u]++;
        }
        bool update = 1;
        while(update && k) {
            update = 0;
            vector<Edge> es;
            for(int i = 1; i <= n; i++) {
                for(int j = i+1; j <= n; j++) {
                    if(mat[i][j])es.push_back(Edge(i, j, mat[i][j]));
                }
            }
            sort(es.begin(), es.end());
            for(int i = 1; i <= n; i++) par[i] = i;
            int cnt = 0;
            for(auto e: es) {
                if(unite(e.u, e.v)) {
                    mat[e.u][e.v]--; mat[e.v][e.u]--;
                    cnt++;
                }
            }
            if(cnt == n-1) {
                update = 1;
                k--;
            }
        }
        if(k)puts("No");
        else puts("Yes");
    }
    return 0;
}

