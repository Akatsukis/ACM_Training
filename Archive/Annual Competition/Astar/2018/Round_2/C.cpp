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
int w[maxn];
int par[maxn];
vector<int> vec[maxn];
int bit[32];

void init(int n)
{
    for(int i = 1; i <= n; i++)par[i] = i, vec[i].clear();
}

int find(int x)
{
    return par[x]==x?x:par[x]=find(par[x]);
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if(x != y)par[x] = y;
}

int main()
{
    int T; sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        init(n);
        for(int i = 1; i <= n; i++)sc(w[i]);
        for(int i = 1; i <= m; i++){
            int u, v;
            sc(u); sc(v);
            unite(u, v);
        }
        for(int i = 1; i <= n; i++){
            vec[find(i)].pb(w[i]);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(!SZ(vec[i]))continue;
            sort(ALL(vec[i]));
            memset(bit, 0, sizeof(bit));
            for(auto u : vec[i]){
                for(int j = 0; j < 32; j++){
                    if((u>>j)&1){
                        ans += (1LL<<j)*bit[j]%mod*u%mod;
                        ans %= mod;
                        bit[j]++;
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}


