#include <bits/stdc++.h>
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
const int maxn = 1e6+10;
long long sum[maxn];
int a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    long long tot = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        tot += a[i];
    }
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1]+a[i];
    }
    vector<long long> fac;
    for(long long i = 2; i*i <= tot; i++) {
        if(tot%i == 0) {
            fac.push_back(i);
            while(tot%i == 0) tot /= i;
        }
    }
    if(tot != 1) fac.push_back(tot);
    long long ans = LONG_LONG_MAX;
    for(auto v: fac) {
        long long res = 0;
        for(int i = 1; i <= n; i++) {
            res += min(sum[i]%v, v-(sum[i]%v));
        }
        ans = min(ans, res);
    }
    if(ans == LONG_LONG_MAX) ans = -1;
    printf("%lld\n", ans);
    return 0;
}

