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
const int maxn = 1e3+10;
int n, k1, k2;
ll a[maxn], b[maxn];

int main()
{
    sc(n); sc(k1); sc(k2);
    for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
    for(int i = 0; i < n; i++)scanf("%lld", &b[i]);
    priority_queue<ll> pq;
    for(int i = 0; i < n; i++){
        pq.push(ABS(a[i]-b[i]));
    }
    for(int i = 0; i < k1+k2; i++){
        ll u = pq.top(); pq.pop();
        pq.push(ABS(u-1));
    }
    ll ans = 0;
    while(!pq.empty())ans += sqr(pq.top()), pq.pop();
    printf("%lld\n", ans);
    return 0;
}


