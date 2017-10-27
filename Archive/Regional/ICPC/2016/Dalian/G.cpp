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
#define fst fi
#define scd se
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
const int maxn = 5e5 + 10;
const int maxk = 10+1;
int n, k;
struct edge
{
    int u, v, next;
}es[maxn * 2];
int col[maxn];
bool vis[maxn];
int size[maxn];
int maxv[maxn];
int sta[maxn];
int head[maxn];
ll Hash[(1<<maxk)];
int Max, root, num;
ll ans;



void addedge(int i, int u, int v)
{
    es[i*2+1].u = u, es[i*2+1].v = v, es[i*2+1].next = head[u];
    head[u] = i*2+1;
    es[i*2+2].u = v, es[i*2+2].v = u, es[i*2+2].next = head[v];
    head[v] = i*2+2;
}

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
    ans = 0;
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
            if(size[v] > maxv[u])maxv[u] = size[v];
        }
    }
}

void dfs_root(int r, int u, int f)
{
    if(size[r] - size[u] > maxv[u])maxv[u] = size[r] - size[u];
    if(maxv[u] < Max)Max = maxv[u], root = u;
    for(int i = head[u]; i; i = es[i].next){
        int v = es[i].v;
        if(v != f && !vis[v]){
            dfs_root(r, v, u);
        }
    }
}

void dfs_sta(int u, int d, int f)
{
    sta[num++] = d;
    for(int i = head[u]; i; i = es[i].next){
        int v  = es[i].v;
        if(v != f && !vis[v]){
            dfs_sta(v, d | (1<<col[v]), u);
        }
    }
}

ll calc(int u, int d)
{
    ll res = 0;
    num = 0;
    dfs_sta(u, d, 0);
    memset(Hash, 0, sizeof(Hash));
    for(int i = 0; i < num; i++)Hash[sta[i]]++;
    for(int i = 0; i < num; i++){
        Hash[sta[i]]--;
        res += Hash[(1 << k) - 1];
        //printf("res=%d\n", res);
        for(int s0 = sta[i]; s0; s0 = (s0-1)&sta[i]){
            res += Hash[((1<<k)-1)^s0];
        }
        Hash[sta[i]]++;
    }
    //printf("res=%d\n", res);
    return res;
}

void dfs(int u)
{
    Max = n;
    dfs_size(u, 0);
    dfs_root(u, u, 0);
    //printf("root=%d\n", root);
    ans += calc(root, (1<<col[root]));
    //printf("ans=%d\n", ans);
    vis[root] = 1;
    for(int i = root; i; i = es[i].next){
        int v = es[i].v;
        if(!vis[v]){
            ans -= calc(v, (1<<col[root])|(1<<col[v]));
            //printf("ans=%d\n", ans);
            dfs(v);
        }
    }
}

void work()
{
    init();
    for(int i = 1; i <= n; i++){
        sc(col[i]);
        col[i]--;
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc(u);sc(v);
        addedge(i, u, v);
    }
    if(k == 1){
        printf("%lld\n", (ll)n * n);
        return;
    }
    dfs(1);
    printf("%lld\n", ans);
}

int main()
{
    while(scanf("%d%d", &n, &k) != EOF){
        work();
    }
    return 0;
}


