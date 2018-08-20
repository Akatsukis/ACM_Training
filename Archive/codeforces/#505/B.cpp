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
ll a[maxn], b[maxn];

int main()
{
    int n; sc(n);
    ll pre = 0;
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &a[i], &b[i]);
        ll g = a[i]/gcd(a[i], b[i])*b[i];
        pre = gcd(pre, g);
    }
    if(pre == 1){
        puts("-1");
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(gcd(pre, a[i]) > 1)pre = gcd(pre, a[i]);
        else pre = gcd(pre, b[i]);
    }
    printf("%lld\n", pre);
    return 0;
}


