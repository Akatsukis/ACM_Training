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

int main()
{
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    if(k < n){
        printf("%lld %d\n", 1+k, 1);
    }
    else{
        k -= n-1;
        ll a = (k-1)/(m-1)+1;
        if(a&1LL){
            ll x = n+1-a, y = k%(m-1)==0?m-1:k%(m-1);
            y++;
            printf("%lld %lld\n", x, y);
        }
        else{
            ll x = n+1-a, y = k%(m-1)==0?m-1:k%(m-1);
            y = m+1-y;
            printf("%lld %lld\n", x, y);
        }
    }
    return 0;
}

