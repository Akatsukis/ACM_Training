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
const int maxn = 1e4+10;
ll deg[maxn];

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u); sc(v);
        deg[u]++, deg[v]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += sqr(deg[i]);
    }
    printf("%lld\n", ans);
    return 0;
}

