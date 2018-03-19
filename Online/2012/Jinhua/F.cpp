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
const int maxn = 100100;
double p[maxn];
double dp[maxn];
int to[maxn];
int n, m;

void init()
{
    for(int i = 0; i < n+6; i++)dp[i] = 0, p[i] = 0;
    memset(to, 0, sizeof(to));
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && (n||m)){
        init();
        for(int i = 0; i < m; i++){
            int x, y;
            sc(x); sc(y);
            to[x] = y;
        }
        p[0] = 1;
        for(int i = 0; i < n; i++){
            if(to[i]){
                dp[to[i]] += dp[i];
                p[to[i]] += p[i];
                continue;
            }
            for(int j = 1; j <= 6; j++){
                p[i+j] += p[i]/6.0;
                dp[i+j] += (dp[i]+p[i])/6.0; 
            }
            //printf("p[%d]:%f,dp[%d]:%f\n", i, p[i], i, dp[i]);
        }
        double ans = 0;
        for(int i = n; i < n+6; i++){
            ans += dp[i];
        }
        printf("%.4f\n", ans);
    }
    return 0;
}

