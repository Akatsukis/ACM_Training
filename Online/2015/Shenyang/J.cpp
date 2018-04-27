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
#define debug cout<<">>>STOP"<<endl
const ll mod = 530600414;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e5+10;
ll g[maxn], f[maxn], b[maxn], len[maxn], sz[maxn];

void init()
{
    len[3] = 3, len[4] = 5;
    f[3] = 1, f[4] = 3;
    b[3] = 2, b[4] = 2;
    sz[3] = 1, sz[4] = 1;
    for(int i = 5; i < maxn; i++){
        len[i] = (len[i-1]+len[i-2])%mod;
        sz[i] = (sz[i-1]+sz[i-2])%mod;
        b[i] = (b[i-1]+b[i-2]+sz[i-2]*len[i-1])%mod;
        f[i] = (f[i-1]+f[i-2]+sz[i-1]*len[i-2])%mod;
    }
    for(int i = 5; i < maxn; i++){
        g[i] = (g[i-1]+g[i-2]+b[i-2]*sz[i-1]+f[i-1]*sz[i-2])%mod;
    }
}

int main()
{
    init();
    int T, kase = 1;
    sc(T);
    while(T--){
        int n;
        sc(n);
        printf("Case #%d: %lld\n", kase++, g[n]);
    }
    return 0;
}

