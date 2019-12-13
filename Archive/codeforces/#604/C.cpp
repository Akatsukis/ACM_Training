#include <bits/stdc++.h>
using namespace std;
#define lson k*2+1
#define rson k*2+2
constexpr int maxn = 2e5+10;
constexpr int mod = 998244353;
long long mul[maxn];
long long p[maxn];
long long tr[maxn*4], tag[maxn*4];
bool cp[maxn];

long long qpow(long long a, long long n) {
    long long ret = 1;
    while(n) {
        if(n&1) ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

void build(int k, int l, int r) {
    tag[k] = 1;
    if(l == r-1) {
        tr[k] = qpow(mul[l], mod-2);
        return;
    }
    int m = (l+r)/2;
    build(lson, l, m);
    build(rson, m, r);
    tr[k] = (tr[lson]+tr[rson])%mod;
}

void push_down(int k, int l, int r) {
    if(l != r-1 && tag[k] != 1) {
        tr[lson] = tr[lson]*tag[k]%mod;
        tr[rson] = tr[rson]*tag[k]%mod;
        tag[lson] = tag[lson]*tag[k]%mod;
        tag[rson] = tag[rson]*tag[k]%mod;
        tag[k] = 1;
    }
}

void update(int a, int b, int k, int l, int r, long long val) {
    if(a >= r || b <= l) return;
    if(a <= l && b >= r) {
        tr[k] = tr[k]*val%mod;
        tag[k] = tag[k]*val%mod;
        return;
    }
    push_down(k, l, r);
    int m = (l+r)/2;
    update(a, b, lson, l, m, val);
    update(a, b, rson, m, r, val);
    tr[k] = (tr[lson]+tr[rson])%mod;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &p[i]);
    }
    mul[n+1] = 1;
    long long inv_100 = qpow(100, mod-2);
    for(int i = n; i >= 1; i--) {
        mul[i] = mul[i+1]*p[i]%mod*inv_100%mod;
    }
    build(0, 1, n+1);
    set<int> st;
    st.insert(1); st.insert(n+1);
    while(q--) {
        int pos;
        scanf("%d", &pos);
        if(cp[pos] == 0) {
            auto it = st.lower_bound(pos);
            int r = *(it), l = *(--it);
            long long val = mul[pos]*qpow(mul[r], mod-2)%mod;
            update(l, pos, 0, 1, n+1, val);
            st.insert(pos);
        }
        else {
            st.erase(pos);
            auto it = st.lower_bound(pos);
            int r = *(it), l = *(--it);
            long long val = qpow(mul[pos]*qpow(mul[r], mod-2)%mod, mod-2);
            update(l, pos, 0, 1, n+1, val);
        }
        long long ans = tr[0]%mod;
        printf("%lld\n", ans);
        cp[pos] ^= 1;
    }
    return 0;
}

