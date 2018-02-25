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

int main()
{
    ull n, k, a, b;
    scanf("%llu%llu%llu%llu", &n, &k, &a, &b);
    if(k == 1){
        printf("%llu\n", a*(n-1));
        return 0;
    }
    ull ans = 0;
    while(n > 1){
        if(n%k==0){
            ans += min(b, a*n/k*(k-1));
            n /= k;
        }
        else{
            if(n/k==0)ans += (n-1)*a, n = 1;
            else ans += n%k*a, n = n/k*k;
        }
        //printf(">>n=%d, ans=%llu\n", n, ans);
    }
    printf("%llu\n", ans);
    return 0;
}

