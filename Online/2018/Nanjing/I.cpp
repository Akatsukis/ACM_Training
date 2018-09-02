#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 2e6+10;
const int sigma = 10;
const int mod = 1e9+7;
int pw[maxn];
ll ans;
char s[maxn];
struct Node
{
    int idx, state, nxt[maxn][sigma], len[maxn], fail[maxn];
    void init()
    {
        idx = 1, state = 0;
        fail[0] = fail[1] = 1; len[1] = -1;
        memset(nxt[0], 0, sizeof(nxt[0]));
        memset(nxt[1], 0, sizeof(nxt[1]));
    }
    int newNode()
    {
        int p = ++idx;
        memset(nxt[p], 0, sizeof(nxt[p]));
        len[p] = fail[p] = 0;
        return p;
    }
    void insert(int x, int pos)
    {
        int rt = state;
        while(s[pos-len[rt]-1] != s[pos])rt = fail[rt];
        if(!nxt[rt][x]){
            int v = newNode(), q = fail[rt]; 
            len[v] = len[rt]+2;
            while(s[pos-len[q]-1] != s[pos])q = fail[q];
            fail[v] = nxt[q][x];
            nxt[rt][x] = v;
        }
        state = nxt[rt][x];
    }
    void dfs(int rt, ll val)
    {
        ans += val;
        ans %= mod;
        for(int i = 0; i < sigma; i++){
            if(nxt[rt][i]){
                ll now = val*10+i;
                if(len[rt]+1 != 0)now += 1LL*pw[len[rt]+1]*i%mod;
                now %= mod; 
                dfs(nxt[rt][i], now);
            }
        }
    }
}PAM;

int main()
{
    pw[0] = 1;
    for(int i = 1; i < maxn; i++)pw[i] = pw[i-1]*10LL%mod;
    scanf("%s", s+1);
    int n = strlen(s+1);
    PAM.init();
    for(int i = 1; i <= n; i++){
        PAM.insert(s[i]-'0', i);
    }
    PAM.dfs(0, 0);
    PAM.dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
