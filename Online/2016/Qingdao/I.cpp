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
vector<pii> G[maxn];
int dist[maxn];
bool dia[maxn];
int res[maxn][3][2];
int dep[maxn][2];
int src, dst;

void init(int n)
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(dist, 0, sizeof(dist));
    memset(dia, 0, sizeof(dia));
    memset(res, 0, sizeof(res));
    memset(dep, 0, sizeof(dep));
}

bool dfs1(int u, int f)
{
    if(u == dst)dia[u] = 1;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i].fi;
        if(v == f)continue;
        dist[v] = dist[u]+G[u][i].se;
        if(dfs1(v, u))dia[u] = 1;
    }
    return dia[u];
}

void dfs2(int u, int f, int t)
{
    dep[u][t] = dep[f][t]+1;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i].fi, w = G[u][i].se;
        if(v == f)continue;
        dfs2(v, u, t);
        int tmp = res[v][1][t]+w;
        if(tmp > res[u][1][t]){
            res[u][2][t] = res[u][1][t];
            res[u][1][t] = tmp;
        }
        else if(tmp > res[u][2][t])res[u][2][t] = tmp;
        res[u][0][t] = max(res[u][0][t], res[v][0][t]);
    }
    res[u][0][t] = max(res[u][0][t], res[u][1][t]+res[u][2][t]);
    //printf("dep[%d][%d]:%d\n", u, t, dep[u][t]);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        int n;
        sc(n);
        init(n);
        for(int i = 1; i < n; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb(mk(v, w));
            G[v].pb(mk(u, w));
        }
        src = 1, dst = 0;
        dfs1(src, 0);
        for(int i = 1; i <= n; i++)if(dist[i] > dist[src])src = i;
        dist[src] = 0;
        dfs1(src, 0);
        for(int i = 1; i <= n; i++)if(dist[i] > dist[dst])dst = i;
        dist[src] = 0;
        dfs1(src, 0);
        dfs2(src, 0, 0);
        dfs2(dst, 0, 1);
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < (int)G[i].size(); j++){
                int v = G[i][j].fi;
                if(!dia[i] || !dia[v])ans += dist[dst];
                else{
                    if(dep[i][0] > dep[v][0])ans += max(res[i][0][0], res[v][0][1]);
                    else ans += max(res[i][0][1], res[v][0][0]);
                    //printf("u=%d, v=%d, ans=%lld\n", i, v, ans);
                }
            }
        }
        printf("%lld\n", ans/2);

    }
    return 0;
}

