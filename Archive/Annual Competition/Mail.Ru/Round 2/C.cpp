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
ll ans;
ll la, ra, ta, lb, rb, tb, g;

void solve(ll k)
{
    ll lc = la+g*k, rc = ra+g*k;
    ans = max(ans, min(rc, rb)-max(lc, lb)+1);
}

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld", &la, &ra, &ta, &lb, &rb, &tb);
    if(ta > tb)swap(la, lb), swap(ra, rb), swap(ta, tb);
    g = gcd(ta, tb);
    ll k;
    k = (lb-la)/g;
    solve(k); solve(k+1);
    k = (rb-ra)/g;
    solve(k-1); solve(k);
    printf("%lld\n", ans);
    return 0;
}

