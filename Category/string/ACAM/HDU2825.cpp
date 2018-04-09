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
const int mod = 20090717;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
int dp[maxn][maxn][1<<11];
char s[maxn];
int n, m, k;

int check(int x)
{
    int ret = 0;
    while(x){
        ret++;
        x -= x&(-x);
    }
    return ret;
}

struct ACAM
{
    int nxt[maxn][26], fail[maxn], last[maxn];
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
        int rt = 0, n = strlen(s);
        for(int i = 0; i < n; i++){
            int u = s[i]-'a';
            int &v = nxt[rt][u];
            if(v == -1){
                v = ++idx;
                init(idx);
            }
            rt = nxt[rt][u];
        }
        last[rt] |= (1<<id);
    }
    void get_fail()
    {
        queue<int> q;
        int rt = 0;
        for(int i = 0; i < 26; i++){
            int &v = nxt[rt][i];
            if(v == -1)v = rt;
            else{
                fail[v] = rt;
                q.push(v);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0; i < 26; i++){
                int &v = nxt[u][i], w = fail[u];
                if(v == -1)v = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    last[v] |= last[fail[v]];
                    q.push(v);
                }
            }
        }
    }
    int solve()
    {
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= idx; j++){
                for(int h = 0; h < (1<<m); h++)dp[i][j][h] = 0;
            }
        }
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= idx; j++){
                for(int h = 0; h < (1<<m); h++){
                    if(!dp[i][j][h])continue;
                    for(int v = 0; v < 26; v++){
                        int np = nxt[j][v];
                        dp[i+1][np][last[np]|h] += dp[i][j][h];
                        dp[i+1][np][last[np]|h] %= mod;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < (1<<m); i++){
            if(check(i) < k)continue;
            for(int j = 0; j <= idx; j++){
                ans = (ans+dp[n][j][i])%mod;
            }
        }
        return ans;
    }
}ACAM;

int main()
{
    while(scanf("%d%d%d", &n, &m, &k) != EOF && n){
        ACAM.init();
        for(int i = 0; i < m; i++){
            scanf("%s", s);
            ACAM.insert(i);
        }
        ACAM.get_fail();
        int ans = ACAM.solve();
        printf("%d\n", ans);
    }
    return 0;
}

