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
const int maxn = 2e2+10;
const int maxm = 3e3+10;
struct edge
{
    int to, cap, nxt;
}es[maxm];
int head[maxn], iter[maxn], lev[maxn];
pii p[maxm];
int deg[maxn];
int cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(deg, 0, sizeof(deg));
}

void add_edge(int u, int v, int cap)
{
    //printf("add(%d,%d,%d)\n", u, v, cap);
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
            edge &e = es[i];
            if(e.cap && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    int ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.cap && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d){
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
                if(ret == f)break;
            }
        }
    }
    if(!ret)lev[v] = 0;
    return ret;
}

int max_flow(int s, int t)
{
    int ret = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        ret += dfs(s, t, INF);
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        init();
        int n, m, num = 0;
        sc(n); sc(m);
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            deg[u]++, deg[v]--;
            if(w != 1)p[num++] = mk(u, v);
        }
        bool flg = 1;
        int src = n+1, dst = src+1;
        for(int i = 1; i <= n; i++){
            if(deg[i]%2 != 0){
                flg = 0;
                break;
            }
            if(deg[i] > 0)add_edge(src, i, deg[i]/2);
            else if(deg[i] < 0)add_edge(i, dst, -deg[i]/2);
        }
        if(!flg){
            puts("impossible");
            continue;
        }
        for(int i = 0; i < num; i++){
            add_edge(p[i].fi, p[i].se, 1);
        }
        max_flow(src, dst);
        for(int i = head[src]; ~i; i = es[i].nxt){
            if(es[i].cap){
                flg = 0;
                break;
            }
        }
        if(flg)puts("possible");
        else puts("impossible");
    }
    return 0;
}

