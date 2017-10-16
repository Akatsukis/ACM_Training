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
#define pr(x) printf("x:%d\n", x)
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
const int maxn = 1000 + 10;
int n;
int x[maxn];
int y[maxn];
int p[maxn];
double cost[maxn][maxn];
double path[maxn][maxn];
double mincost[maxn];
bool used[maxn][maxn];
bool vis[maxn];
int pre[maxn];

double dist(int id1, int id2)
{
    double res = (x[id1]-x[id2])*(x[id1]-x[id2]) + (y[id1]-y[id2])*(y[id1]-y[id2]);
    return sqrt(res);
}

double prim()
{
    double res = 0;
    fill(mincost, mincost + n + 1, 1.0*INF);
    memset(used, 0, sizeof(used));
    memset(vis, 0, sizeof(vis));
    memset(path, 0, sizeof(path));
    memset(pre, 0, sizeof(pre));
    mincost[1] = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && (u == -1 || mincost[i] < mincost[u])){
                u = i;
            }
        }
        if(u == -1)break;
        vis[u] = 1;
        used[u][pre[u]] = used[pre[u]][u] = 1;
        res += mincost[u];
        for(int i = 1; i <= n; i++){
            if(vis[i] && i != u){
                path[u][i] = path[i][u] = max(path[i][pre[u]], mincost[u]);
            }
            if(!vis[i] && mincost[i] > cost[u][i]){
                mincost[i] = cost[u][i];
                pre[i] = u;
            }
        }
    }
    return res;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 1; i <= n; i++){
            sc(x[i]);sc(y[i]);sc(p[i]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cost[i][j] = dist(i, j);
            }
        }
        double mst = prim();
        double ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(used[i][j]){
                    ans = max(ans, 1.0*(p[i]+p[j])/(mst - cost[i][j]));
                }
                else{
                    ans = max(ans, 1.0*(p[i]+p[j])/(mst - path[i][j]));
                }
            }
        }
         printf("%.2f\n", ans);
    }
	return 0;
}


