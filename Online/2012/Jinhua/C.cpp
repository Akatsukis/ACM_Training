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
#define Abs(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 33;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m, bo, ba, wo, wa;
int cnt;
int vis[maxn][maxn];

void dfs(int x, int y, int step)
{
    vis[x][y] = step;
    if(step == n*m){
        cnt++;
        int a = 0, b = 0, c = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int ret = 0;
                for(int k = 0; k < 4; k++){
                    int nx = i+dx[k], ny = j+dy[k];
                }
                if(ret == 1)a++;
                else if(ret == 2)b++;
                else c++;
            }
        }
        printf("a=%d,b=%d,c=%d\n", a, b, c);
        vis[x][y] = 0;
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
            dfs(nx, ny, step+1);
        }
    }
    vis[x][y] = 0;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && (n||m)){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i, j, 1);
            }
        }
        pr(cnt/8);
    }
    return 0;
}

