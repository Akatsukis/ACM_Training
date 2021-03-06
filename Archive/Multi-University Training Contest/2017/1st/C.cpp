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
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5 + 10;
int n, kase;
vector<vector<int> >G(maxn);
bool vis[maxn];
int sum[maxn];
int size[maxn];
int col[maxn];
int cnt;
ll ans;


void init()
{
    cnt = 0;
    memset(vis, 0 ,sizeof(vis));
    memset(sum, 0, sizeof(sum));
}


void dfs(int u, int f)
{
    size[u] = 1;
    int allson = 0;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        int pre = sum[col[u]];
        dfs(v, u);
        size[u] += size[v];
        ll tmp = sum[col[u]] - pre;//以v节点为根的颜色为col[u]的子树的大小的和
        //size[v]-tmp表示以v为根不含col[u]的联通块的大小
        ans -= (ll)(size[v] - tmp) * (ll)(size[v] - tmp - 1) / 2;
        allson += size[v] - tmp;//计算以u为根的颜色不为col[u]的联通块的大小的和
    }
    sum[col[u]] += allson + 1;//加上不为col[u]的联通块的大小和自己，因为颜色为col[u]的子树已计算

}


void work()
{
    init();
    for(int i = 1; i <= n; i++){
        sc(col[i]);
        G[i].clear();
        if(!vis[col[i]]){
            vis[col[i]] = 1;
            cnt++;
        }
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc(u);sc(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    ans = (ll)n * (n - 1) / 2 * cnt;
    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        if(!sum[i])continue;
        ll tmp = n - sum[i];//递归计算时没有计算dfs(1)的贡献，需计算最顶层的联通块的贡献
        ans -= tmp * (tmp - 1) / 2;
    }
    printf("Case #%d: %lld\n", kase++, ans);
}

int main()
{
    kase = 1;
    while(scanf("%d", &n) != EOF){
        work();
    }
    return 0;
}


