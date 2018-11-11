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
const int maxn = 2e5+10;
int a[maxn], b[maxn], n;
ll sum[maxn], t;

int main()
{
    scanf("%d%lld", &n, &t);
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sc(a[i]); b[i] = a[i];
        sum += a[i];
    }
    ll ans = 0;
    while(1){
        ll sum = 0, tot = 0;
        for(int j = 1; j <= n; j++){
            if(t >= a[j]){
                sum += a[j]; tot++;
                t -= a[j]; ans++;
            }
        }
        if(!sum)break;
        ans += t/sum*tot; t %= sum;
    }
    printf("%lld\n", ans);
    return 0;
}

