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
const int maxn = 1e6+10;
ll a[maxn];
ll b[maxn];
int n, m;

bool cmp(ll lhs, ll rhs)
{
    return lhs>rhs;
}

int main()
{
    sc(n); sc(m);
    for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++)scanf("%lld", &b[i]);
    sort(a+1, a+n+1);
    sort(b+1, b+n+1, greater<ll>());
    ll ans = 0;
    int i;
    for(i = 1; i <= n; i++){
        if(b[i] >= a[i]){
            ans += b[i]-a[i];
            if(i%3 == 0)ans += m;
        }
        else break;
    }
    ll now = 0;
    for(; i <= n; i++){
        now += b[i]-a[i];
        if(i%3 == 0){
            if(m+now > 0){
                ans += m+now;
                now = 0;
            }
            else break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

