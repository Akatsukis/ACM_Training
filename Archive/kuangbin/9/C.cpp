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
const int maxn = 1e5+10;
vector<int> G[maxn];
int dfn[maxn], low[maxn];
int idx, n;
vector<pii> ans;

void init()
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    for(int i = 0; i < n; i++)G[i].clear();
    ans.clear();
    idx = 0;
}

void dfs(int u, int f)
{
    dfn[u] = low[u] = idx++;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > dfn[u]){
                ans.pb(mk(min(u, v), max(u, v)));
            }
        }
        else if(dfn[v] < dfn[u])low[u] = min(low[u], dfn[v]);
    }   
}

void tarjan()
{
    for(int i = 0; i < n; i++){
        if(!dfn[i])dfs(i, -1);
    }
    sort(ALL(ans));
    printf("%d critical links\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d - %d\n", ans[i].fi, ans[i].se);
    }
    printf("\n");
}

int main()
{
    while(sc(n) != EOF){
        init();
        for(int i = 0; i < n; i++){
            int u, v, k;
            scanf("%d %*c%d%*c", &u, &k);
            for(int j = 0; j < k; j++){
                sc(v);
                G[u].pb(v);
            }
        }
        tarjan();
    }
    return 0;
}
