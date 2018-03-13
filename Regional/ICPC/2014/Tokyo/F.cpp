#include <cstdio>
#include <iostream>
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
#include <bitset>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n",x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt","r",stdin)
#define freout freopen("out.txt","w",stdout)
#define PI 3.14159265358979323846
#define debug cout<<"???"<<endl;

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxm = 1e5+10;
const int maxn = 510;
struct edge
{
    int u, v, next;
    ll w;
}es[maxm];
int head[maxn];
bool used[maxm];
bool vis[maxn];
int id[maxn];
ll mincost[maxn];
int pre[maxn];
ll path[maxn][maxn];
int n, m, cnt;

void add_edge(int u, int v, int w)
{
    cnt++;
    es[cnt].u = u, es[cnt].v = v, es[cnt].w = w, es[cnt].next = head[u];
    head[u] = cnt;
    cnt++;
    es[cnt].u = v, es[cnt].v = u, es[cnt].w = w, es[cnt].next = head[v];
    head[v] = cnt;
}

ll prim()
{
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
        mincost[i] = INF64;
        id[i] = 0;
    }
    mincost[1] = 0;
    ll res = 0, cur = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++)if(!vis[i] && mincost[i] != INF && (u == -1 || mincost[i] < mincost[u]))u = i;
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
//                pre[es[i].v] = u;
                id[es[i].v] = i;
            }
        }
//        for(int i = 1; i <= n; i++){
//            if(vis[i] && u != i){
//                if(path[i][u] == mincost[u]){
//
//                }
//                path[i][u] = path[u][i] = max(path[i][pre[u]], );
//            }
//        }
    }
    return res;
}

 ll prim1()
 {
    for(int i = 0; i <= n; i++){
        vis[i] = 0;
        mincost[i] = INF64;
    }
    mincost[1] = 0;
    ll res = 0, cur = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++)if(!vis[i] && mincost[i] != INF64 && (u == -1 || mincost[i] < mincost[u]))u = i;
        if(u == -1)break;
        vis[u] = 1;
        cur++;
        res += mincost[u];
        //printf("res=%lld\n", res);
        //pr(u);
        for(int i = head[u]; i; i = es[i].next){
            if(!vis[es[i].v] && mincost[es[i].v] > es[i].w){
                mincost[es[i].v] = es[i].w;
                //printf("es[%d].w=%lld\n", es[i].v, es[i].w);
                //printf("minocst[%d]=%lld\n", es[i].v, es[i].w);
            }
        }
    }
    if(cur != n)return INF64;
    return res;
 }

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        memset(head, 0, sizeof(head));
        cnt = 0;
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u);sc(v);sc(w);
            add_edge(u, v, w);
        }
        ll ans = prim();
        //printf("ans=%lld\n", ans);
        ll cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= cnt; i += 2){
            if(used[i]){
                ll tmp = es[i].w;
                es[i].w = es[i+1].w = INF64;
                //printf("es[%d].w = es[%d].w = %lld\n", i, i + 1, es[i].w);
                ll now = prim1();
                //printf("now=%lld\n", now);
                //cout << endl;
                if(now > ans){
                    cnt1++;
                    cnt2 += tmp;
                }
                es[i].w = es[i+1].w = tmp;
                //printf("es[%d].w = es[%d].w = %lld\n", i, i + 1, es[i].w);
            }
        }
        //cout << endl;
        printf("%lld %lld\n", cnt1, cnt2);
    }
    return 0;
}
