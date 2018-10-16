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
const int maxn = 1e3+10;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char mp[maxn][maxn];
int fire[maxn][maxn], dist[maxn][maxn];
vector<pii> vec;
int n, m;

bool in(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '#';
}

int solve(int u, int v)
{
    memset(fire, 0x3f, sizeof(fire));
    memset(dist, 0x3f, sizeof(dist));
    queue<pii> q;
    for(auto p : vec){
        fire[p.fi][p.se] = 0;
        q.push(mk(p.fi, p.se));
    }
    while(!q.empty()){
        pii p = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = p.fi+dx[i], ny = p.se+dy[i];
            if(in(nx, ny) && fire[nx][ny] > fire[p.fi][p.se]+1){
                fire[nx][ny] = fire[p.fi][p.se]+1;
                q.push(mk(nx, ny));
            }
        }
    }
    dist[u][v] = 0;
    q.push(mk(u, v));
    while(!q.empty()){
        pii p = q.front(); q.pop();
        if(p.fi == 0 || p.fi == n-1 || p.se == 0 || p.se == m-1)return dist[p.fi][p.se]+1;
        for(int i = 0; i < 4; i++){
            int nx = p.fi+dx[i], ny = p.se+dy[i];
            if(in(nx, ny) && dist[nx][ny] > dist[p.fi][p.se]+1 && dist[p.fi][p.se]+1 < fire[nx][ny]){
                dist[nx][ny] = dist[p.fi][p.se]+1;
                q.push(mk(nx, ny));
            }
        }
    }
    return INF;
}

int main()
{
    int T; sc(T);
    while(T--){
        vec.clear();
        sc(n); sc(m);
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", mp[i]);
            for(int j = 0; j < m; j++){
                if(mp[i][j] == 'J')x = i, y = j;
                else if(mp[i][j] == 'F')vec.pb(mk(i, j));
            }
        }
        int ans = solve(x, y);
        if(ans == INF)puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}

