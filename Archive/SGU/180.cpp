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
int a[maxn], tr[maxn];
int n, sz;

int query(int x)
{
    int ret = 0;
    while(x){
        ret += tr[x];
        x -= x&-x;
    }
    return ret;
}

void add(int x)
{
    while(x <= sz){
        tr[x]++;
        x += x&-x;
    }
}

int main()
{
    sc(n);
    vector<int> vec;
    for(int i = 1; i <= n; i++)sc(a[i]), vec.pb(a[i]);
    sort(ALL(vec));
    vec.erase(unique(ALL(vec)), vec.end());
    sz = vec.size();
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int id = lower_bound(ALL(vec), a[i])-vec.begin()+1;
        ans += query(sz)-query(id);
        add(id);
    }
    printf("%lld\n", ans);
    return 0;
}

