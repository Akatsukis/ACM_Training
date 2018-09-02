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
const ll INF64 = 0x3f3f3f3f3f3f3f;
const int maxn = 26;
ll pw[maxn];

ll cal(ll m)
{
    ll ret = 0;
    for(int i = 1; i < maxn; i++)ret += m/pw[i];
    return ret;
}

int main()
{
    pw[0] = 1;
    for(int i = 1; i < maxn; i++){
        pw[i] = pw[i-1]*5;
    }
    int n; sc(n);
    if(n == 0){
        printf("%d\n", 1);
        return 0;
    }
    ll l = 0, r = INF64, ans = -1;
    while(l <= r){
        ll m = (l+r)>>1;
        ll now = cal(m*5);
        if(now < n)l = m+1;
        else if(now == n){
            ans = m*5;
            break;
        }
        else if(now > n)r = m-1;
    }
    if(ans == -1)puts("No solution");
    else printf("%lld\n", ans);
    return 0;
}

