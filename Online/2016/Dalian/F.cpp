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
const int maxn = 2e4+10;
ll a[maxn];
ll sum[maxn];

int main()
{
    int T;
    while(sc(T) != EOF){
        while(T--){
            int n;
            sc(n);
            for(int i = 1; i <= n; i++)scanf("%lld\n", &a[i]);
            sort(a+1, a+n+1);
            for(int i = 1; i <= n; i++)sum[i] = sum[i-1]+a[i];
            bool flg = 1;
            for(ll k = 1; k <= n; k++){
                if(sum[k] < k*(k-1)|| (sum[n]-sum[n-k]) > 2*k*(n-k)+k*(k-1)){
                    flg = 0;
                    break;
                }
            }
            if(flg)puts("T");
            else puts("F");
        }   
    }
    return 0;
}

