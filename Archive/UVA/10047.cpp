#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> VI;
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
const int maxn = 1e2+10;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char mp[maxn][maxn];
int dist[maxn][maxn][5][4];
int sx, sy, tx, ty;
int n, m;

bool ok(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '#';
}

vector<int> walk(vector<int> u, int k)
{
    VI ret = u;
    if(!k)ret[0] += dx[ret[3]], ret[1] += dy[ret[3]], ret[2] = (ret[2]+1)%5;
    else ret[3] = (ret[3]+k+4)%4;
    return ret;
}

 int solve()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[sx][sy][0][0] = 0;
    queue<VI> q;
    q.push(VI{sx, sy, 0, 0});
    while(!q.empty()){
        VI u = q.front(); q.pop();
        for(int i = -1; i <= 1; i++){
            VI v = walk(u, i);
            //printf("%d,%d,%d,%d\n", v[0], v[1], v[2], v[3]);
            if(ok(v[0], v[1]) && dist[v[0]][v[1]][v[2]][v[3]] > dist[u[0]][u[1]][u[2]][u[3]]+1){
                dist[v[0]][v[1]][v[2]][v[3]] = dist[u[0]][u[1]][u[2]][u[3]]+1;
                q.push(v);
            }
        }
    }
    int ret = INF;
    for(int i = 0; i < 4; i++)ret = min(ret, dist[tx][ty][0][i]);
    return ret;
}

int main()
{
    int kase = 1, fst = 1;
    while(scanf("%d%d", &n, &m) != EOF && n){
        for(int i = 0; i < n; i++){
            scanf("%s", mp[i]);
            for(int j = 0; j < m; j++){
                if(mp[i][j] == 'S')sx = i, sy = j;
                if(mp[i][j] == 'T')tx = i, ty = j;
            }
        }
        int ans = solve();
        if(fst)fst = 0;
        else puts("");
        printf("Case #%d\n", kase++);
        if(ans == INF)puts("destination not reachable");
        else printf("minimum time = %d sec\n", ans);
    }
    return 0;
}

