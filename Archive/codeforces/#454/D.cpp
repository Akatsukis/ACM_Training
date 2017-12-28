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
const int maxn = 1e5+10;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
set<int> ban[maxn];
vector<vector<int> > ans(maxn);
map<int, int> mp;
int pos[10][10];
int res[10][10];
bool vis[100];
int n, m;
bool flag;

void dfs(int x, int y)
{
    for(int k = 1; k <= n*m; k++){
        if(!vis[k] && !ban[k].count(res[x-1][y]) && !ban[k].count(res[x][y-1])){
            res[x][y] = k;
            vis[k] = 1;
            if(x == n && y == m){
                flag = 1;
                return;
            }
            if(y == m)dfs(x+1, 1);
            else dfs(x, y+1);
            if(flag)return;
            vis[k] = 0;
            res[x][y] = 0;
        }
    }
}


void solve()
{
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            pos[i][j] = ++cnt;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < 4; k++){
                int nx = i+dx[k], ny = j+dy[k];
                if(nx >= 1 && nx <= n && ny >= 1 && ny <= m){
                    ban[pos[i][j]].insert(pos[nx][ny]);
                }
            }
        }
    }
    dfs(1, 1);
    if(flag){
        printf("YES\n");
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                printf("%d%c", res[i][j], j == m ? '\n' : ' ');
            }
        }
    }
    else printf("NO\n");
}

void work()
{
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans[i].pb(++cnt);
        }
    }
    for(int i = 1; i < n; i += 2){
        int a = ans[i][m-2], b = ans[i][m-1];
        for(int j = m-1; j >= 2; j--){
            ans[i][j] = ans[i][j-2];
        }
        ans[i][0] = a, ans[i][1] = b;
    }
    for(int i = 1; i < m; i += 2){
        int a = ans[n-1][i];
        for(int j = n-1; j >= 1; j--){
            ans[j][i] = ans[j-1][i];
        }
        ans[0][i] = a;
    }
}

int main()
{
    sc(n);sc(m);
    if(n == 1 && m >= 5){
        printf("YES\n");
        for(int i = 1; i <= n*m; i += 2){
            printf("%d ", i);
        }
        for(int i = 2; i <= n*m; i += 2){
            printf("%d%c", i, i+2>n*m?'\n':' ');
        }
    }
    else if(n >= 5 && m == 1){
        printf("YES\n");
        for(int i = 1; i <= n*m; i += 2){
            printf("%d\n", i);
        }
        for(int i = 2; i <= n*m; i += 2){
            printf("%d\n", i);
        }
    }
    else if(n >= 2 && m >= 4){
        work();
        printf("YES\n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                 printf("%d%c", ans[i][j], j == m - 1 ? '\n' : ' ');
            }
        }
    }
    else if(n >= 4 && m >= 2){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mp[j*n+i+1] = i*m+j+1;
                //printf("mp[%d]:%d\n", i*m+j+1, j*n+i+1);
            }
        }
        swap(n, m);
        work();
        printf("YES\n");
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                 printf("%d%c", mp[ans[j][i]], j == n - 1 ? '\n' : ' ');
            }
        }
    }
    else solve();
    return 0;
}

