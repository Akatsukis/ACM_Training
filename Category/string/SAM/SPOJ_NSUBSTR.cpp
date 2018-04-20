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
const int maxn = 5e5+10;
int ans[maxn];
char s[maxn];
struct Trie
{
    int nxt[maxn][26], par[maxn], len[maxn], right[maxn];
    vector<int> son[maxn];
    int lst, idx;
    int newnode()
    {
        int u = ++idx;
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = right[u] = 0;
        return u;
    }
    void init()
    {
        lst = idx = 0;
        lst = newnode();
    }
    void extend(int c)
    {
        int rt = lst, np = newnode();
        right[np] = 1;
        len[np] = len[rt]+1;
        for(; rt && !nxt[rt][c]; rt = par[rt])nxt[rt][c] = np;
        if(!rt)par[np] = 1;
        else{
            int q = nxt[rt][c];
            if(len[q] == len[rt]+1)par[np] = q;
            else{
                int nq = ++idx;
                right[nq] = 0;
                par[nq] = par[q];
                len[nq] = len[rt]+1;
                memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
                par[np] = par[q] = nq;
                for(; rt && nxt[rt][c] == q; rt = par[rt])nxt[rt][c] = nq;
            }
        }
        lst = np;
    }
    void dfs(int u)
    {
        for(auto v : son[u]){
            dfs(v);
            right[u] += right[v];
        }
    }
    void solve()
    {
        for(int i = 2; i <= idx; i++)son[par[i]].pb(i);
        dfs(1);
        //for(int i = 2; i <= idx; i++)printf("right[%d]=%d\n", i, right[i]);
        for(int i = 2; i <= idx; i++)ans[len[i]] = max(ans[len[i]], right[i]);
    }
}SAM;

int main()
{
    SAM.init();
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++)SAM.extend(s[i]-'a');
    SAM.solve();
    for(int i = 1; i <= n; i++)printf("%d\n", ans[i]);
    return 0;
}

