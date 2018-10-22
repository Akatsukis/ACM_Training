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
const int maxn = 1e2+10;
const int maxs = 16;
int n, m, E, SR, SC, TR, TC;
int mp[maxn][maxn];
int val[maxn][maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
struct Node
{
    int x, y;
    Node(){}
    Node(int x, int y):x(x), y(y){}
};

int solve()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            val[i][j] = -1;
        }
    }
    val[SR][SC] = E;
    queue<Node> q;
    q.push(Node(SR, SC));
    while(!q.empty()){
        Node dt = q.front(); q.pop();
        int x = dt.x, y = dt.y;
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == -100000)continue;
            if(val[nx][ny] < val[x][y]+mp[nx][ny]){
                val[nx][ny] = val[x][y]+mp[nx][ny];
                q.push(Node(nx, ny));
            }
        }
    }
    return val[TR][TC];
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%d%d%d%d%d%d%d", &n, &m, &E, &SR, &SC, &TR, &TC);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sc(mp[i][j]);
            }
        }
        int ans = solve();
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

