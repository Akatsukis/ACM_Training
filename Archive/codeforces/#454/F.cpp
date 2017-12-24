#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100;
bool vis[maxn*maxn];
int ans[maxn][maxn];
bool flag;

void dfs(int x, int y, int n, int m)
{
    if(flag)return;
    for(int i = 1; i <= n*m; i++){
        if(!vis[i] && ans[x-1][y] != i && ans[x][y-1] != i){
            ans[x][y] = 1;
            vis[i] = 1;
            if(x == n && y == m){
                flag = 1;
                return;
            }
            else if(x == n){
                dfs(1, y+1, n, m);
            }
            else dfs(x+1, y, n, m);
            if(flag)return;
            ans[x][y] = 0;
            vis[i] = 0;
        }
    }
}

void solve(int n, int m)
{
    flag = 0;
    memset(ans, 0, sizeof(ans));
    memset(vis, 0, sizeof(vis));
    dfs(1, 1, n, m);
    printf("n=%d m=%d\n", n, m);
    if(flag){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                printf("%d%c", ans[i][j], j == m ? '\n' : ' ');
            }
        }
    }
    else{
        printf("-1\n");
    }
}

int main()
{
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            solve(i, j);
        }
    }
    return 0;
}

