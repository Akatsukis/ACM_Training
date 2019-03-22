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
int a[maxn];

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++)sc(a[i]);
    long long ans = 0;
    int pre = 0x3f3f3f3f;
    for(int i = n-1; i >= 0; i--){
        int val = min(a[i], pre-1);
        val = max(val, 0);
        ans += val;
        pre = val;
    }
    printf("%lld\n", ans);
    return 0;
}

