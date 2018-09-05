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
const int maxn = 2e4+10;
vector<int> G[maxn];
int mx[maxn], sz[maxn], ans;
vector<int> root;

void dfs(int u, int f)
{
    sz[u] = 1;
    for(auto v :G[u]){
        if(v == f)continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > mx[u])mx[u] = sz[v];
    }
}

void get_ans(int r, int u, int f)
{
    if(sz[r]-sz[u] > mx[u])mx[u] = sz[r]-sz[u];
    if(mx[u] < ans)ans = mx[u], root.clear();
    if(mx[u] == ans)root.pb(u);
    for(auto v : G[u]){
        if(v == f)continue;
        get_ans(r, v, u);
    }
}

int main()
{
    int n; sc(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    ans = n;
    dfs(1, 0);
    get_ans(1, 1, 0);
    printf("%d %d\n", ans, SZ(root));
    for(int i = 0; i < SZ(root); i++){
        printf("%d%c", root[i], " \n"[i==SZ(root)-1]);
    }
    return 0;
}

