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
const int maxv = 1040;
const int maxe = 20010;
struct edge
{
    int to, cap, next;
}es[maxe];
int head[maxv];
int iter[maxv];
int lev[maxv];
int kind[maxv];
int cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(kind, 0, sizeof(kind));
}

void add_edge(int from, int to, int cap)
{
    es[cnt].to = to, es[cnt].cap = cap, es[cnt].next = head[from];
    head[from] = cnt++;
    es[cnt].to = from, es[cnt].cap = 0, es[cnt].next = head[to];
    head[to] = cnt++;
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int i = head[v]; ~i; i = es[i].next){
            edge &e = es[i];
            if(e.cap && lev[e.to] < 0){
                lev[e.to] = lev[v]+1;
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
    for(int &i = iter[v]; ~i; i = es[i].next){
        edge &e = es[i];
        if(e.cap && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(f-ret, e.cap));
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
    int flow = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        flow += dfs(s, t, INF);
    }
    return flow;
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int src = (1<<m)+m, dst =src+1;
        int foo;
        for(int i = 0; i < n; i++){
            int num = 0;
            for(int j = 0; j < m; j++){
                sc(foo);
                if(foo)num += 1<<j;
            }
            kind[num]++;
        }
        for(int i = 0; i < (1<<m); i++){
            if(kind[i]){
                add_edge(src, i, kind[i]);
                int num = i, j = 0;
                while(num){
                    if(num%2)add_edge(i, j+(1<<m), INF);
                    num /= 2;
                    j++;
                }
            }
        }
        for(int i = 0; i < m; i++){
            sc(foo);
            if(foo)add_edge(i+(1<<m), dst, foo);
        }
        int ans = max_flow(src, dst);
        if(ans == n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

