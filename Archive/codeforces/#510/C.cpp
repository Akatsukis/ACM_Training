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
const int maxn = 1e6+10;
ll a[maxn], t;
int tr[maxn];
int n, sz;

void add(int x)
{
    while(x <= sz){
        tr[x]++;
        x += x&-x;
    }
}

ll sum(int x)
{
    ll ret = 0;
    while(x){
        ret += tr[x];
        x -= x&-x;
    }
    return ret;
}

int main()
{
    scanf("%d%lld", &n, &t);
    ll tot = 0, ans = 0;
    vector<ll> vec;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        tot += a[i];
        vec.pb(tot); vec.pb(tot-t);
    }
    vec.pb(0);
    sort(ALL(vec));
    vec.erase(unique(ALL(vec)), vec.end());
    sz = vec.size(), tot = 0;
    int id = lower_bound(ALL(vec), 0)-vec.begin()+1;
    add(id);
    for(int i = 1; i <= n; i++){
        tot += a[i];
        id = lower_bound(ALL(vec), tot-t)-vec.begin()+1;
        ans += sum(sz)-sum(id);
        id = lower_bound(ALL(vec), tot)-vec.begin()+1;
        add(id);
    }
    printf("%lld\n", ans);
    return 0;
}

