#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 2e4+10;
int dfn[maxn], low[maxn], bcc[maxn], num[maxn], cac[maxn];
vector<int> G[maxn];
stack<pii> sk;
int n, m, idx, cnt;
bool ok;

struct BigInt
{
    const static int mod = 1e4;
    const static int DLEN = 4;
    int a[maxn], len;
    BigInt()
    {
        memset(a, 0, sizeof(a));
        len = 1;
    }
    BigInt(int v)
    {
        memset(a, 0, sizeof(a));
        len = 0;
        do{
            a[len++] = v%mod;
            v /= mod;
        }while(v);
    }
    BigInt operator * (const BigInt &b)const
    {
        BigInt res;
        for(int i = 0; i < len; i++){
            int up = 0;
            for(int j = 0; j < b.len; j++){
                int tmp = a[i]*b.a[j]+res.a[i+j]+up;
                res.a[i+j] = tmp%mod;
                up = tmp/mod;
            }
            if(up)res.a[i+b.len] = up;
        }
        res.len = len+b.len;
        while(res.a[res.len-1] == 0 && res.len > 1)res.len--;
        return res;
    }
    void output()
    {
        printf("%d", a[len-1]);
        for(int i = len-2; i >= 0; i--)printf("%04d", a[i]);
        puts("");
    }
};

void init()
{
    for(int i = 1; i <= n; i++){
        dfn[i] = low[i] = bcc[i] = num[i] = cac[i] = 0;
        G[i].clear();
    }
    idx = cnt = 0;
    ok = 1;
}

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++idx;
    for(auto v : G[u]){
        if(v == f)continue;
        if(!dfn[v]){
            sk.push(mk(u, v));
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){
                cnt++;
                while(1){
                    pii p = sk.top(); sk.pop();
                    if(bcc[p.fi] != cnt)bcc[p.fi] = cnt, num[cnt]++;
                    if(bcc[p.se] != cnt)bcc[p.se] = cnt, num[cnt]++;
                    if(p.fi == u && p.se == v)break;
                }
            }
            else cac[u]++;
        }
        else if(dfn[v] < dfn[u]){
            cac[u]++;
            sk.push(mk(u, v));
            low[u] = min(low[u], dfn[v]);
        }
    }
}

int main()
{
    bool fst = 1;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(int i = 0; i < m; i++){
            int k; sc(k);
            int v = 0;
            for(int j = 0; j < k; j++){
                int u; sc(u);
                if(v)G[u].pb(v), G[v].pb(u);
                v = u;
            }
        }
        dfs(1, 0);
        BigInt ans = BigInt(1);
        for(int i = 1; i <= n; i++){
            if(!dfn[i] || cac[i] > 1)ok = 0;
        }
        if(!ok)ans = BigInt(0);
        for(int i = 1; i <= cnt; i++){
            if(num[i] > 2)ans = ans*BigInt(num[i]+1);
        }
        if(fst)fst = 0;
        else puts("");
        ans.output();
    }
    return 0;
}

