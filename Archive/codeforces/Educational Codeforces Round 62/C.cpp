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
pii p[maxn];

int main()
{
    int n, k;
    sc(n); sc(k);
    for(int i = 0; i < n; i++)scanf("%d%d", &p[i].se, &p[i].fi);
    sort(p, p+n);
    ll ans = 0, sum = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = n-1; i >= 0; i--){
        pq.push(p[i].se); sum += p[i].se;
        if((int)pq.size() > k){
            int u = pq.top(); pq.pop();
            sum -= u;
        }
        ans = max(ans, p[i].fi*sum);
    }
    printf("%lld\n", ans);
    return 0;
}

