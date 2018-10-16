#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int mod = 1e9+7;
const int maxn = 1e5+10;
int a[maxn];
int n;

int main()
{
    int T; sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++)sc(a[i]);
        sort(a, a+n);
        ll ans = 1;
        for(int i = n-1; i >= 0; i -= 2){
            int val = a[i-1];
            int num = i-(lower_bound(a, a+n, val)-a);
            ans = ans*num%mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

