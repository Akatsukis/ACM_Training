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
const int maxn = 3e5+10;
ll a[maxn];
int bit[maxn], sum[maxn], sgn[maxn];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        ll x = a[i];
        while(x){
            if(x&1LL)bit[i]++;
            x >>= 1;
        }
        sum[i] = sum[i-1];
        sgn[i] = sgn[i-1]^(bit[i]&1);
        if(i != 1 && (sgn[i-1]^(bit[i]&1)) == 0)sum[i]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int sg = bit[i]&1LL;
        int mx = bit[i], tot = bit[i];
        for(int j = i+1; j <= n; j++){
            sg ^= (bit[j]&1);
            tot += bit[j], mx = max(mx, bit[j]);
            if(tot%2 == 0 && tot >= mx*2)ans++;
            if(tot >= 128){
                int val = sum[n]-sum[j];
                if(sg != sgn[j])ans += n-j-val;
                else ans += val;
                break;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}

