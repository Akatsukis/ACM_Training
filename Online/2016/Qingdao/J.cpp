#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
map<int, ll> mp;
struct Bag
{
    int w, v;
}bag[maxn];
int n, T;
vector<int> v;

bool cmp(const Bag &lhs, const Bag &rhs)
{
    return lhs.v > rhs.v;
}

int main()
{
    while(scanf("%d%d", &n, &T) != EOF){
        mp.clear();
        for(int i = 0; i < n; i++){
            sc(bag[i].w); sc(bag[i].v);
        }
        sort(bag, bag+n, cmp);
        ll ans = 0; mp[0] = 0;
        for(int i = 0; i < n; i++){
            if(bag[i].w > T || bag[i].w <= 0)continue;
            v.clear();
            ll mx = 0;
            for(auto it : mp){
                if(it.se+bag[i].v > mx && it.fi+bag[i].w <= T){
                    v.pb(it.fi+bag[i].w);
                    mx = max(mx, it.se+bag[i].v);
                }
            }
            for(auto &u : v){
                mp[u] = max(mp[u], mp[u-bag[i].w]+bag[i].v);
                ans = max(ans, mp[u]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

