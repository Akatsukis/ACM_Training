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
const int maxn = 3e5+10;
char s[maxn];
ll ans;
struct Node
{
    int now, cnt, fail[maxn], len[maxn], sz[maxn], nxt[maxn][26];
    void init()
    {
        cnt = 1; fail[0] = fail[1] = 1; len[1] = -1;
    }
    void extend(int c, int pos)
    {
        int rt = now;
        while(s[pos-len[rt]-1] != s[pos])rt = fail[rt];
        if(!nxt[rt][c]){
            int v = ++cnt, q = fail[rt]; len[v] = len[rt]+2;
            while(s[pos-len[q]-1] != s[pos])q = fail[q]; 
            fail[v] = nxt[q][c];
            nxt[rt][c] = v;
        }
        now = nxt[rt][c]; sz[now]++;
    }
    void count()
    {
        for(int i = cnt; i > 0; i--){
            sz[fail[i]] += sz[i];
            ans = max(ans, 1LL*len[i]*sz[i]);
        }
    }
}PAM;

int main()
{
    PAM.init();
    scanf("%s", s+1);
    int n = strlen(s+1);
    for(int i = 1; i <= n; i++)PAM.extend(s[i]-'a', i);
    PAM.count();
    printf("%lld\n", ans);
    return 0;
}

