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
const int maxn = 100;
int mp[maxn][maxn];
bool vis[maxn][maxn];
char s[maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;

void bfs(int x, int y)
{
    vis[x][y] = 1;
    queue<pii> q;
    q.push(mk(x, y));
    while(!q.empty()){
        pii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = u.fi+dx[i], ny = u.se+dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && mp[nx][ny] != 2){
                vis[nx][ny] = 1;
                q.push(mk(nx, ny));
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] == 'L')mp[i][j] = 1;
            else if(s[j] == 'W')mp[i][j] = 2;
            else mp[i][j] = 3;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && mp[i][j] == 1)ans++, bfs(i, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}


