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
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int maxn = 5e4+10;
char s[maxn];
map<int, int> mp[maxn][4];

void init(int r, int c) {
    for(int i = 0; i <= max(r, c); i++) {
        for(int j = 0; j < 4; j++) {
            mp[i][j].clear();
        }
    }
}

int find(map<int, int> &par, int x) {
    if(par[x] == x)return x;
    else return par[x] = find(par, par[x]);
}

void go(int &x, int &y, int nx, int ny, int dir) {
    if(dir == 0 || dir == 1) {
        if(!mp[ny][dir].count(nx)) {
            x = nx; y = ny;
        }
        else {
            mp[ny][dir][nx] = find(mp[ny][dir], mp[ny][dir][nx]);
            if(dir == 0) {
                x = mp[ny][dir][nx]-1; y = ny;
            }
            else {
                x = mp[ny][dir][nx]+1; y = ny;
            }
        }
    }
    if(dir == 2 || dir == 3) {
        if(!mp[nx][dir].count(ny)) {
            x = nx; y = ny;
        }
        else {
            mp[nx][dir][ny] = find(mp[nx][dir], mp[nx][dir][ny]);
            if(dir == 2) {
                x = nx; y = mp[nx][dir][ny]-1;
            }
            else {
                x = nx; y = mp[nx][dir][ny]+1;
            }
        }
    }

}

void unite(int x, int y) {
    if(mp[y][0].count(x-1)) {
        mp[y][0][x] = x-1;
        mp[y][1][x-1] = x;
    }
    else mp[y][0][x] = x;
    if(mp[y][1].count(x+1)) {
        mp[y][1][x] = x+1;
        mp[y][0][x+1] = x;
    }
    else mp[y][1][x] = x;
    if(mp[x][2].count(y-1)) {
        mp[x][2][y] = y-1;
        mp[x][3][y-1] = y;
    }
    else mp[x][2][y] = y;
    if(mp[x][3].count(y+1)) {
        mp[x][3][y] = y+1;
        mp[x][2][y+1] = y;
    }
    else mp[x][3][y] = y;
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        int n, r, c, x, y;
        scanf("%d%d%d%d%d", &n, &r, &c, &x, &y);
        init(r, c);
        scanf("%s", s);
        for(int i = 0; i < n; i++) {
            unite(x, y);
            int dir = 0;
            if(s[i] == 'N')dir = 0;
            if(s[i] == 'S')dir = 1;
            if(s[i] == 'W')dir = 2;
            if(s[i] == 'E')dir = 3;
            int nx = x+dx[dir], ny = y+dy[dir];
            go(x, y, nx, ny, dir);
            //printf("(%d, %d)\n", x, y);
        }
        printf("Case #%d: %d %d\n", kase++, x, y);
    }
    return 0;
}

