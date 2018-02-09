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
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
char s[maxn];
int dp[maxn*2];
int k;

int main()
{
    scanf("%s%d", s, &k);
    if(k == 0){
        printf("1\n");
        return 0;
    }
    int n = strlen(s);
    dp[0] = dp[1] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == '1'){
            for(int i = maxn-1; i >= 1; i--){
                dp[i+1] = (dp[i+1]+dp[i])%mod;
                dp[i] = (dp[i]+dp[i])%mod;
            }
        }
        else{
            for(int i = maxn-1; i >= 1; i--){
                dp[i] = (dp[i]+dp[i])%mod;
            }
        }
    }
//    for(int i = 0; i < n; i++){
//        printf("%d\n", dp[i]);
//    }
    int ans = 0;
    for(int i = 1; i <= 1000; i++){
        int now = i, tmp = 0;;
        while(now != 1){
            int p = now, cnt = 0;
            while(p){
                p -= p&(-p);
                cnt++;
            }
            tmp++;
            now = cnt;
        }
        if(tmp == k-1){
            ans += dp[i];
            ans %= mod;
        }
    }
    printf("%d\n", ans);
    return 0;
}

