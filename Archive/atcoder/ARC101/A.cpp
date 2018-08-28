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
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
int a[maxn];

int main()
{
    int n, k;
    sc(n); sc(k);
    for(int i = 1; i <= n; i++)sc(a[i]);
    int ans = INF;
    for(int i = 1; i+k-1 <= n; i++){
        if(a[i] < 0 && a[i+k-1] < 0)ans = min(ans, -a[i]);
        else if(a[i] < 0 && a[i+k-1] >= 0)ans = min(ans, -a[i]+a[i+k-1]+min(-a[i], a[i+k-1]));
        else ans = min(ans, a[i+k-1]);
    }
    printf("%d\n", ans);
    return 0;
}


