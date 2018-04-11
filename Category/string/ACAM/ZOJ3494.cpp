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
const ll mod = 1000000009;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e3+10;
const int maxm = 2e2+10;
char s[maxn];
int bcd[maxn][10];
int bit[maxn];
int dp[maxn][maxm];
struct Trie
{
    int nxt[maxn][2], fail[maxn], last[maxn];
    int idx;
    void init(int u)
    {
        memset(nxt[u], -1, sizeof(nxt[u]));
        fail[u] = last[u] = 0;
    }
    void init()
    {
        init(0);
        idx = 0;
    }
    void insert()
    {
        int rt = 0, len = strlen(s);
        for(int i = 0; i < len; i++){
            int &v = nxt[rt][s[i]-'0'];
            if(v == -1){
                v = ++idx;
                init(idx);
            }
            rt = nxt[rt][s[i]-'0'];
        }
        last[rt] = 1;
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
                    if(last[fail[v]])last[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    int change(int pre, int num)
    {
        if(last[pre])return -1;
        int cur = pre;
        for(int i = 3; i >= 0; i--){
            if(last[nxt[cur][(num>>i)&1]])return -1;
            cur = nxt[cur][(num>>i)&1];
        }
        return cur;
    }
    void pre_init()
    {
        for(int i = 0; i <= idx; i++){
            for(int j = 0; j < 10; j++){
                bcd[i][j] = change(i, j);
                //printf("bcd[%d][%d]=%d\n", i, j, bcd[i][j]);
            }
        }
        memset(dp, -1, sizeof(dp));
    }
    int dfs(int rt, int pos, bool bound, bool prezero)
    {
        if(pos == -1)return 1;
        if(!bound && dp[rt][pos] != -1)return dp[rt][pos];
        ll ret = 0;
        int to = bound?bit[pos]:9;
        if(prezero){
            ret = (ret+dfs(rt, pos-1, bound && to == 0, 1))%mod;
        }
        else if(bcd[rt][0] != -1){
            ret = (ret+dfs(bcd[rt][0], pos-1, bound && to == 0, 0))%mod;
        }
        for(int i = 1; i <= to; i++){
            if(bcd[rt][i] != -1){
                ret = (ret+dfs(bcd[rt][i], pos-1, bound && i == to, 0))%mod;
            }
        }
        if(!bound && !prezero)dp[rt][pos] = ret;
        return ret;
    }
    int calc()
    {
        int len = strlen(s);
        for(int i = 0; i < len; i++)bit[i] = s[len-1-i]-'0';
        return dfs(0, len-1, 1, 1);
    }
}ACAM;

int main()
{
    int T;
    sc(T);
    while(T--){
        ACAM.init();
        int n;
        sc(n);
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            ACAM.insert();
        }
        ACAM.get_fail();
        ACAM.pre_init();
        int ans = 0;
        scanf("%s", s);
        int len = strlen(s);
        for(int i = len-1; i >= 0; i--){
            if(s[i] > '0'){
                s[i]--;
                break;
            }
            else s[i] = '9';
        }
        ans = (ans-ACAM.calc())%mod;
        scanf("%s", s);
        ans = (ans+ACAM.calc())%mod;
        ans = (ans%mod+mod)%mod;
        printf("%d\n", ans);
    }
    return 0;
}

