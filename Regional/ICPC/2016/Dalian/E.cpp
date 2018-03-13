#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fst fi
#define scd se
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
ll lowbit(ll i)
{
    return i&(-i);
}

ll query(ll x, ll n)
{
    ll ans = 0;
    while(x <= n){
        x += lowbit(x);
        ans++;
    }
    return ans;
}

ll cal(ll x)
{
    ll ans = 0, pre = 0;
    for(int i = 63; i >= 0; i--){
        int now = x / (1LL << i);
        now -= pre;
        pre += now;
        ans += now * (1LL << i);
    }
    return ans;
}


int main()
{
    ll n;
    int q;
    while(scanf("%lld%d", &n, &q) != EOF){
        for(int i = 0; i < q; i++){
            int k;
            sc(k);
            if(k == 1){
                ll l, r;
                scanf("%lld%lld", &l, &r);
                ll ans = cal(r) - cal(l - 1);
                //printf("cal(%lld)=%lld cal(%lld)=%lld\n", r, cal(r), l - 1, cal(l - 1));
                printf("%lld\n", ans);
            }
            else{
                ll x;
                scanf("%lld", &x);
                ll ans = query(x, n);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}


