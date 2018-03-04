#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
int mp[maxn][maxn];
int cost[maxn][maxn][maxn][2];
int n;
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int pow2[maxn];
struct Node
{
    int x, y, cnt, dir;
};

void init()
{
    pow2[0] = 1;
    for(int i = 1; i < 64; i++)pow2[i] = pow2[i-1]*2;
}

int bfs()
{
    memset(cost, 0x3f3f3f3f, sizeof(cost));
    queue<Node> q;
    q.push({1, 0, 0, 0});
    q.push({0, 1, 0, 1});
    cost[0][0][0][0] = cost[0][0][0][1] = mp[0][0];
    cost[1][0][0][0] = mp[0][0]+mp[1][0];
    cost[0][1][0][1] = mp[0][0]+mp[0][1];
    int ans = INF;
    while(q.size()){
        Node now = q.front(); q.pop();
        int x = now.x, y = now.y, cnt = now.cnt, dir = now.dir;
        if(x == n-1 && y == n-1){
            ans = min(ans, cost[x][y][cnt][dir]);
        }
        if(cost[x][y][cnt][dir] >= ans || cnt > 18)continue;
        int nx, ny;
        nx = x+dx[dir], ny = y+dy[dir];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(cost[nx][ny][cnt][dir] > cost[x][y][cnt][dir]+mp[nx][ny]){
                cost[nx][ny][cnt][dir] = cost[x][y][cnt][dir]+mp[nx][ny];
                q.push({nx, ny, cnt, dir});
            }
        }
        int ndir = (dir+1)%2;
        nx = x+dx[ndir], ny = y+dy[ndir];
        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
            if(cost[nx][ny][cnt+1][ndir] > cost[x][y][cnt][dir]+mp[nx][ny]+pow2[cnt]){
                cost[nx][ny][cnt+1][ndir] = cost[x][y][cnt][dir]+mp[nx][ny]+pow2[cnt];
                q.push({nx, ny, cnt+1, ndir});
            }
        }
    }
    return ans;
}


int main()
{
    init();
    sc(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sc(mp[i][j]);
        }
    }
    if(n == 1){
        printf("%d\n", mp[0][0]);
        return 0;
    }
    int ans = bfs();
    printf("%d\n", ans);
    return 0;
}

