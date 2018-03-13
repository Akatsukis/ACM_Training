#include <bits/stdc++.h>
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
const int maxn = 100100;
int dfn[maxn], low[maxn], scc[maxn], num[maxn];
int in[maxn], out[maxn];
vector<int> G[maxn];
stack<int> S;
int idx, cnt;
int n, m;

void init()
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(scc, 0, sizeof(scc));
    memset(num, 0, sizeof(num));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for(int i = 0; i <= n; i++)G[i].clear();
    idx = cnt = 0;
}

void dfs(int u)
{
    dfn[u] = low[u] = ++idx;
    S.push(u);
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v])low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        cnt++;
        while(1){
            int  x = S.top(); S.pop();
            scc[x] = cnt;
            num[cnt]++;
            if(x == u)break;
        }
    }
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i);
    }
    if(cnt == 1){
        printf("-1\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        int u = scc[i];
        for(int j = 0; j < (int)G[i].size(); j++){
            int v = scc[G[i][j]];
            if(u != v)out[v]++, in[u]++;
        }
    }
    int mn  = INF;
    for(int i = 1; i <= cnt; i++){
        if(!in[i] || !out[i])mn = min(mn, num[i]);
    }
    printf("%lld\n", 1LL*n*(n-1)-m-(n-mn)*mn);
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        printf("Case %d: ", kase++);
        sc(n); sc(m);
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
        }
        tarjan();
    }
    return 0;
}

