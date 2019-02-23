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
char s[maxn][maxn];
int par[maxn*2], dp[maxn*2], deg[maxn*2];
bool vis[maxn*2];
vector<int> G[maxn*2];

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if(x != y)par[x] = y;
}

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 0; i < n+m; i++)par[i] = i;
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
        for(int j = 0; j < m; j++){
            if(s[i][j] == '=')unite(i, j+n);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int u = find(i), v = find(j+n);
            if(s[i][j] == '>'){
                G[v].pb(u);
                deg[u]++;
            }
            else if(s[i][j] == '<'){
                G[u].pb(v);
                deg[v]++;
            }
        }
    }
    queue<int> q;
    for(int i = 0; i < n+m; i++){
        int u = find(i);
        if(!vis[u] && !deg[u]){
            dp[u] = vis[u] = 1;
            q.push(u);
        }
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G[u]){
            dp[v] = max(dp[v], dp[u]+1);
            deg[v]--;
            if(!deg[v])q.push(v);
        }
    }
    bool flg = 1;
    for(int i = 0; i < n+m; i++){
        if(deg[i])flg = 0;
    }
    if(flg){
        puts("Yes");
        for(int i = 0; i < n; i++)printf("%d%c", dp[find(i)], " \n"[i==n-1]);
        for(int i = 0; i < m; i++)printf("%d%c", dp[find(i+n)], " \n"[i==m-1]);
    }
    else puts("No");
    return 0;
}

