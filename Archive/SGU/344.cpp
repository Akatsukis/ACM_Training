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
int tot[maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    int n, m;
    sc(n); sc(m);
    queue<pii> q;
    for(int i = 0; i < n; i++){
        scanf("%s", mp[i]);
        for(int j = 0; j < m; j++){
            if(mp[i][j] == 'X')q.push(mk(i, j));
        }
    }
    while(!q.empty()){
        pii u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = u.fi+dx[i], ny = u.se+dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] == '.'){
                tot[nx][ny]++;
                if(tot[nx][ny] >= 2){
                    mp[nx][ny] = 'X';
                    q.push(mk(nx, ny));
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)if(mp[i][j] == 'X')ans++;
    }
    printf("%d\n", ans);
    return 0;
}

