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
const ll INF = 0x3f3f3f3f;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100 + 10;
int n, m;
int cost[maxn][maxn];
int mincost[maxn];
int pre[maxn];
bool vis[maxn];
bool used[maxn][maxn];
int path[maxn][maxn];

int prim()
{
    memset(mincost, INF, sizeof(mincost));
    memset(path, 0, sizeof(path));
    memset(vis, 0, sizeof(vis));
    memset(used, 0 ,sizeof(used));
    memset(pre, 0, sizeof(pre));
    int res = 0;
    mincost[1] = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && (u == -1 || mincost[i] < mincost[u]))u = i;
        }
        if(u == -1)break;
        vis[u] = 1;
        used[u][pre[u]] =  used[pre[u]][u] = 1;
        res += mincost[u];
        //printf("mincost[%d]:%d\n", u, mincost[u]);
        for(int i = 1; i <= n; i++){
            if(!vis[i] && mincost[i] > cost[u][i]){
                mincost[i] = cost[u][i];
                pre[i] = u;
            }
            if(vis[i] && i != u){
                path[i][u] = path[u][i] = max(path[i][pre[u]], mincost[u]);
            }
        }
    }
    return res;
}

void work()
{
    sc(n);sc(m);
    memset(cost, INF, sizeof(cost));
    for(int i = 1; i <= m; i++){
        int u, v, w;
        sc(u);sc(v);sc(w);
        cost[u][v] = cost[v][u] = w;
    }
    int ans1, ans2 = INF;
    ans1 = prim();
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            printf("%d%c", path[i][j], j == n ? '\n' : ' ');
//        }
//    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j || cost[i][j] == INF)continue;
            if(!used[i][j]){
                ans2 = min(ans2, ans1 - path[i][j] + cost[i][j]);
            }
        }
    }
    printf("%d %d\n", ans1, ans2);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        work();
    }
	return 0;
}


