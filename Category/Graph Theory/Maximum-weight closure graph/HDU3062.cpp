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
const int maxn = 2e3+10;
vector<int> G[maxn];
int dfn[maxn], low[maxn], scc[maxn];
stack<int> S;
int idx, cnt;


void init(int n)
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(scc, 0, sizeof(scc));
    idx = cnt = 0;
    for(int i = 0; i <= 2*n; i++)G[i].clear();
}

void dfs(int u)
{
    dfn[u] = low[u] = ++idx;
    S.push(u);
    for(auto v : G[u]){
        if(!dfn[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!scc[v]){
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u]){
        cnt++;
        while(1){
            int x = S.top(); S.pop();
            scc[x] = cnt;
            if(x == u)break;
        }
    }
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        init(n);
        for(int i = 0; i < m; i++){
            int u, v, x, y;
            scanf("%d%d%d%d", &u, &v, &x, &y);
            G[u+x*n].pb(v+(1-y)*n);
            G[v+y*n].pb(u+(1-x)*n);
        }
        for(int i = 0; i < 2*n; i++){
            if(!dfn[i])dfs(i);
        }
        bool flg = 1;
        for(int i = 0; i < n; i++){
            if(scc[i] == scc[i+n]){
                flg = 0;
                break;
            }
        }
        if(flg)puts("YES");
        else puts("NO");
    }
    return 0;
}

