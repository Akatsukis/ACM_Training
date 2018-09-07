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
const int maxn =1e4+10;
vector<pii> G[maxn];
int dep[maxn][2];
int mx, root;

void dfs(int u, int f, int t)
{
    if(dep[u][t] > mx){
        mx = dep[u][t];
        root = u;
    }
    for(auto v : G[u]){
        if(v.fi == f)continue;
        dep[v.fi][t] = dep[u][t]+v.se;
        dfs(v.fi, u, t);
    }
}

int main()
{
    int n; sc(n);
    for(int i = 2; i <= n; i++){
        int u, w;
        sc(u); sc(w);
        G[u].pb(mk(i, w));
        G[i].pb(mk(u, w));
    }
    dfs(1, 0, 0);
    mx = dep[root][0] = 0;
    dfs(root, 0, 0);
    mx = dep[root][1] = 0;
    dfs(root, 0, 1);
    for(int i = 1; i <= n; i++){
        printf("%d\n", max(dep[i][0], dep[i][1]));
    }
    return 0;
}

