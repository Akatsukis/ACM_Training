#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
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

int id(char c)
{
    if(islower(c))return c-'a';
    else return c-'A';
}

struct Trie
{
    int nxt[maxn][52], par[maxn], len[maxn], sz[maxn], rev[maxn];
    int lst, idx;
    vector<int> son[maxn];
    int newnode()
    {
        int u = ++idx;
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = ans[u] = sz[u] = rev[u] = 0;
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
        len[np] = len[rt]+1, sz[np] = 1;
        for(; rt && !nxt[rt][c]; rt = par[rt])nxt[rt][c] = np;
        if(!rt)par[np] = 1;
        else{
            int q = nxt[rt][c];
            if(len[q] == len[rt]+1)par[np] = q;
            else{
                int nq = ++idx;
                len[nq] = len[rt]+1, ans[nq] = 0, sz[nq] = 0;
                par[nq] = par[q];
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
            sz[u] += sz[v];
        }
    }
    void solve(char* t)
    {
        for(int i = 0; i <= idx; i++)son[i].clear();
        for(int i = 2; i <= idx; i++)son[par[i]].pb(i);
        dfs(1);
        int rt = 1, now = 0, n = strlen(t);
        for(int i = 0; i < n; i++){
            while(rt && !nxt[rt][id(t[i])])rt = par[rt];
            now = min(now, len[rt]);
            rt = nxt[rt][id(t[i])];
            if(rt)now++;
            else rt = 1;
            if(now >= k)
            ans[rt] = max(ans[rt], now);
        }
        for(int i = idx; i > 1; i--)if(ans[i]){
            for(int j = par[i]; ans[j] != len[j]; j = par[j])ans[j] = len[j];
        }
    }
    ll calc(int k)
    {
        ll ret = 0;
        for(int i = 2; i <= idx; i++)printf("ans[%d]=%d\n", i ,ans[i]);
        for(int i = 2; i <= idx; i++){
            if(len[par[i]]+1 >= k && ans[i] >= k)ret +=  sz[i]*(ans[i]-len[par[i]]), pr(sz[i]);
        }
        return ret;
    }
}SAM;

int main()
{
    int k;
    while(scanf("%d", &k) != EOF && k){
        SAM.init();
        scanf("%s", s);
        int n = strlen(s);
        for(int i = 0; i < n; i++)SAM.extend(id(s[i]));
        scanf("%s", s);
        SAM.solve(s);
        ll ans = SAM.calc(k);
        printf("%lld\n", ans);
    }
    return 0;
}

