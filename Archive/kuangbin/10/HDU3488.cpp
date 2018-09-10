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
const int INF = 0x3f3f3f3f;
const int maxn = 2e2+10;
int G[maxn][maxn];
int dx[maxn], dy[maxn], mat[maxn], pre[maxn], sl[maxn];
bool vis[maxn];
int n, m;

void bfs(int x)
{
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    memset(sl, 0x3f, sizeof(sl));
    int nx = 0, ny = 0;
    mat[ny] = x;
    do{
        nx = mat[ny]; vis[ny] = 1;
        int d = INF, t = 0;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                int cost = dx[nx]+dy[i]-G[nx][i];
                if(cost < sl[i]){
                    sl[i] = cost, pre[i] = ny;
                }
                if(sl[i] < d)d = sl[i], t = i;
            }
        }
        for(int i = 0; i <= n; i++){
            if(vis[i])dx[mat[i]] -= d, dy[i] += d;
            else sl[i] -= d;
        }
        ny = t;
    }while(mat[ny]);
    while(ny)mat[ny] = mat[pre[ny]], ny = pre[ny];
}

int KM()
{
    memset(mat, 0, sizeof(mat));
    memset(dy, 0, sizeof(dy));
    for(int i = 1; i <= n; i++){
        dx[i] = -INF;
        for(int j = 1; j <= n; j++)dx[i] = max(dx[i], G[i][j]);
    }
    for(int i = 1; i <= n; i++)bfs(i);
    int ret = 0;
    for(int i = 1; i <= n; i++)if(mat[i])ret += G[mat[i]][i];
    return ret;
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n); sc(m);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++)G[i][j] = -INF;
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            G[u][v] = max(G[u][v], -w);
        }
        printf("%d\n", -KM());
    }
    return 0;
}
