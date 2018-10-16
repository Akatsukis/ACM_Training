#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ALL(A) A.begin(),A.end()
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n", x)
#define Abs(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
int a[maxn];
int sum[maxn];
int n;

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(sum, 0 ,sizeof(sum));
        sc(n);
        for(int i = 1; i <= n; i++){
            sc(a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        int ans = INF;
        for(int i = 0; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                ans = min(ans, Abs(sum[j]-sum[i]));
            }
        }
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}
