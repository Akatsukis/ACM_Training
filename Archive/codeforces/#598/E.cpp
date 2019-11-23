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
constexpr int maxn = 2e5+10;
long long dp[maxn];
int ans[maxn], pre[maxn];
struct ps{
    int v, pos;
    bool operator < (const ps &rhs) const {
        return v < rhs.v;
    }
}a[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].v);
        a[i].pos = i;
    }
    sort(a+1, a+n+1);
    set<pair<long long, int>> st;
    st.insert(make_pair(-a[1].v, 1));
    for(int i = 3; i <= n; i++) {
        auto val = st.begin()->first;
        auto id = st.begin()->second;
        dp[i] = a[i].v+val;
        pre[i] = id-1;
        if(i >= 5)st.insert(make_pair(dp[i-2]-a[i-1].v, i-1));
    }
    int cur = 0;
    for(int i = n; i; ) {
        cur++;
        for(int j = pre[i]+1; j <= i; j++) {
            ans[a[j].pos] = cur;
        }
        i = pre[i];
    }
    printf("%lld %d\n", dp[n], cur);
    for(int i = 1; i <= n; i++) {
        printf("%d%c", ans[i], " \n"[i==n]);
    }
    return 0;
}

