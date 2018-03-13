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
const double eps = 1e-6;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e4+10;
int cost[maxn][maxn];
int mincost[maxn];
int pre[maxn];
bool used[maxn][maxn];
bool vis[maxn];
int n, m;

int prim()
{
    for(int i = 0; i <= n; i++){
        mincost[i] = INF;
        vis[i] = 0;
    }
    int res = 0;
    mincost[1] = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && (u == -1 || mincost[i] < mincost[u]))u = i;
        }
        if(u == -1)break;
        res += mincost[u];
        //printf("res=%lld\n", res);
        vis[u] = 1;
        if(u != 1){
            used[u][pre[u]] = 1;
            used[pre[u]][u] = 1;
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i] && mincost[i] > cost[u][i]){
                mincost[i] = cost[u][i];
                pre[i] = u;
            }
        }
    }
    return res;
}

int prim1()
{
    for(int i = 0; i <= n; i++){
        mincost[i] = INF;
        vis[i] = 0;
    }
    int res = 0;
    int cur = 0;
    mincost[1] = 0;
    while(1){
        int u = -1;
        for(int i = 1; i <= n; i++){
            if(!vis[i] && (u == -1 || mincost[i] < mincost[u]))u = i;
        }
        if(u == -1)break;
        res += mincost[u];
        cur++;
        vis[u] = 1;
        for(int i = 1; i <= n; i++){
            mincost[i] = min(mincost[i], cost[u][i]);
        }
    }
    if(cur != n)return INF;
    return res;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(i == j)cost[i][j] = 0;
                else cost[i][j] = INF;
                used[i][j] = 0;
            }
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u);sc(v);sc(w);
            cost[u][v] = cost[v][u] = min(cost[v][u], w);
        }
        int ans = prim();
        //printf("ans=%lld\n", ans);
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(cost[i][j] != INF && used[i][j]){
                    int tmp = cost[i][j];
                    cost[i][j] = cost[j][i] = INF;
                    int now = prim1();
                    //printf("now=%d\n", now);
                    if(now > ans){
                        cnt1++;
                        cnt2 += tmp;
                    }
                    cost[i][j] = cost[j][i] = tmp;
                }
            }
        }
        printf("%d %d\n", cnt1, cnt2);
    }

    return 0;
}

