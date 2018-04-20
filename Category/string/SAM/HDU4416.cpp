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
struct Trie
{
    int nxt[maxn][26], par[maxn], len[maxn];
    ll num[maxn];
    bool ban[maxn], vis[maxn];
    int lst, idx;
    int newnode()
    {
        int u = ++idx;
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = num[u] = ban[u] = vis[u] = 0;
        return u;
    }
    void init()
    {
        idx = 0;
        lst = newnode();
        ban[lst] = 1;
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
                par[nq] = par[q], num[nq] = ban[nq] = vis[nq] = 0;
                memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
                par[q] = par[np] = nq;
                for(; rt && nxt[rt][c] == q; rt = par[rt])nxt[rt][c] = nq;
            }
        }
        lst = np;
    }
    void solve(char* t)
    {
        int rt = 1, n = strlen(t);
        for(int i = 0; i < n; i++){
        
        }
    }
    void dfs(int u)
    {
        vis[u] = 1;
        if(!ban[u])num[u] = 1;
        for(int i = 0; i < 26; i++){
            int v = nxt[u][i];
            if(!v)continue;
            if(!vis[v])dfs(v);
            num[u] += num[v];
        }
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
        printf("Case %d: %lld\n", kase++, SAM.num[1]);
    }
    return 0;
}

