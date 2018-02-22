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
const int maxn = 1e6+10;
int dp[maxn][10];
int q;


int main()
{
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j < 10; j++)dp[i][j] = dp[i-1][j];
        int now = i;
        while(now >= 10){
            int cnt = 1;
            while(now){
                if(now%10)cnt *= now%10;
                now /= 10;
            }
            now = cnt;
        }
        dp[i][now]++;
    }
    sc(q);
    for(int i = 0; i < q; i++){
        int l, r, k;
        sc(l);sc(r);sc(k);
        printf("%d\n", dp[r][k]-dp[l-1][k]);
    }
    return 0;
}

