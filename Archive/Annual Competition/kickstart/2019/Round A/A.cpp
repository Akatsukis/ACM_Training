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
const int maxn = 1e5+10;
ll sum[maxn];
int a[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n, k;
        sc(n); sc(k);
        for(int i = 1; i <= n; i++)sc(a[i]);
        sort(a+1, a+1+n);
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1; i <= n; i++)sum[i] = sum[i-1]+a[i];
        for(int i = 1; i <= 1e4; i++){
            int id = upper_bound(a+1, a+1+n, i)-(a+1);
            if(id >= k)ans = min(ans, 1LL*i*k-(sum[id]-sum[id-k]));
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

