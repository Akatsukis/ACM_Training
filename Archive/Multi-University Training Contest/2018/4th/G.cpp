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
const int mod = 1e9+7;
const int maxn = 1e6+10;
ll fac[maxn], inv[maxn];
int a[maxn];
int used[maxn], stk[maxn];
vector<int> G[maxn], bit[maxn];
ll cnt, ans;

void pre_init()
{
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i < maxn; i++){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = inv[mod%i]*(mod-mod/i)%mod;
    }
}

void init(int n)
{
    cnt = 1, ans = 0;
    for(int i = 0; i <= n; i++)G[i].clear(), bit[i].clear(), used[i] = 0;
}

void add(int id, int x)
{
    while(x < SZ(bit[id])){
        bit[id][x]++;
        x += x&-x;
    }
}

int query(int id, int x)
{
    int ret = 0;
    while(x){
        ret += bit[id][x];
        x -= x&-x;
    }
    return ret;
}

int main()
{
    pre_init();
    int T; sc(T);
    while(T--){
        int n; sc(n);
        init(n);
        for(int i = 0; i < n; i++)sc(a[i]);
        for(int i = 0; i < n-1; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        for(int i = 1; i <= n; i++){
            cnt = cnt*fac[SZ(G[i])-1]%mod;
            sort(ALL(G[i]));
            bit[i].resize(SZ(G[i])+1);
        }
        for(int i = 1; i < a[0]; i++){
            ans = (ans+cnt*SZ(G[i]))%mod;
        }
        cnt = cnt*SZ(G[a[0]])%mod;
        int top = 0;
        stk[top++] = a[0];
        for(int i = 1; i < n; i++){
            while(top && SZ(G[stk[top-1]]) == used[stk[top-1]])top--;
            if(!top)break;
            int u = stk[top-1];
            cnt = cnt*inv[SZ(G[u])-used[u]]%mod;
            int idv = lower_bound(ALL(G[u]), a[i])-G[u].begin();
            ans = (ans+cnt*(idv-query(u, idv)))%mod;
            if(idv == SZ(G[u]) || G[u][idv] > a[i])break;
            int v = G[u][idv];
            used[u]++, used[v]++;
            int idu = lower_bound(ALL(G[v]), u)-G[v].begin();
            add(u, idv+1);
            add(v, idu+1);
            stk[top++] = v;
        }
        printf("%lld\n", ans);
    }
    return 0;
}


