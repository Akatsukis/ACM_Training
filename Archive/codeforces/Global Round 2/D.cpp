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
ll sum[maxn];

int main()
{
    int n;
    sc(n);
    vector<ll> vec(n, 0);
    for(auto &u : vec)scanf("%lld", &u);
    sort(ALL(vec));
    vec.erase(unique(ALL(vec)), vec.end());
    int tot = vec.size();
    vector<ll> diff;
    for(int i = 0; i+1 < (int)vec.size(); i++){
        diff.pb(vec[i+1]-vec[i]-1);
    }
    sort(ALL(diff));
    for(int i = 0; i < (int)diff.size(); i++){
        //printf("diff[%d]=%lld\n", i, diff[i]);
        sum[i+1] = sum[i]+diff[i];
    }
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        int cur = upper_bound(ALL(diff), r-l)-diff.begin();
        //printf("cur=%d\n", cur);
        //printf("sum=%lld\n", sum[cur]);
        printf("%lld%c", tot+sum[cur]+1LL*(tot-cur)*(r-l), " \n"[i==q-1]);
    }
    return 0;
}

