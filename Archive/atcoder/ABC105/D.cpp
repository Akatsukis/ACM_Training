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
int a[maxn];
ll sum[maxn];
map<int, int> mp;

int main()
{
    int n, m; 
    sc(n); sc(m);
    for(int i = 1; i <= n ;i++){
        sc(a[i]);
        sum[i] = sum[i-1]+a[i];
    }
    ll ans = 0;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        ans += mp[sum[i]%m];
        mp[sum[i]%m]++;
    }
    printf("%lld\n", ans);
    return 0;
}


