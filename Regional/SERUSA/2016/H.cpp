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
const ll INF64 = 0x3f3f3f3f;
const int maxn = 4e5+10;
struct atom
{
    ll l, r;
    bool operator < (const atom &rhs)const
    {
        return l < rhs.l;
    }
}tb[maxn];
ll tr[maxn];
int sz;

ll query(int x)
{
    ll ret = 0;
    while(x){
        ret = max(ret, tr[x]);
        x -= x&-x;
    }
    return ret;
}

void update(int x, ll val)
{
    while(x <= sz){
        tr[x] = max(tr[x], val);
        x += x&-x;
    }
}

int main()
{
    ll n; 
    int k;
    scanf("%lld%d", &n, &k);
    vector<ll> vec;
    for(int i = 1; i <= k; i++){
        scanf("%lld%lld", &tb[i].l, &tb[i].r);
        vec.pb(tb[i].l); vec.pb(tb[i].r);
    }
    sort(tb+1, tb+1+k);
    sort(ALL(vec));
    vec.erase(unique(ALL(vec)), vec.end());
    sz = vec.size();
    ll ans = 0;
    for(int i = 1; i <= k; i++){
        int idx = lower_bound(ALL(vec), tb[i].l)-vec.begin()+1;
        int idy = lower_bound(ALL(vec), tb[i].r)-vec.begin()+1;
        ll u = query(idx-1)+tb[i].r-tb[i].l+1;
        update(idy, u);
        ans = max(ans, u);
    }
    printf("%lld\n", n-ans);
    return 0;
}


