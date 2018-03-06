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
#define sc(x) scanf("%d ", &x)
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
struct es
{
    int to, cap, rev;
};
vector<es> G[maxn];
int lev[maxn];
int iter[maxn];

void init()
{
    for(int i = 0; i < maxn; i++)G[i].clear();
}

void add_edge(int from, int to, int cap)
{
    //printf("add(%d,%d,%d)\n", from, to, cap);
    G[from].pb((es){to, cap, (int)G[to].size()});
    G[to].pb((es){from, 0, (int)G[from].size()-1});
}

void bfs(int s)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int i = 0; i < (int)G[v].size(); i++){
            es &e = G[v][i];
            if(e.cap > 0 && lev[e.to] < 0){
                lev[e.to] = lev[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    for(int &i = iter[v]; i < (int)G[v].size(); i++){
        es &e = G[v][i];
        if(e.cap > 0 && lev[e.to] > lev[v]){
            int d = dfs(e.to, t, min(e.cap, f));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while(1){
        bfs(s);
        if(lev[t] < 0)break;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0)flow += f;
    }
    return flow;
}

int main()
{
    int n, np, nc, m;
    while(scanf("%d%d%d%d ", &n, &np, &nc, &m) != EOF){
        init();
        int src = n, dst = n+1;
        int u, v, w;
        for(int i = 0; i < m; i++){
            getchar(); sc(u);
            getchar(); sc(v);
            getchar(); sc(w);
            add_edge(u, v, w);
        }
        for(int i = 0; i < np; i++){
            getchar(); sc(u);
            getchar(); sc(w);
            add_edge(src, u, w);
        }
        for(int i = 0; i < nc; i++){
            getchar(); sc(v);
            getchar(); sc(w);
            add_edge(v, dst, w);
        }
        int ans = max_flow(src, dst);
        printf("%d\n", ans);
    }
    return 0;
}

