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
    long long w1, h1, w2, h2;
    scanf("%lld%lld%lld%lld", &w1, &h1, &w2, &h2);
    long long ans = w1+2+h1*2+w2+2+h2*2+w1-w2;
    printf("%lld\n", ans);
    return 0;
}

