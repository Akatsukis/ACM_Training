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
char s[11][maxn];
int ans[maxn][11];
struct Trie
{
    int nxt[maxn][26], par[maxn], len[maxn];
    int idx, lst;
    int newnode()
    {
        int u = ++idx;
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = 0;
        return u;
    }
    void init()
    {
        idx = lst = 0;
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
                par[nq] = par[q];
                len[nq] = len[rt]+1;
                memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
                par[np] = par[q] = nq;                
                for(; rt && nxt[rt][c] == q; rt = par[rt])nxt[rt][c] = nq;
            }
        }
        lst = np;
    }
    void solve(char* t, int id)
    {
        int n = strlen(t), rt = 1, now = 0;
        for(int i = 0; i < n; i++){
            while(rt && !nxt[rt][t[i]-'a'])rt = par[rt];
            now = min(now, len[rt]);
            rt = nxt[rt][t[i]-'a'];
            if(rt)now++;
            else rt = 1;
            ans[rt][id] = max(ans[rt][id], now);
        }
        for(int i = idx; i > 0; i--){
            if(ans[i][id]){
                for(int j = par[i]; j && ans[j][id] != len[j]; j = par[j])ans[j][id] = len[j];
            }
        }
    }
}SAM;

int main()
{
    int n = 0;
    while(scanf("%s", s[n]) != EOF)n++;
    SAM.init();
    int len = strlen(s[0]);
    for(int i = 0; i < len; i++){
        SAM.extend(s[0][i]-'a');
    }
    for(int i = 1; i < n; i++)SAM.solve(s[i], i);
    int res = 0;
    for(int i = 2; i <= SAM.idx; i++){
        int now = SAM.len[i];
        for(int j = 1; j < n; j++)now = min(now, ans[i][j]);
        res = max(res, now);
    }
    printf("%d\n", res);
    return 0;
}

