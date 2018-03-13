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
const int maxn = 110;
vector<int> G[maxn];
int dfn[maxn], low[maxn], cut[maxn];
int idx;

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    int cnt = 0;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        if(!dfn[v]){
            cnt++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u])cut[u] = 1;
        }
        if(dfn[v] < dfn[u])low[u] = min(low[u], dfn[v]);
    }
    if(!f && cnt <= 1)cut[u] = 0;
}

int main()
{
    int n;
    while(sc(n) != EOF && n){
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(cut, 0, sizeof(cut));
        for(int i = 0; i <= n; i++)G[i].clear();
        idx = 0;
        int u, v;
        char c;
        while(sc(u) != EOF && u){
            while(scanf("%d%c", &v, &c) != EOF){
                G[u].pb(v);
                G[v].pb(u);
                if(c == '\n')break;
            }
        }
        for(int i = 1; i <= n; i++){
            if(!dfn[i])dfs(i, 0);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(cut[i])ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

