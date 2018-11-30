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

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    ll ans = 0;
    for(int i = 0; i < n; i++)sc(a[i]);
    sort(a, a+n);
    int tag = a[n-1]+1;
    for(int i = n-1; i >= 0; i--){
        ans += a[i]-1;
        if(a[i] < tag)ans -= tag-a[i]-1, tag = a[i];
        else tag--;
        tag = max(tag, 1);
    }
    ans -= tag-1;
    printf("%lld\n", ans);
    return 0;
}

