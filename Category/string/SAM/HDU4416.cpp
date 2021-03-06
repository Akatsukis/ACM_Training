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
const int maxn = 2e5+10;
char s[maxn];
int ans[maxn];
struct Trie
{
    int nxt[maxn][26], par[maxn], len[maxn];
    int lst, idx;
    int newnode()
    {
        int u = ++idx;
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = ans[u] = 0;
        return u;
    }
    void init()
    {
        idx = 0;
        lst = newnode();
    }
    void extend(int c)
    {
        int rt = lst, np = newnode();
        len[np] = len[rt]+1;
        for(; rt && !nxt[rt][c]; rt = par[rt])nxt[rt][c] = np;
        if(!rt)par[np] = 1;
        else{
            int q = nxt[rt][c];
            if(len[q] == len[rt]+1)par[np] = q;
            else{
                int nq = ++idx;
                len[nq] = len[rt]+1;
                par[nq] = par[q], ans[nq] = 0;
                memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
                par[q] = par[np] = nq;
                for(; rt && nxt[rt][c] == q; rt = par[rt])nxt[rt][c] = nq;
            }
        }
        lst = np;
    }
    void solve(char* t)
    {
        int rt = 1, n = strlen(t), now = 0;
        for(int i = 0; i < n; i++){
            while(rt && !nxt[rt][t[i]-'a'])rt = par[rt];
            now = min(now, len[rt]);
            rt = nxt[rt][t[i]-'a'];
            if(rt)now++;
            else rt = 1;
            ans[rt] = max(ans[rt], now);
        }
    }
    ll calc()
    {
        for(int i = idx; i > 1; i--)if(ans[i]){
            for(int j = par[i]; ans[j] != len[j]; j = par[j])ans[j] = len[j];
        }
        ll ret = 0;
        for(int i = 2; i <= idx; i++){
            if(len[i] > ans[i])ret += len[i]-max(len[par[i]], ans[i]);
        }
        return ret;
    }
}SAM;

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        SAM.init();
        int n;
        sc(n);
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < len; i++)SAM.extend(s[i]-'a');
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            SAM.solve(s);
        }
        ll ret = SAM.calc();
        printf("Case %d: %lld\n", kase++, ret);
    }
    return 0;
}

