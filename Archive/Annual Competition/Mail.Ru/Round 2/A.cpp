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
vector<int> G[maxn];
bool vis[maxn];
int n, s;

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : G[u]){
        if(!vis[v])dfs(v);
    }
}

int main()
{
    scanf("%d%d", &n, &s);
    int pre = 0;
    for(int i = 1; i <= n; i++){
        int x; sc(x);
        if(x){
            if(pre)G[pre].pb(i);
            pre = i;
        }
    }
    pre = 0;
    for(int i = 1; i <= n; i++){
        int x; sc(x);
        if(x){
            if(pre)G[i].pb(pre);
            pre = i;
        }
    }
    dfs(1);
    if(vis[s])puts("YES");
    else puts("NO");
    return 0;
}

