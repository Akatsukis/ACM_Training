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
const int maxn = 50+10;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dist[maxn][maxn][maxn], dp[maxn][maxn], opt[maxn];
char s[maxn], mp[maxn][maxn];
int n, m, len;
int rx, ry, ex, ey;
struct Node
{
    int x, y, dis, num;
    Node(int x, int y, int dis, int num):x(x), y(y), dis(dis), num(num){}
    bool operator < (const Node &rhs)const
    {
        return dis>rhs.dis;
    }
};

int encode(char c)
{
    switch(c){
        case 'U':return 0;
        case 'D':return 1;
        case 'L':return 2;
        case 'R':return 3;
    }
    return 0;
}

bool ok(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && mp[x][y] != '#';
}

void solve()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[rx][ry][0] = 0;
    priority_queue<Node> pq;
    pq.push(Node(rx, ry, 0, 0));
    while(!pq.empty()){
        Node tmp = pq.top(); pq.pop();
        int x = tmp.x, y = tmp.y, dis = tmp.dis, num = tmp.num;
        if(dist[x][y][num] < dis)continue;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(num < len && opt[num] == i){
                if(ok(nx, ny)){
                    if(dist[nx][ny][num+1] > dist[x][y][num]){
                        dist[nx][ny][num+1] = dist[x][y][num];
                        pq.push(Node(nx, ny, dis, num+1));
                    }
                }
                else{
                    if(dist[x][y][num+1] > dist[x][y][num]){
                        dist[x][y][num+1] = dist[x][y][num];
                        pq.push(Node(x, y, dis, num+1));
                    }
                }
            }
            else{
                if(ok(nx, ny) && dist[nx][ny][num] > dist[x][y][num]+1){
                    dist[nx][ny][num] = dist[x][y][num]+1;
                    pq.push(Node(nx, ny, dis+1, num));
                }
            }
        }
    }
}

void get_dis()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[ex][ey] = 0;
    queue<pii> q;
    q.push(mk(ex, ey));
    while(!q.empty()){
        pii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = u.fi+dx[i], ny = u.se+dy[i];
            if(ok(nx, ny) && dp[nx][ny] > dp[u.fi][u.se]+1){
                dp[nx][ny] = dp[u.fi][u.se]+1;
                q.push(mk(nx, ny));
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", mp[i]);
        for(int j = 0; j < m; j++){
            if(mp[i][j] == 'R')rx = i, ry = j;
            else if(mp[i][j] == 'E')ex = i, ey = j;
        }
    }
    scanf("%s", s);
    len = strlen(s);
    for(int i = 0; i < len; i++)opt[i] = encode(s[i]);
    solve();
    get_dis();
    int ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k <= len; k++){
                ans = min(ans, dist[i][j][k]+len-k+dp[i][j]);
            }
        }
    }
    for(int i = 0; i <= len; i++)ans = min(ans, dist[ex][ey][i]);
    printf("%d\n", ans);
    return 0;
}
