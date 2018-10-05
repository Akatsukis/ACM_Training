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
const int maxn = 2e5+10;
vector<int> G[maxn];
int sz[maxn], dep[maxn];
int n;
ll ans, odd;

void dfs(int u, int f)
{
    dep[u] = dep[f]+1; sz[u] = 1;
    if(dep[u]&1)odd++;
    for(auto v : G[u]){
        if(v == f)continue;
        dfs(v, u);
        sz[u] += sz[v];
        ans += 1LL*sz[v]*(n-sz[v]);
    }
}

int main()
{
    sc(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v); G[v].pb(u);
    }
    dfs(1, 0);
    ans += (n-odd)*odd;
    printf("%lld\n", ans/2);
    return 0;
}

