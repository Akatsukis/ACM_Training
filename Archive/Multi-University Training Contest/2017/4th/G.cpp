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
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 998244353;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e5+10;
struct edge
{
    int u, v, w, next;
    bool f;
}es[maxn*4];
int deg[maxn*2];
int head[maxn*2];
bool del[maxn*2];
queue<int> q;
ll ans, ans1, ans2;
int cnt, n;

void addedge(int u, int v, int w)
{
    es[cnt].u = u, es[cnt].v = v, es[cnt].w = w, es[cnt].next = head[u], es[cnt].f = 0, head[u] = cnt;
    cnt++;
    es[cnt].u = v, es[cnt].v = u, es[cnt].w = w, es[cnt].next = head[v], es[cnt].f = 0, head[v] = cnt;
    cnt++;
}

void dfs(int u, int f)
{
    del[u] = 1;
    for(int i = head[u]; ~i; i = es[i].next){
        if(es[i].f)continue;
        es[i].f = es[i^1].f = 1;
        if(f)ans1 = ans1*es[i].w%mod;
        else ans2 = ans2*es[i].w%mod;
        dfs(es[i].v, f^1);
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        cnt = 0;
        memset(head, -1, sizeof(head));
        memset(del, 0, sizeof(del));
        memset(deg, 0, sizeof(deg));
        sc(n);
        ans = 1;
        for(int i = 1; i <= n; i++){
            int v1, w1, v2, w2;
            scanf("%d%d%d%d", &v1, &w1, &v2, &w2);
            addedge(i, v1+n, w1);
            addedge(i, v2+n, w2);
            deg[i] += 2;
            deg[v1+n]++;
            deg[v2+n]++;
        }
        for(int i = n+1; i <= 2*n; i++){
            if(deg[i] == 1)q.push(i);
        }
        while(!q.empty()){
            int u = q.front();q.pop();
            del[u] = 1;
            for(int i = head[u]; ~i; i = es[i].next){
                if(es[i].f)continue;
                es[i].f = es[i^1].f = 1;
                int v = es[i].v;
                del[v] = 1;
                ans = (ans*es[i].w)%mod;
                for(int j = head[v]; ~j; j = es[j].next){
                    if(es[j].f)continue;
                    es[j].f = es[j^1].f = 1;
                    deg[es[j].v]--;
                    if(deg[es[j].v] == 1)q.push(es[j].v);
                }
            }
        }
        for(int i = 1; i <= 2*n; i++){
            if(!del[i]){
                ans1 = ans2 = 1;
                dfs(i, 0);
                ans = (ans1+ans2)%mod*ans%mod;
                //printf("sum=%lld\n", ans1+ans2);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

