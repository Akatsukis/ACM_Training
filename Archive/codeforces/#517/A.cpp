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

int main()
{
    int n, m, k;
    sc(n); sc(m); sc(k);
    int ans = 0;
    for(int i = 0; i < k; i++){
        int now = 2*(n+m)-4;
        ans += now;
        n -= 4, m -= 4;
    }
    printf("%d\n", ans);
    return 0;
}

