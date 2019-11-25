#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
constexpr int mod = 998244353;
int a[maxn], fac[maxn], inv[maxn];

int qpow(long long a, int n) {
    long long ret = 1;
    while(n) {
        if(n&1) ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

void init() {
    fac[0] = 1;
    for(int i = 1; i < maxn; i++) fac[i] = 1LL*fac[i-1]*i%mod;
    inv[maxn-1] = qpow(fac[maxn-1], mod-2);
    for(int i = maxn-2; i >= 0; i--) {
        inv[i] = 1LL*inv[i+1]*(i+1)%mod;
    }
}

int C(int a, int b) {
    return 1LL*fac[a]*inv[b]%mod*inv[a-b]%mod;
}

int main()
{
    init();
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != a[(i+1)%n]) cnt++;
    }
    long long ans = 0;
    for(int i = 0; i*2 <= cnt; i++) {
        ans += 1LL*C(cnt, i)*C(cnt-i, i)%mod*qpow(k-2, cnt-2*i)%mod*qpow(k, n-cnt)%mod;
        ans %= mod;
        ans %= mod;
    }
    ans = (qpow(k, n)-ans+mod)*inv[2]%mod;
    printf("%lld\n", ans);
    return 0;
}

