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
#define pr(x) cout<< #x"=" << x << endl;
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 6e4+10;
const int maxm = 12;
int path[maxm][maxm];
int dist[maxn];
int dp[1<<maxm][maxm];
char s[maxn];
int n, m;
struct Trie
{
    int nxt[maxn][2], fail[maxn], src[maxn], virus[maxn];
    int idx;
    vector<int> vec;
    void init(int u)
    {
        memset(nxt[u], -1, sizeof(nxt[u]));
        fail[u] = src[u] = virus[u] = 0;
    }
    void init()
    {
        init(0);
        idx = 0;
        vec.clear();
    }
    void insert(int kind)
    {
        int rt = 0, len = strlen(s);
        for(int i = 0; i < len; i++){
            int &v = nxt[rt][s[i]-'0'];
            if(v == -1){
                v = ++idx;
                init(v);
            }
            rt = nxt[rt][s[i]-'0'];
        }
        if(kind != -1)src[rt] |= (1<<kind);
        else virus[rt] = 1;
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
                    src[v] |= src[fail[v]];
                    virus[v] |= virus[fail[v]];
                    q.push(v);
                }
            }
        }
    }
    void bfs(int u)
    {
        memset(dist, -1, sizeof(dist));
        queue<int> q;
        q.push(vec[u]);
        dist[vec[u]] = 0;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int i = 0; i < 2; i++){
                int w = nxt[v][i];
                if(w && !virus[w] && dist[w] == -1){
                    dist[w] = dist[v]+1;
                    q.push(w);
                    //printf("dist[%d]=%d<-dist[%d]=%d\n", w, dist[w], v, dist[v]);
                }
            }
        }
        for(int i = 0; i <= n; i++){
            path[u][i] = dist[vec[i]];
            //printf("path[%d][%d]=%d\n", u, i, path[u][i]);
        }
    }
    void solve()
    {
        vec.pb(0);
        for(int i = 0; i <= idx; i++){
            if(src[i] && !virus[i])vec.pb(i);
        }
        for(int i = 0; i <= n; i++)bfs(i);
        for(int i = 0; i < (1<<n); i++){
            for(int j = 0; j <= n; j++)dp[i][j] = INF;
        }
        dp[0][0] = 0;
        for(int i = 0; i < (1<<n); i++){
            for(int j = 0; j <= n; j++){
                if(dp[i][j] == INF)continue;
                for(int k = 0; k <= n; k++){
                    if(path[j][k] == -1)continue;
                    dp[i|src[vec[k]]][k] = min(dp[i|src[vec[k]]][k], dp[i][j]+path[j][k]); 
                }
            }
        }
        int ans = INF;
        for(int i = 0; i <= n; i++){
            ans = min(ans, dp[(1<<n)-1][i]);
        }
        printf("%d\n", ans);
    }
}ACAM;

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && n){
        ACAM.init();
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            ACAM.insert(i);
        }
        for(int i = 1; i <= m; i++){
            scanf("%s", s);
            ACAM.insert(-1);
        }
        ACAM.get_fail();
        ACAM.solve();
    }
    return 0;
}

