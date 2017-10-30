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
struct edge
{
    int u, v, next;
}es[maxn*2];
int head[maxn];
int size[maxn];
int maxv[maxn];
bool vis[maxn];
int col[maxn];
ll Hash[maxn];
int root, Max;
ll ans, sum, num;

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
    ans = 0;
}


void addedge(int i, int u, int v)
{
    es[i*2+1].u = u, es[i*2+1].v = v, es[i*2+1].next = head[u];
    head[u] = i*2+1;
    es[i*2+2].u = v, es[i*2+2].v = u, es[i*2+1].next = head[v];
    head[v] = i*2+2;
}

void dfs_size(int u, int f)
{
    size[u] = 1;
    maxv[u] = 0;
    for(int i = head[u]; i; i = es[i].next){
        int v = es[i].v;
        if(v != f && !vis[v]){
            dfs_size(v, u);
            size[u] += size[v];
            maxv[u] = max(maxv[u], size[v]);
        }
    }
}

void dfs_root(int r, int u, int f)
{
    maxv[u] = max(maxv[u], size[r] - size[u]);
    if(Max > maxv[u]){
        Max = maxv[u];
        root = u;
    }
    for(int i = head[u]; i; i = es[i].next){
        int v = es[i].v;
        if(v != f && !vis[v]){
            dfs_root(r, v, u);
        }
    }
}

void dfs_cal(int u, int f, ll d)
{
    Hash[num++] = d;
    sum += col[u];
    for(int i = head[u]; i; i = es[i].next){
        int v = es[i].v;
        if(v != f && !vis[v]){
            dfs_cal(v, u, d + col[u]);
        }
    }
}

ll calc(int u, ll d)
{
    ll res = 0;
    sum = d;
    num = 0;
    dfs_cal(u, u, d);
    for(int i = 0; i < num; i++){
        res += Hash[i];
    }
    return res;
}


void dfs(int u)
{
    Max = n;
    dfs_size(u, 0);
    dfs_root(u, u, 0);
    ans += calc(root, col[root]);
    vis[root] = 1;
    int rt = root;
    for(int i = head[rt]; i; i = es[i].next){
        int v = es[i].v;
        if(!vis[v]){
            ans -= calc(v, col[rt] + col[v]);
            dfs(v);
        }
    }
}


void work()
{
    init();
    for(int i = 1; i <= n; i++){
        sc(col[i]);
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc(u);sc(v);
        addedge(i, u, v);
    }
    ans = 0;
    dfs(1);
    printf("Case #%d: %lld\n", ans);
}

int main()
{
    kase = 1;
    while(scanf("%d", &n) != EOF){
        work();
    }
    return 0;
}


