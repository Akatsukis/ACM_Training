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
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x:"%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
ll n, m;
ll a[maxn];
ll b[maxn];

ll extgcd(ll u, ll v, ll &x, ll &y)
{
    ll d = u;
    if(v){
        d = extgcd(v, u%v, y, x);
        y -= (u/v)*x;
    }
    else{
        x = 1; y = 0;
    }
    return d;
}

ll inv(ll a)
{
    ll x, y;
    extgcd(a, mod, x, y);
    return (mod+x%mod)%mod;
}

int main()
{
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
    for(int i = 0; i < n; i++)scanf("%lld", &b[i]);
    ll ans = 0, now = inv(1);
    for(int i = 0; i < n; i++){
        if(a[i]==0&&b[i]==0){
            ans = (ans+now*(m-1)%mod*inv(2*m)%mod)%mod;
            now = now*inv(m)%mod;
        }
        else if(a[i]==0){
            ans = (ans+now*(m-b[i])%mod*inv(m)%mod)%mod;
            now = now*inv(m)%mod;
        }
        else if(b[i]==0){
            ans = (ans+now*(a[i]-1)%mod*inv(m)%mod)%mod;
            now = now*inv(m)%mod;
        }
        else if(a[i]>b[i]){
            ans = (ans+now)%mod;
            break;
        }
        else if(b[i]>a[i]){
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

