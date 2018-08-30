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
pii a[maxn], b[maxn];
int mat[maxn], vis[maxn];
int G[maxn][maxn];
int n;

bool dfs(int u)
{
    for(int i = 1; i <= n; i++){
        if(G[u][i] && !vis[i]){
            vis[i] = 1;
            if(!mat[i] || dfs(mat[i])){
                mat[i] = u;
                return 1;
            }
        }
    }
    return 0;
}

bool check(int dis)
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(ABS(a[i].fi-b[j].fi)+ABS(a[i].se-b[j].se) <= dis)G[i][j] = 1;
            else G[i][j] = 0;
        }
    }
    memset(mat, 0, sizeof(mat));
    int ret = 0;
    for(int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(i))ret++;
    }
    return ret == n;
}

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++)scanf("%d%d", &a[i].fi, &a[i].se);
    for(int i = 1; i <= n; i++)scanf("%d%d", &b[i].fi, &b[i].se);
    int l = 0, r = INF, ans = 0;
    while(l <= r){
        int m = (l+r)>>1;
        if(check(m)){
            ans = m;
            r = m-1;
        }
        else l = m+1;
    }
    printf("%d\n", ans);
    return 0;
}


