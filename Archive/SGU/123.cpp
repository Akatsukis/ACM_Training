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
const int maxn = 50;
ll f[maxn], sum[maxn];

int main()
{
    int n;
    sc(n);
    f[1] = f[2] = 1;
    sum[1] = 1, sum[2] = 2;
    for(int i = 3; i <= n; i++){
        f[i] = f[i-1]+f[i-2];
        sum[i] = sum[i-1]+f[i];
    }
    printf("%lld\n", sum[n]);
    return 0;
}


