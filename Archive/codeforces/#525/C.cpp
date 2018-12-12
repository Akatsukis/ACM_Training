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
const int maxn = 2e3+10;
ll a[maxn];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
    ll sum = 0;
    printf("%d\n", n+1);
    for(int i = n; i >= 1; i--){
        a[i] += sum;
        ll val = n+i-1-(a[i]%n);
        sum += val;
        printf("1 %d %lld\n", i, val);
    }
    printf("2 %d %d\n", n, n);
    return 0;
}

