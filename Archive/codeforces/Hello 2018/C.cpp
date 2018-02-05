#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 30;
ll c[maxn];
ll d[maxn];

int main()
{
    ll n, L;
    scanf("%lld%lld", &n, &L);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &c[i]);
        d[i] = c[i];
    }
    for(int i = 2; i <= n; i++){
        c[i] = min(c[i], c[i-1]*2);
    }
    for(int i = n-1; i >= 1; i--){
        d[i] = min(d[i], d[i+1]);
    }
    ll ans = 0;
    ll now = L/(1<<(n-1));
    L -= now*(1<<(n-1));
    ans += now*c[n];
    for(int i = n-1; i >= 1; i--){
        ll now = L/(1<<(i-1));
        ll tmp = now*c[i];
        for(int j = i+1; j <= n; j++){
            if(d[j] < tmp){
                L = 0;
                ans += d[j];
                break;
            }
        }
        L -= now*(1<<(i-1));
        ans += now*c[i];
    }
    printf("%lld\n", ans);
    return 0;
}

