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
const int maxn = 12;
const int type = 3;
struct node
{
    int x, y, k, t;
    node(){}
    node(int _x, int _y, int _k, int _t):x(_x), y(_y), k(_k), t(_t){}
};
pii dist[maxn][maxn][maxn*maxn][3];
int mp[maxn][maxn];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2, 1, 1, -1, -1, 0, 1, 0, -1};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1, 1, -1, 1, -1, 1, 0, -1, 0};
int n;


bool in(int nx, int ny)
{
    return nx >= 0 && nx < n && ny >= 0 && ny < n;
}

void bfs()
{
    memset(dist, 0x3f, sizeof(dist));
    queue<node> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mp[i][j] == 1){
                for(int k = 0; k < 3; k++){
                    dist[i][j][1][k] = mk(0, 0);
                    q.push(node(i, j, 1, k));
                }
                break;
            }
        }
    }
    while(!q.empty()){
        node u = q.front(); q.pop();
        pii d = dist[u.x][u.y][u.k][u.t];
        if(mp[u.x][u.y] == u.k+1){
            if(dist[u.x][u.y][u.k+1][u.t] > mk(d.fi, d.se)){
                dist[u.x][u.y][u.k+1][u.t] = mk(d.fi, d.se);
                q.push(node(u.x, u.y, u.k+1, u.t));
            }
        }
        for(int i = 0; i < type; i++){
            if(dist[u.x][u.y][u.k][i] > mk(d.fi+1, d.se+1)){
                dist[u.x][u.y][u.k][i] = mk(d.fi+1, d.se+1);
                q.push(node(u.x, u.y, u.k, i));
            }
        }
        if(u.t == 0){
            for(int i = 0; i < 8; i++){
                int nx = u.x+dx[i], ny = u.y+dy[i];
                if(in(nx, ny) && dist[nx][ny][u.k][u.t] > mk(d.fi+1, d.se)){
                    dist[nx][ny][u.k][u.t] = mk(d.fi+1, d.se);
                    q.push(node(nx, ny, u.k, u.t));
                }
            }
        }
        else if(u.t == 1){
            for(int i = 8; i < 12; i++){
                for(int j = 1; j < n; j++){
                    int nx = u.x+dx[i]*j, ny = u.y+dy[i]*j;
                    if(in(nx, ny) && dist[nx][ny][u.k][u.t] > mk(d.fi+1, d.se)){
                        dist[nx][ny][u.k][u.t] = mk(d.fi+1, d.se);
                        q.push(node(nx, ny, u.k, u.t));
                    }
                }
            }
        }
        else if(u.t == 2){
            for(int i = 12; i < 16; i++){
                for(int j = 1; j < n; j++){
                    int nx = u.x+dx[i]*j, ny = u.y+dy[i]*j;
                    if(in(nx, ny) && dist[nx][ny][u.k][u.t] > mk(d.fi+1, d.se)){
                        dist[nx][ny][u.k][u.t] = mk(d.fi+1, d.se);
                        q.push(node(nx, ny, u.k, u.t));
                    }
                }
            }
        }
    }
}

int main()
{
    sc(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)sc(mp[i][j]);
    }
    bfs();
    pii ans = mk(INF, INF);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < type; k++)ans = min(ans, dist[i][j][n*n][k]);
        }
    }
    printf("%d %d\n", ans.fi, ans.se);
    return 0;
}

