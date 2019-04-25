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
    long long a, b;
    scanf("%lld%lld", &a, &b);
    if(a < b)swap(a, b);
    long long n = a-b, mn = 1e18;
    int ans = 0;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            int u = i, v = n/i;
            int k = a%u;
            if(k)k = u-k;
            long long res = (a+k)*(b+k)/__gcd(a+k, b+k);
            if(res < mn){
                mn = res;
                ans = k;
            }
            else if(res == mn)ans = min(ans, k);
            k = a%v;
            if(k)k = v-k;
            res = (a+k)*(b+k)/__gcd(a+k, b+k);
            if(res < mn){
                mn = res;
                ans = k;
            }
            else if(res == mn)ans = min(ans, k);
        }
    }
    printf("%d\n", ans);
    return 0;
}

