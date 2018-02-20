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
int pre[maxn];
int n;

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            pre[i] = i;
            dp[i] = dp[i-pre[i-1]] + i-pre[i-1];
        }
        else{
            pre[i] = pre[i-1];
            dp[i] = dp[i-1] + 1;
        }
        printf("dp[%d]:%d, pre[%d]:%d\n", i, dp[i], i, pre[i]);
    }
    printf("%d\n", dp[n]);
    return 0;
}

