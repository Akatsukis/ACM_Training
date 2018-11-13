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
const int maxn = 3e5+10;
ll x[maxn], y[maxn];
ll px[maxn], py[maxn];
ll n, k;

int main()
{
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i <= n; i++)scanf("%lld", &x[i]);
    for(int i = 1; i <= n; i++)scanf("%lld", &y[i]);
    bool flg = 1;
    for(int i = 1; i <= n; i++){
        px[i] = (x[i]-(k-px[i-1])-(y[i]-1)*k);
        py[i] = (y[i]-(k-py[i-1])-(x[i]-1)*k);
        px[i] = max(px[i], 0LL); py[i] = max(py[i], 0LL);
        if(px[i] > k || py[i] > k){
            flg = 0;
            break;
        }
    }
    if(flg)puts("YES");
    else puts("NO");
    return 0;
}

