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
const int maxn = 1e5;
vector<vector<int> > G(maxn);
bool flag;

void dfs(int u)
{
    int cnt = 0;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(G[v].size() == 0)cnt++;
        else dfs(v);
    }
    if(G[u].size() && cnt < 3)flag = 0;
}

int main()
{
    int n;
    sc(n);
    for(int i = 2; i <= n; i++){
        int u;
        sc(u);
        G[u].pb(i);
    }
    flag = 1;
    dfs(1);
    if(flag)printf("Yes\n");
    else printf("No\n");
    return 0;
}

