#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int n, m, x, y;
const int maxn = 1e3 + 10;
vector<vector<int> > G(maxn);
bool vis[maxn];
int col[maxn];
bool flag;

void dfs(int cur)
{
    for(int i = 0; i < (int)G[cur].size(); i++){
        int u = G[cur][i];
        if(col[u] == col[cur])flag = 0;
        else{
            if(!col[u]){
                col[u] = 3 - col[cur];
                dfs(u);
            }
        }
    }
}

void solve()
{
    for(int i = 1; i <= n; i++){
        if(col[i])dfs(i);
    }
    for(int i = 1; i <= n; i++){
        if(!col[i]){
            col[i] = 1;
            dfs(i);
        }
    }
}

int main()
{
    while(scanf("%d%d%d%d", &n, &m, &x, &y) != EOF){
        memset(vis, 0, sizeof(vis));
        memset(col, 0, sizeof(col));
        flag = 1;
        for(int i = 1; i <= n; i++){
            G[i].clear();
        }
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            vis[u] = 1;
            vis[v] = 1;
            G[u].pb(v);
            G[v].pb(u);
        }
        for(int i = 0; i < x; i++){
            int u;
            scanf("%d", &u);
            vis[u] = 1;
            col[u] = 1;
        }
        for(int i = 0; i < y; i++){
            int u;
            scanf("%d", &u);
            vis[u] = 1;
            col[u] = 2;
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                flag = 0;
                break;
            }
        }
        if(flag)solve();
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}


