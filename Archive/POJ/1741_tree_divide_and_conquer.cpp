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
const int maxn = 1e5 + 10;
int n, k;
vector<vector<pii> > G(maxn);
vector<int> dep;
int f[maxn];//i的最大子树的size
int sum[maxn];//i的size
int vis[maxn];
int d[maxn];
int sz, root, ans;


void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(vis, 0, sizeof(vis));
}

void getroot(int x, int fa)
{
    f[x] = 0, sum[x] = 1;
    for(int i = 0; i < (int)G[x].size(); i++){
        int u = G[x][i].fi;
        if(u != fa && !vis[u]){
            getroot(u, x);
            sum[x] += sum[u];
            f[x] = max(f[x], sum[u]);
        }
    }
    f[x] = max(f[x], sz - sum[x]);//f[x]的上半部分和下半部分的较大值
    if(f[x] < f[root])root = x;
}

void getdep(int x, int fa)
{
    dep.pb(d[x]);
    for(int i = 0; i < (int)G[x].size(); i++){
        int u = G[x][i].fi, w = G[x][i].se;
        if(u != fa && !vis[u]){//未访问过的节点且不是父亲
            d[u] = d[x] + w;
            getdep(u, x);
        }
    }
}

int cal(int x, int st)
{
    dep.clear();
    d[x] = st;
    getdep(x, 0);
    sort(ALL(dep));
    int ans = 0;
    int l = 0, r = (int)dep.size() - 1;
    while(l < r){
        if(dep[l] + dep[r] <= k){
            ans += r - l;
            l++;
        }
        else r--;
    }
    return ans;
}

void solve(int x)
{
    ans += cal(x, 0);vis[x] = 1;
    for(int i = 0; i < (int)G[x].size(); i++){
        int u = G[x][i].fi;
        if(!vis[u]){
            ans -= cal(u, G[x][i].se);//减去ans中同子树同根的部分
            f[0] = sz = sum[u];
            root = 0;
            getroot(u, 0);
            solve(root);
        }
    }
}

void work()
{
    init();
    for(int i = 0; i < n - 1; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].pb(mk(v, w));
        G[v].pb(mk(u, w));
    }
    f[0] = sz = n;
    root = 0;
    getroot(1, 0);
    ans = 0;
    solve(root);
    printf("%d\n", ans);
}

int main()
{
    while(scanf("%d%d", &n, &k) != EOF && (n || k)){
        work();
    }
    return 0;
}


