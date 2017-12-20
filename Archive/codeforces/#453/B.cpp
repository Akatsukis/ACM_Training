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
const int maxn = 1e4+10;
vector<vector<int> > G(maxn);
int col[maxn];
int ans;

void dfs(int u, int c, int f)
{
    if(col[u] != c)ans++;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        dfs(v, col[u], u);
    }
}

int main()
{
    int n;
    sc(n);
    for(int i = 2; i <= n; i++){
        int u;
        sc(u);
        G[u].pb(i);
        G[i].pb(u);
    }
    for(int i = 1; i <= n; i++){
        sc(col[i]);
    }
    dfs(1, 0, -1);
    printf("%d\n", ans);
    return 0;
}

