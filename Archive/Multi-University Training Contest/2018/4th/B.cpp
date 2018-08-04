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
const int maxn = 1e5+10;
const int blk = 316;
struct Query
{
    int n, m, id;
    bool operator < (const Query &rhs)
    {
        return n/blk != rhs.n/blk ? n/blk<rhs.n/blk : m<rhs.m;
    }
}q[maxn];
ll fac[maxn], inv[maxn];
int ans[maxn];

void init()
{
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for(int i = 2; i < maxn; i++)fac[i] = fac[i-1]*i%mod, inv[i] = inv[mod%i]*(mod-mod/i)%mod;
    for(int i = 2; i < maxn; i++)inv[i] = inv[i]*inv[i-1]%mod;
}

ll C(int n, int m)
{
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}

int main()
{
    init();
    int n; sc(n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &q[i].n, &q[i].m);
        q[i].id = i;
    }
    sort(q, q+n);
    ll res = 1;
    int l = 1, r = 0; // [l, r]
    for(int i = 0; i < n; i++){
        while(q[i].n > l)res = (res*2-C(l++, r)+mod)%mod;
        while(q[i].n < l)res = (res+C(--l, r))*inv[2]%mod;
        while(q[i].m > r)res = (res+C(l, ++r))%mod;
        while(q[i].m < r)res = (res-C(l, r--)+mod)%mod;
        ans[q[i].id] = res;
    }
    for(int i = 0; i < n; i++)printf("%d\n", ans[i]);
    return 0;
}


