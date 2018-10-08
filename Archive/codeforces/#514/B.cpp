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
const int maxn = 1e3+10;
char mp[maxn][maxn];
char ans[maxn][maxn];
bool vis[maxn][maxn];
int n, m;

void mark(int x, int y)
{
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(!i && !j)continue;
            int nx = x+i, ny = y+j;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m)vis[nx][ny] = 1;
        }
    }
}


void paint(int x, int y)
{
    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            if(!i && !j)continue;
            int nx = x+i, ny = y+j;
            if(nx >= 0 && nx < n && ny >= 0 && ny < m)ans[nx][ny] = '#';
        }
    }
}

int main()
{
    sc(n); sc(m);
    for(int i = 0; i < n; i++)scanf("%s", mp[i]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == '.')mark(i, j);
            ans[i][j] = '.';
        }
    }
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            if(!vis[i][j])paint(i, j);
        }
    }
    bool flg = 1;
    for(int i = 0; i < n; i++){
        if(strcmp(mp[i], ans[i]))flg = 0;
    }
    if(flg)puts("YES");
    else puts("NO");
    return 0;
}

