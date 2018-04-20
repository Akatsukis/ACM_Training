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
char s[maxn], ans[maxn];
struct Trie
{
    int nxt[maxn][26], par[maxn], len[maxn], num[maxn];
    int lst, idx;
    int newnode()
    {
        int u = ++idx;
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = num[u] = 0;
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
        len[np] = len[rt]+1;
        for(; rt && !nxt[rt][c]; rt = par[rt])nxt[rt][c] = np;
        if(!rt)par[np] = 1;
        else{
            int q = nxt[rt][c];
            if(len[q] == len[rt]+1)par[np] = q;
            else{
                int nq = ++idx;
                len[nq] = len[rt]+1;
                par[nq] = par[q];
                memcpy(nxt[nq], nxt[q], sizeof(nxt[q]));
                num[nq]= 0;
                par[np] = par[q] = nq;
                for(; rt && nxt[rt][c] == q; rt = par[rt])nxt[rt][c] = nq;
            }
        }
        lst = np;
    }
    void dfs(int u)
    {
        num[u] = 1;
        for(int i = 0; i < 26; i++){
            int v = nxt[u][i];
            if(v){
                if(!num[v])dfs(v);
                num[u] += num[v];
            }
        }
    }
    void solve(int k)
    {
        int rt = 1, t = 0;
        while(k){
            for(int i = 0; i < 26; i++){
                int v = nxt[rt][i];
                if(!v)continue;
                if(k > num[v])k -= num[v];
                else{
                    k--;
                    rt = nxt[rt][i];
                    ans[t++] = 'a'+i;
                    break;
                }
            }   
        }
        ans[t] = 0;
        puts(ans);
    }
}SAM;

int main()
{
    SAM.init();
    scanf("%s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        SAM.extend(s[i]-'a');
    }
    SAM.dfs(1);
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        int k;
        sc(k);
        SAM.solve(k);
    }
    return 0;
}

