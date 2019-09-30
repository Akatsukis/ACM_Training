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
const int maxn = 1e7+10;
bool vis[maxn];
vector<int> prime;

void init()
{
    for(int i = 2; i < maxn; i++) {
        if(!vis[i])prime.pb(i);
        for(int j = 0; j < (int)prime.size() && i*prime[j] < maxn; j++) {
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)break;
        }
    }
}

bool check(ll v) {
    for(auto p: prime) {
        if(v%p ==0)return 0;
    }
    return 1;
}

ll qpow(__int128 a, ll n, ll p) {
    __int128 ret = 1;
    while(n) {
        if(n&1)ret = ret*a%p;
        a = a*a%p;
        n >>= 1;
    }
    return ret;
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--){
        ll p;
        scanf("%lld", &p);
        ll q = p-1;
        while(!check(q))q--;
        __int128 ans = p-1;
        for(ll i = p-1; i > q; i--) {
            ans = ans*qpow(i, p-2, p)%p;
        }
        printf("%lld\n", (ll)ans);
    }
    return 0;
}

