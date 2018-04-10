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
#define id(x) (x=='A'?0:x=='T'?1:x=='G'?2:3)
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3+10;
char s[maxn];
int dp[maxn][maxn];
struct Trie
{
    int nxt[maxn][4], fail[maxn], last[maxn];
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
    void insert()
    {
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int u = id(s[i]);
            int &v = nxt[rt][u];
            if(v == -1){
                v = ++idx;
                init(v);
            }
            rt = nxt[rt][u];
        }
        last[rt]++;
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        for(int i = 0; i < 4; i++){
            int &v = nxt[rt][i];
            if(v == -1)v = rt;
            else{
                fail[v] = rt;
                q.push(v);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
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
        int n = strlen(s);
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= idx; j++)dp[i][j] = INF;
        }
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= idx; j++){
                if(dp[i][j] == INF)continue;
                for(int k = 0; k < 4; k++){
                    int np = nxt[j][k];
                    if(last[np])continue;
                    if(id(s[i]) == k)dp[i+1][np] = min(dp[i+1][np], dp[i][j]);
                    else dp[i+1][np] = min(dp[i+1][np], dp[i][j]+1);
                } 
            }
        }
        int ans = INF;
        for(int i = 0; i <= idx; i++){
            ans = min(ans, dp[n][i]);
        }
        if(ans == INF)printf("-1\n");
        else printf("%d\n", ans);
    }
}ACAM;

int main()
{
    int n, kase = 1;
    while(scanf("%d", &n) != EOF && n){
        ACAM.init();
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            ACAM.insert();
        }
        ACAM.get_fail();
        scanf("%s", s);
        printf("Case %d: ", kase++);
        ACAM.solve();
    }
    return 0;
}

