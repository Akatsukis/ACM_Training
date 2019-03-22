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
const int maxn = 1e5+10;
const int mod = 1e9+7;
int par[maxn], sz[maxn];

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    par[x] = y;
}

int qpow(ll a, int n)
{
    ll ret = 1;
    while(n){
        if(n&1)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}


int main()
{
    int n, k;
    sc(n); sc(k);
    for(int i = 1; i <= n; i++)par[i] = i;
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if(w == 0)unite(u, v);
    }
    for(int i = 1; i <= n; i++){
        sz[find(i)]++;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ans += qpow(sz[i], k);
        ans %= mod;
    }
    ans = qpow(n, k)-ans;
    ans = (ans%mod+mod)%mod;
    printf("%lld\n", ans);
    return 0;
}

