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
const int mod = 998244353;
int pre[maxn], nxt[maxn];
char s[maxn];
int n;

int main()
{
    scanf("%d%s", &n, s+1);
    ll ans = 0;
    int l = 1, r = n;
    while(l+1 <= n && s[l+1] == s[1])l++;
    while(r-1 >= 1 && s[r-1] == s[n])r--;
    if(s[1] == s[n]){
        if(l < r)ans = 1LL*(n-r+2)*(l+1);
        else ans = 1LL*n*(n+1)/2;
    }
    else ans = l+n-r+2;
    printf("%lld\n", ans%mod);
    return 0;
}

