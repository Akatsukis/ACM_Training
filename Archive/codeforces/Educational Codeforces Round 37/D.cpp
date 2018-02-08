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
const int maxn = 5000+10;
int n, k, v;
bool dp[maxn][maxn];
bool used[maxn][maxn];
bool f[maxn];
int a[maxn];

int main()
{
    scanf("%d%d%d", &n, &k, &v);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < k; j++){
            if(dp[i-1][j]){
                dp[i][j] = 1;used[i][j] = 0;
                dp[i][(j+a[i])%k] = 1;used[i][(j+a[i])%k] = 1;
            }
        }
    }
    //for(int i = 1; i <= n; i++){
        //for(int j = 0; j < k; j++){
            //printf("dp[%d][%d]:%d\n", i, j, dp[i][j]);
        //}
    //}
    if(!dp[n][v%k] || sum < v)return !printf("NO\n");
    else printf("YES\n");
    int now = v%k, pre = 0; sum = 0;
    for(int i = n; i >= 1; i--){
        if(used[i][now]){
            if(pre && a[pre])printf("%d %d %d\n", (a[pre]-1+k)/k, pre, i);
            now = ((now-a[i])%k+k)%k;
            sum += a[i];a[i] = sum;
            f[i] = 1;
            pre = i;
        }
    }
    int ans = pre, tot = 0; pre = 0;
    for(int i = n; i >= 1; i--){
        if(!f[i]){
            if(pre && a[pre])printf("%d %d %d\n", (a[pre]-1+k)/k, pre, i);
            tot += a[i];a[i] = tot;
            pre = i;
        }
    }
    if(!ans){
        for(int i = 1; i <= n; i++)if(pre != i){
            ans = i;
            break;
        }
    }
    if(!pre){
        for(int i = 1; i <= n; i++)if(ans != i){
            pre = i;
            break;
        }
    }
    if(sum < v)printf("%d %d %d\n", (v-sum)/k, pre, ans);
    else if(sum > v)printf("%d %d %d\n", (sum-v)/k, ans, pre);
	return 0;
}

