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
const int mod = 1e9+7;
char s[maxn];

int qpow(ll a, int n) {
    long long ret = 1;
    while(n) {
        if(n&1)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s);
        int ans = 0, cnt = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == 'A')cnt--;
            else cnt++;
            if(cnt > k) {
                ans = (ans+qpow(2, i+1))%mod;
                cnt -= 2;
            }
            cnt = max(cnt, 0);
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

