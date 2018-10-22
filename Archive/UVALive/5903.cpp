#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb emplace_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 5e2+10;
const int maxm = 2e5+10;
char mp[maxn][maxn];
int id[maxn][maxn];
int mat[maxm];
bool vis[maxm];
vector<int> G[maxm];
int n, m, uN, vN;

void init()
{
    for(int i = 1; i <= uN; i++)G[i].clear();
}

bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v]){
            vis[v] = 1;
            if(mat[v] == 0 || dfs(mat[v])){
                mat[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

bool allMatch()
{
    memset(mat, 0, sizeof(mat));
    for(int i = 1; i <= uN; i++){
        memset(vis, 0, sizeof(vis));
        if(!dfs(i))return 0;
    }
    return 1;
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n); sc(m);
        int idw = 0, idb = 0;
        for(int i = 1; i <= n; i++){
            scanf("%s", mp[i]+1);
            for(int j = 1; j <= m; j++){
                if(mp[i][j] == 'W')id[i][j] = ++idw;
                if(mp[i][j] == 'B')id[i][j] = ++idb;
            }
        }
        if(idb*2 != idw){
            puts("NO");
            continue;
        }
        uN = idb*2, vN = idw;
        init();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(mp[i][j] == 'B'){
                    if(i-1 >= 1 && mp[i-1][j] == 'W')G[id[i][j]].pb(id[i-1][j]);
                    if(i+1 <= n && mp[i+1][j] == 'W')G[id[i][j]].pb(id[i+1][j]);
                    if(j-1 >= 1 && mp[i][j-1] == 'W')G[id[i][j]+idb].pb(id[i][j-1]);
                    if(j+1 <= m && mp[i][j+1] == 'W')G[id[i][j]+idb].pb(id[i][j+1]);
                }
            }   
        }
        if(allMatch())puts("YES");
        else puts("NO");
    }
    return 0;
}

