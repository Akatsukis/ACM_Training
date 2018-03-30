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
const ll mod = 10056;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3+10;
int dp[maxn][maxn];
int ans[maxn];

void init()
{
    dp[1][1] = 1; ans[1] = 1;
    for(int i = 2; i < maxn; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])*j%mod;
            ans[i] = (ans[i]+dp[i][j])%mod;
        }
    }
}

int main()
{
    init();
    int T, kase = 1;
    sc(T);
    while(T--){
        int n;
        sc(n);
        printf("Case %d: %d\n", kase++, ans[n]);
    }
    return 0;
}

