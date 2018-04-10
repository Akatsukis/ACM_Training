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
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e2+10;
const int maxm = 1e2+10;
int dp[maxn][maxm][maxm][4];
char s[maxn];
int n, m;
struct Trie
{
    int nxt[maxn][2], fail[maxn], last[maxn];
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
    void insert(int id)
    {
        int rt = 0, len = strlen(s);
        for(int i = 0; i < len; i++){
            int u = s[i] == 'R'?0:1;
            int &v = nxt[rt][u];
            if(v == -1){
                v = ++idx;
                init(idx);
            }
            rt = nxt[rt][u];
        }
        last[rt] |= id;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        for(int i = 0; i < 2; i++){
            int &v = nxt[rt][i];
            if(v == -1)v = rt;
            else{
                fail[v] = rt;
                q.push(v);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < 2; i++){
                int &v = nxt[u][i], w = fail[u];
                if(v == -1)v = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    if(last[fail[v]])last[v] |= last[fail[v]];
                    q.push(v);
                }
            }
        }
    }
    void solve()
    {
        for(int i = 0; i <= idx; i++){
            for(int j = 0; j <= n; j++){
                for(int k = 0; k <= m; k++){
                    for(int h = 0; h < 4; h++)dp[i][j][k][h] = 0;
                }
            }
        }
        dp[0][0][0][0] = 1;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= idx; k++){
                    for(int h = 0; h < 4; h++){
                        if(!dp[k][i][j][h])continue;
                        for(int v = 0; v < 2; v++){
                            int np = nxt[k][v];
                            int ni = i+(v==0), nj = j+(v==1);
                            if(ni > n || nj > m)continue;
                            dp[np][ni][nj][h|last[np]] += dp[k][i][j][h];
                            dp[np][ni][nj][h|last[np]] %= mod;
                            //printf("dp[%d][%d][%d][%d]=%d\n", np, ni, nj, h|last[np], dp[np][ni][nj][h|last[np]]);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= idx; i++){
            ans = (ans+dp[i][n][m][3])%mod;
        }
        printf("%d\n", ans);
    }
}ACAM;

int main()
{
    int T;
    sc(T);
    while(T--){
        ACAM.init();
        sc(n); sc(m);
        for(int i = 1; i <= 2; i++){
            scanf("%s", s);
            ACAM.insert(i);
        }
        ACAM.get_fail();
        ACAM.solve();
    }
    return 0;
}

