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
const int maxn = 2000+10;
int a[maxn];
int dp[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 2)dp[i] = dp[i-1]+1;
        else{
            int now = 1;
            while(i-now>0&&a[i-now+1]<=a[i-now])now++;
            dp[i] = max(dp[i-1], now+dp[i-now]);
        }
        printf("dp[%d]=%d\n", i, dp[i]);
    }
    printf("%d\n", dp[n]);
    return 0;
}

