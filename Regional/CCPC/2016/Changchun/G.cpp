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
const int maxn = 100;
bool mp[maxn][maxn];
ll fac[maxn];
vector<int> vec;
int n, m;

void init()
{
    fac[0] = 1;
    for(int i = 1; i < maxn; i++)fac[i] = fac[i-1]*i%mod;
}

int qpow(ll a, int n)
{
    ll ret = 1;
    while(n){
        if(n&1LL)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

ll C(int a, int b)
{
    return fac[b]*qpow(fac[b-a], mod-2)%mod*qpow(fac[a], mod-2)%mod;
}

bool calc()
{
    int ret = 0, sz = vec.size();
    for(int i = 0; i < sz; i++){
        for(int j = i+1; j < sz; j++){
            for(int k = j+1; k < sz; k++){
                if(mp[vec[i]][vec[j]]&&mp[vec[i]][vec[k]]&&mp[vec[j]][vec[k]])return 1;
                else if(!mp[vec[i]][vec[j]]&&!mp[vec[i]][vec[k]]&&!mp[vec[j]][vec[k]])return 1;
            }
        }
    }
    return ret;
}

int dfs(int id, int u, int k)
{
    int ret = 0;
    if(u == k){
        ret += calc();
        return ret;
    }
    for(int i = id; i <= n; i++){
        vec.pb(i);
        ret = (ret+dfs(i+1, u+1, k))%mod;
        vec.pop_back();
    }
    return ret;
}


int main()
{
    init();
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(mp, 0, sizeof(mp));
        sc(n); sc(m);
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            mp[u][v] = mp[v][u] = 1;
        }
        ll ans = 0;
        for(int i = 6; i <= n; i++)ans = (ans+C(i, n))%mod;
        for(int i = 3; i <= min(5, n); i++)ans = (ans+dfs(1, 0, i))%mod;
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

