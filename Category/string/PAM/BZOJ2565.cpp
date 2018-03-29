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
const int maxn = 1e5+10;
char s[maxn];
int mx[maxn];
struct Node
{
    int cnt, state, nxt[maxn][26], fail[maxn], len[maxn], sz[maxn];
    void init()
    {
        memset(nxt, 0 , sizeof(nxt));
        memset(fail, 0, sizeof(fail));
        memset(len, 0 ,sizeof(len));
        memset(sz, 0, sizeof(sz));
        cnt = 1, state = 0;
        fail[0] = fail[1] = 1; len[1] = -1;
    }
    int insert(int ch, int pos)
    {
        int rt = state;
        while(s[pos-len[rt]-1] != s[pos])rt = fail[rt];
        if(!nxt[rt][ch]){
            int v = ++cnt, q = fail[rt]; len[v] = len[rt]+2;
            while(s[pos-len[q]-1] != s[pos])q = fail[q];
            fail[v] = nxt[q][ch];
            nxt[rt][ch] = v;
        }
        state = nxt[rt][ch], sz[state]++;
        return state;
    }
}PAM;

int main()
{
    scanf("%s", s+1);
    PAM.init();
    s[0] = -1;
    int n = strlen(s+1), ans = 0;
    for(int i = 1; i <= n; i++){
        int u = PAM.insert(s[i]-'a', i);
        mx[i] = PAM.len[u];
        while(u^1){
            if(mx[i-PAM.len[u]] >= 1)ans = max(ans, PAM.len[u]+mx[i-PAM.len[u]]);
            u = PAM.fail[u];
        }
        //printf("mx[%d]:%d\n", i, mx[i]);
        if(mx[i-mx[i]] >= 1)ans = max(ans, mx[i]+mx[i-mx[i]]);
    }
    printf("%d\n", ans);
    return 0;
}

