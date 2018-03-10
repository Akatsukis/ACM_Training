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
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
const int maxe = 20010;
struct edge
{
    int v, w, nxt;
}es[maxe];
int path[maxn][maxn];
bool used[maxe];
int mincost[maxn];
int head[maxn];
bool vis[maxn];
int pre[maxn];
int id[maxn];
int n, m, cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int w)
{
    es[cnt].v = v, es[cnt].w = w, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].v = u, es[cnt].w = w, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

int prim()
{
    memset(vis, 0, sizeof(vis));
    memset(path, 0, sizeof(path));
    memset(mincost, INF, sizeof(mincost));
    memset(used, 0, sizeof(used));
    int ret = 0;
    mincost[1] = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && (u == -1 || mincost[i] < mincost[u]))u = i;
        }
        if(u == -1)break;
        ret += mincost[u];
        vis[u] = 1;
        if(u != 1)used[id[u]] = used[id[u]^1] = 1;
        for(int i = head[u]; ~i; i = es[i].nxt){
            int v = es[i].v, w = es[i].w;
            if(mincost[v] > w){
                mincost[v] = w;
                pre[v] = u;
                id[v] = i;
            }
        }
        for(int i = 0; i < n; i++){
            if(vis[i] && i != u){
                path[u][i] = path[i][u] = max(path[i][pre[u]], mincost[u]);
            }
        }
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        sc(n); sc(m);
        int u, v, w;
        for(int i = 0; i < m; i++){
            sc(u); sc(v); sc(w);
            add_edge(u, v, w);
        }
        int mst = prim();
        bool unq = 1;
        for(int i = 1; i <= n; i++){
            for(int j = head[i]; ~j; j = es[j].nxt){
                if(!used[j]){
                    if(es[j].w == path[i][es[j].v]){
                        unq = 0;
                        break;
                    }
                }
            }
            if(!unq)break;
        }
        if(unq)printf("%d\n", mst);
        else printf("Not Unique!\n");
    }
    return 0;
}

