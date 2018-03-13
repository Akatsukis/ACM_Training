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
const int maxe = 10100;
struct edge
{
    int u, v, nxt;
}es[maxe];
int head[maxn], in[maxn], out[maxn], dfn[maxn], scc[maxn], low[maxn], num;
int n, cnt, idx;
stack<int> S;

void dfs(int u)
{
    dfn[u] = low[u] = ++idx;
    S.push(u);
    for(int i = head[u]; ~i; i = es[i].nxt){
        int v = es[i].v;
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        num++;
        while(1){
            int x = S.top(); S.pop();
            scc[x] = num;
            if(x == u)break;
        }
    }
}

void solve()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i);
    }
    if(num == 1){
        printf("1\n0\n");
        return;
    }
    for(int i = 0; i < cnt; i++){
        if(scc[es[i].u] != scc[es[i].v]){
            out[scc[es[i].u]]++;
            in[scc[es[i].v]]++;
        }   
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= num; i++){
        if(!in[i])ans1++;
        if(!out[i])ans2++;
    }
    ans2 = max(ans1, ans2);
    printf("%d\n%d\n", ans1, ans2);
}

int main()
{
    memset(head, -1, sizeof(head));
    sc(n);
    for(int i = 1; i <= n; i++){
        int k;
        while(sc(k) && k){
            es[cnt].u = i, es[cnt].v = k, es[cnt].nxt = head[i];
            head[i] = cnt++;
        }
    }
    solve();
    return 0;
}
