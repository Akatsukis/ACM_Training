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
const int mod = 998244353;
const int maxn = 1e5+10;
ll ans[maxn];

void init()
{
    ans[2] = 0 , ans[3] = ans[4] = 1;
    for(int i = 5; i < maxn; i++){
        ans[i] = (i-2)*ans[i-1]+(i-1)*ans[i-2]-(i%2?-1:1);
        ans[i] = (ans[i]%mod+mod)%mod;
    }
}

int main()
{
    init();
    int T; sc(T);
    while(T--){
        int n; sc(n);
        printf("%lld\n", ans[n]);
    }
    return 0;
}


