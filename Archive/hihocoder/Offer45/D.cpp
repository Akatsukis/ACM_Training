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
const int maxn = 1e6+10;
int x[maxn];
int y[maxn];
int t[maxn];
bool vis[maxn];
int n, m;
vector<int> G[maxn];

bool dfs(int u, int des)
{
    //printf("dfs(%d,%d)\n", u, des);
    vis[u] = 1;
    if(u == des)return 1;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(vis[v])continue;
        if(dfs(v, des))return 1;
    }
    return 0;
}

bool check(int stp)
{
    for(int i = 1; i <= n; i++)G[i].clear();
    for(int i = 1; i <= stp; i++){
        if(t[i])G[x[i]].pb(y[i]);
        else{
            G[x[i]].pb(y[i]);
            G[y[i]].pb(x[i]);
        }
    }
    memset(vis, 0 ,sizeof(vis));
    if(dfs(1, n))return 1;
    memset(vis, 0 ,sizeof(vis));
    if(dfs(n, 1))return 1;
    return 0;
}

int main()
{
    scanf("%d%d ", &n, &m);
    for(int i = 1; i <= m; i++){
        getchar();
        scanf("%d ", &x[i]);
        char s[2];
        scanf("%s ", s);
        if(s[0] == '=')t[i] = 0;
        else t[i] = 1;
        getchar();
        scanf("%d ", &y[i]);
    }
//    for(int i = 0; i < m; i++){
//        printf("%d %d %d", x[i], t[i], y[i]);
//    }
    if(n == 1){
        printf("0\n");
        return 0;
    }
    int l = 1, r = m, ans = INF;
    while(l <= r){
        int m = (l+r)/2;
        if(check(m)){
            r = m-1;
            ans = m;
        }
        else l = m+1;
    }
    if(ans == INF)printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}

