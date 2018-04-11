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
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 60;
const int maxm = 510;
double x[maxn], y[maxn];
double dp[maxn][maxm];
int n, m;
double dis(int a, int b)
{
    return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));
}
struct Trie
{
    int nxt[maxm][maxn], fail[maxm], last[maxm];
    int idx;
    void init()
    {
        memset(nxt[0], -1, sizeof(nxt[0]));
        fail[0] = last[0] = 0;
        idx = 0;
    }
    void init(int u)
    {
        memset(nxt[u], -1, sizeof(nxt[u]));
        fail[u] = last[u] = 0;
    }
    void insert(const vector<int> &vec)
    {
        int rt = 0, sz = vec.size();
        for(int i = 0; i < sz; i++){
            int &v = nxt[rt][vec[i]];
            if(v == -1){
                v = ++idx;
                init(v);
            }
            rt = nxt[rt][vec[i]];
        }
        last[rt] = 1;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        for(int i = 1; i <= n; i++){
            int &v = nxt[rt][i];
            if(v == -1)v = rt;
            else{
                fail[v] = rt;
                q.push(v);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 1; i <= n; i++){
                int &v = nxt[u][i], w = fail[u];
                if(v == -1)v = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    if(last[fail[v]])last[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    void solve()
    {
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= idx; j++)dp[i][j] = INF64;
        }
        dp[1][nxt[0][1]] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= idx; j++){
                if(dp[i][j] >= INF64)continue;
                for(int k = i+1; k <= n; k++){
                    int np = nxt[j][k];
                    if(last[np])continue;
                    dp[k][np] = min(dp[k][np], dp[i][j]+dis(i, k));
                }
            }
        }
        double ans = INF64;
        for(int i = 0; i <= idx; i++){
            ans = min(ans, dp[n][i]);
        }
        if(ans >= INF64)printf("Can not be reached!\n");
        else printf("%.2f\n", ans);
    }
}ACAM;

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && n){
        ACAM.init();
        for(int i = 1; i <= n; i++){
            scanf("%lf%lf", &x[i], &y[i]);
        }
        for(int i = 0; i < m; i++){
            int k, u;
            sc(k);
            vector<int> vec;
            for(int j = 0; j < k; j++){
                sc(u);
                vec.pb(u);
            }
            ACAM.insert(vec);
        }
        ACAM.get_fail();
        ACAM.solve();
    }
    return 0;
}

