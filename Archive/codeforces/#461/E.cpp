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
#define pr(x) printf(#x">>>x:%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e4+10;
ll n, W, B, X;
ll c[maxn];
ll cost[maxn];
ll dp[maxn];

int main()
{
    scanf("%lld%lld%lld%lld", &n, &W, &B, &X);
    for(int i = 0; i < n; i++)scanf("%lld", &c[i]);
    for(int i = 0; i < n; i++)scanf("%lld", &cost[i]);
    memset(dp, -1, sizeof(dp));
    dp[0] = W;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < c[i]; j++){
            for(int k = maxn-1; k >= 1; k--){
                if(dp[k-1] != -1)dp[k] = max(dp[k], dp[k-1]-cost[i]);
            }
        }
        for(int j = maxn-1; j >= 1; j--){
            if(dp[j] != -1)dp[j] = min(W+j*B, dp[j]+X);
        }
    }
    for(int i = maxn-1; i >= 0; i--){
        if(dp[i] != -1)return !printf("%d\n", i);
    }
	return 0;
}

