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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6+10;
const int maxlen = 26;
char s[maxn], t[maxn];
struct Node
{
    int nxt[maxn][maxlen], par[maxn], len[maxn];
    int idx, lst;
    void init(int u)
    {
        memset(nxt[u], 0, sizeof(nxt[u]));
        par[u] = len[u] = 0;
    }
    void init()
    {
        idx = lst = 0;
        lst = ++idx;
        init(lst);
    }
    void extend(int c)
    {
        int rt = lst, np = ++idx;
        init(np);
        len[np] = len[rt]+1;
        for(; rt&&!nxt[rt][c]; rt = par[rt])nxt[rt][c] = np;
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
                for(; rt&&nxt[rt][c]==q; rt = par[rt])nxt[rt][c] = nq;
            }
        }
        lst = np;
    }
    void solve()
    {
        int rt = 1, n = strlen(t);
        int ans = 0, now = 0;
        for(int i = 0; i < n; i++){
            int c = t[i]-'a';
            if(nxt[rt][c]) {
                rt = nxt[rt][c];
                now++;
                //printf("rt=%d, now=%d c=%d\n", rt, now, c);
                ans = max(ans, now);
            }
            else{
                while(rt && !nxt[rt][c])rt = par[rt];
                if(nxt[rt][c]){
                    now = len[rt]+1;
                    rt = nxt[rt][c];
                    ans = max(ans, now);
                }
                else{
                    rt = 1;
                    now = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
}SAM;

int main()
{
    scanf("%s%s", s, t);
    int n = strlen(s);
    SAM.init();
    for(int i = 0; i < n; i++){
        SAM.extend(s[i]-'a');
    }
    SAM.solve();
    return 0;
}

