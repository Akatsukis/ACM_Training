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
const int maxn = 3e3+10;
char s[maxn];
int val[maxn], dp[60][maxn];
string ans[60][maxn];
int n, m;
struct Node
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
            int &v = nxt[rt][s[i]-'a'];
            if(v == -1){
                v = ++idx;
                init(idx);
            }
            rt = nxt[rt][s[i]-'a'];
        }
        last[rt] = id;
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
                    q.push(v);
                }
            }
        }
    }
    void solve()
    {
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= idx; j++)dp[i][j] = -1;
        }
        dp[0][0] = 0;
        ans[0][0] = "";
        string ret;
        int mx = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= idx; j++){
                if(dp[i][j] < 0)continue;
                for(int k = 0; k < 26; k++){
                    int np = nxt[j][k];
                    char c = 'a'+k;
                    string ns = ans[i][j]+c;
                    if(dp[i+1][np] < dp[i][j]+val[last[np]] || (dp[i+1][np] == dp[i][j]+val[last[np]] && ans[i+1][np] > ns)) {
                        dp[i+1][np] = dp[i][j]+val[last[np]];
                        ans[i+1][np] = ns;
                        if(dp[i+1][np] > mx || (dp[i+1][np] == mx && (ret.size() > ans[i+1][np].size() || (ret.size() == ans[i+1][np].size() && ret > ans[i+1][np])))){
                            mx = dp[i+1][np];
                            ret = ans[i+1][np];
                        }
                    }                   
                }
            }
        }
        cout << ret << endl;
    }
}ACAM;

int main()
{
    int T;
    sc(T);
    while(T--){
        scanf("%d%d", &n, &m);
        ACAM.init();
        for(int i = 1; i <= m; i++){
            scanf("%s", s);
            ACAM.insert(i);
        }
        ACAM.get_fail();
        for(int i = 1; i <= m; i++)sc(val[i]);
        ACAM.solve();
    }
    return 0;
}

