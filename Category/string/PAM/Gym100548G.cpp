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
const int maxn = 4e5+10;
char s[maxn], t[maxn];
ll ans;
struct Node
{
    int cnt, state, nxt[maxn][26], len[maxn], sz[maxn][2], fail[maxn];
    void init()
    {
        memset(nxt, 0, sizeof(nxt));
        memset(len, 0, sizeof(len));
        memset(sz, 0, sizeof(sz));
        memset(fail, 0, sizeof(fail));
        fail[0] = fail[1] = 1; len[1] = -1;
        cnt = 1, state = 0;
    }
    void insert(int x, int pos, char* ch, int id)
    {
        int rt = state;
        while(ch[pos-len[rt]-1] != ch[pos])rt = fail[rt];
        if(!nxt[rt][x]){
            int v = ++cnt, q = fail[rt]; len[v] = len[rt]+2;
            while(ch[pos-len[q]-1] != ch[pos])q = fail[q];
            fail[v] = nxt[q][x];
            nxt[rt][x] = v;
        }
        state = nxt[rt][x], sz[state][id]++;
    }
    void count()
    {
        for(int i = cnt; i > 0; i--){
            sz[fail[i]][0] += sz[i][0];
            sz[fail[i]][1] += sz[i][1];
            ans += 1LL*sz[i][0]*sz[i][1];
        }
    }
}PAM;

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        PAM.init();
        scanf("%s%s", s+1, t+1);
        s[0] = t[0] = -1;
        int n = strlen(s+1), m = strlen(t+1);
        ans = 0;
        for(int i = 1; i <= n; i++)PAM.insert(s[i]-'a', i, s, 0);
        PAM.state = 0;
        for(int i = 1; i <= m; i++)PAM.insert(t[i]-'a', i, t, 1);
        PAM.count();
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}
