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
const int maxn = 70;
const int maxs = 520;
vector<int> G[maxn];
double dp[maxn][maxs];
double sum[maxs];
double tmp[maxs];
double p;
int N, L, S;

void init()
{
    for(int i = 0; i < maxn; i++)G[i].clear();
    memset(dp, 0, sizeof(dp));
}

void dfs(int u, int f)
{
    dp[u][0] = 1;
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        dfs(v, u);
        memset(sum, 0, sizeof(sum));
        memset(tmp, 0, sizeof(tmp));
        for(int j = 0; j <= L; j++){
            for(int k = 0; j+k<= S; k++){
                sum[j+k] += p*dp[v][k];
            }
        }
        for(int j = 0; j <= S; j++){
            for(int k = 0; j+k <= S; k++){
                tmp[max(j, k)] += dp[u][j]*sum[k];
            }
        }
        for(int j = 0; j <= S; j++)dp[u][j] = tmp[j];
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        init();
        sc(N); sc(L); sc(S);
        p = 1.0/(L+1);
        for(int i = 1; i < N; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1, 0);
        double ans = 0;
        for(int i = 0; i <= S; i++){
            ans += dp[1][i];
        }
        printf("Case %d: %.6f\n", kase++, ans);
    }
    return 0;
}

