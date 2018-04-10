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
#define id(x) (x=='A'?0:x=='T'?1:x=='G'?2:3)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e2+10;
const int maxm = 2e4+10;
int dp[maxn][maxm];
int num[4], bit[4];
char s[maxn];

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
                init(idx);
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
                    if(last[fail[v]])last[v] += last[fail[v]];
                    q.push(v);
                }
            }
        }
    }
    void solve()
    {
        bit[0] = (num[1]+1)*(num[2]+1)*(num[3]+1);
        bit[1] = (num[2]+1)*(num[3]+1);
        bit[2] = num[3]+1;
        bit[3] = 1;
        int m = num[0]*bit[0]+num[1]*bit[1]+num[2]*bit[2]+num[3]*bit[3];
        for(int i = 0; i <= idx; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;
        for(int A = 0; A <= num[0]; A++){
            for(int T = 0; T <= num[1]; T++){
                for(int G = 0; G <= num[2]; G++){
                    for(int C = 0; C <= num[3]; C++){
                        for(int i = 0; i <= idx; i++){
                            int u = A*bit[0]+T*bit[1]+G*bit[2]+C*bit[3];
                            if(dp[i][u] < 0)continue;
                            for(int j = 0; j < 4; j++){
                                if(j == 0 && A == num[0])continue;
                                if(j == 1 && T == num[1])continue;
                                if(j == 2 && G == num[2])continue;
                                if(j == 3 && C == num[3])continue;
                                int np = nxt[i][j];
                                dp[np][u+bit[j]] = max(dp[np][u+bit[j]], dp[i][u]+last[np]);
                                //printf("dp[%d][%d]=%d->dp[%d][%d]=%d\n", i, u, dp[i][u], np, u+bit[j], dp[np][u+bit[j]]);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= idx; i++){
            ans = max(ans, dp[i][m]);
        }
        printf("%d\n", ans);
    }
}ACAM;

int main()
{
    int n, kase = 1;
    while(scanf("%d", &n) != EOF && n){
        memset(num, 0, sizeof(num));
        ACAM.init();
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            ACAM.insert();
        }
        ACAM.get_fail();
        scanf("%s", s);
        int m = strlen(s);
        for(int i = 0; i < m; i++){
            num[id(s[i])]++;
        }
        printf("Case %d: ", kase++);
        ACAM.solve();
    }
    return 0;
}

