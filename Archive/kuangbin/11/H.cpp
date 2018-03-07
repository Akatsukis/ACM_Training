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
const int maxv = 810;
const int maxe = 200010;
struct edge
{
    int to, cap, next;
};
edge es[maxe];
int head[maxv];
int lev[maxv];
int N, F, D, cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int from, int to, int cap)
{
    es[cnt].to = to, es[cnt].cap = cap, es[cnt].next = head[from];
    head[from] = cnt++;
    es[cnt].to = from, es[cnt].cap = 0, es[cnt].next = head[to];
    head[to] = cnt++;
}

void bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        if(v == t)break;
        for(int i = head[v]; ~i; i = es[i].next){
            edge &e = es[i];
            if(e.cap > 0 && lev[e.to] < 0){
                lev[e.to] = lev[v]+1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    int ret = 0;
    for(int i = head[v]; ~i; i = es[i].next){
        edge &e = es[i];
        if(e.cap > 0 && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d > 0){
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
            }
            if(ret == f)break;
        }
    }
    if(!ret)lev[v] = 0;
    return ret;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while(1){
        bfs(s, t);
        if(lev[t] < 0)break;
        flow += dfs(s, t, INF);
    }
    return flow;
}

int main()
{
    while(scanf("%d%d%d", &N, &F, &D) != EOF){
        init();
        int src = 0, dst = 2*N+F+D+1;
        int foo;
        for(int i = 1; i <= N; i++)add_edge(i+F, i+F+N, 1);
        for(int i = 1; i <= F; i++){
            sc(foo);
            if(foo)add_edge(src, i, foo);
        }
        for(int i = 1; i <= D; i++){
            sc(foo);
            if(foo)add_edge(F+2*N+i, dst, foo);
        }
        for(int i = 1; i <= N; i++){
            char s[maxv];
            scanf("%s", s);
            for(int j = 0; j < F; j++){
                if(s[j] == 'Y')add_edge(j+1, i+F, 1);
            }
        }
        for(int i = 1; i <= N; i++){
            char s[maxv];
            scanf("%s", s);
            for(int j = 0; j < D; j++){
                if(s[j] == 'Y')add_edge(i+F+N, F+2*N+j+1, 1);
            }
        }
        int ans = max_flow(src, dst);
        printf("%d\n", ans);
    }
    return 0;
}

