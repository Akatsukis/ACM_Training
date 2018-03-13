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
const int maxn = 5010;
int dfn[maxn], low[maxn], scc[maxn];
int deg[maxn];
vector<int> G[maxn];
stack<int> S;
map<pii, bool> mp;
int idx, cnt;
int n, m;

void dfs(int u, int f)
{
    low[u] = dfn[u] = ++idx;
    S.push(u);
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]){
        cnt++;
        while(1){
            int x = S.top(); S.pop();
            scc[x] = cnt;
            if(x == u)break;
        }
    }
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}

int main()
{
    sc(n); sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u); sc(v);
        if(mp.count(mk(u, v)))continue;
        G[u].pb(v);
        G[v].pb(u);
        mp[mk(u, v)] = mp[mk(v, u)] = 1;
    }
    tarjan();
    for(int i = 1; i <= n; i++){
        int u = scc[i];
        for(int j = 0; j < (int)G[i].size(); j++){
            int v = scc[G[i][j]];
            if(u != v)deg[v]++;
        }
    }
    int ans = 0;
    for(int i = 1; i <= cnt; i++){
        if(deg[i] == 1)ans++;
    }
    printf("%d\n", (ans+1)/2);
    return 0;
}

