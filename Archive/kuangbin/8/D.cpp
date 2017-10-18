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
const int maxm = 400 + 10;
int cnt;
struct edge
{
    int u, v, w, next;
}es[maxm];
int head[maxn];
bool used[maxm];
bool vis[maxn];
int id[maxn];
int mincost[maxn];
int pre[maxn];
int path[maxn][maxn];
int n, m;



void add_edge(int u, int v, int w)
{
    cnt++;
    es[cnt].u = u, es[cnt].v = v, es[cnt].w = w, es[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
    es[cnt].u = v, es[cnt].v = u, es[cnt].w = w, es[cnt].next = head[v];
    head[v] = cnt;
}

int prim()
{
    memset(mincost, INF, sizeof(mincost));
    memset(vis, 0, sizeof(vis));
    memset(used, 0, sizeof(used));
    memset(id, 0, sizeof(id));
    memset(pre, 0, sizeof(pre));
    mincost[1] = 0;
    int res = 0, cur = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && mincost[i] != INF && (u == -1 || mincost[i] < mincost[u]))u = i;
        }
        if(u == -1)break;
        vis[u] = 1;
        if(u != 1){
            if(id[u] % 2){
                used[id[u]] = used[id[u] + 1] = 1;
            }
            else{
                used[id[u]] = used[id[u] - 1] = 1;
            }
        }
        cur++;
        res += mincost[u];
        for(int i = head[u]; i; i = es[i].next){
            if(!vis[es[i].v] && mincost[es[i].v] > es[i].w){
                mincost[es[i].v] = es[i].w;
                pre[es[i].v] = u;
                id[es[i].v] = i;
            }
        }
        for(int i = 1; i <= n; i++){
            if(vis[i] && u != i){
                path[i][u] = path[u][i] = max(path[i][pre[u]], mincost[u]);
            }
        }
    }
    //cout << cur << endl;
    if(cur != n)return INF;
    return res;
}


void work()
{
    sc(n);sc(m);
    memset(head, 0, sizeof(head));
    cnt = 0;
    for(int i = 0; i < m; i++){
        int u, v, w;
        sc(u);sc(v);sc(w);
        add_edge(u, v, w);
    }
    int ans1, ans2 = INF;
    ans1 = prim();
    if(ans1 == INF){
        printf("No way\n");
        return;
    }
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= n; j++){
//            printf("%d%c", path[i][j], j == n ? '\n' : ' ');
//        }
//    }
//    for(int i = 1; i <= cnt; i++){
//        printf("%d%c", used[i], i == cnt ? '\n' : ' ');
//    }
    for(int i = 1; i <= cnt; i++){
        if(!used[i]){
            ans2 = min(ans2, ans1 - path[es[i].u][es[i].v] + es[i].w);
        }
    }
    if(ans2 == INF){
        printf("No second way\n");
        return;
    }
    else{
        printf("%d\n", ans2);
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        printf("Case #%d : ", kase++);
        work();
    }
	return 0;
}


