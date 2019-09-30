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
const int mod = 1e9+7;
map<long long, __int128> mp;
int a, b;

__int128 dfs(__int128 n) {
    if(mp.count(n))return mp[n];
    mp[n] = n*n*n*b+n*n*(n-1)*a;
    if(n%2 == 1)return mp[n];
    else {
        mp[n] = min(mp[n], 18*sqr(n/2)*a+7*dfs(n/2));
        return mp[n];
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        mp.clear();
        long long n;
        scanf("%lld%d%d", &n, &a, &b);
        int ans = dfs(n)%mod;
        printf("%d\n", ans);
    }
    return 0;
}

