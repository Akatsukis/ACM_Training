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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
map<ll, ll> mp1;
map<pii, ll> mp2;

int main()
{
    int n;
    ll a, b;
    scanf("%d%lld%lld", &n, &a, &b);
    for(int i = 0; i < n; i++){
        ll x;
        int vx, vy;
        scanf("%lld%d%d", &x, &vx, &vy);
        ll now = a*vx-vy;
        mp1[now]++;
        mp2[mk(vx, vy)]++;
    }
    ll ans = 0;
    for(auto u : mp1)ans += u.se*u.se;
    for(auto u : mp2)ans -= u.se*u.se;
    printf("%lld\n", ans);
    return 0;
}

