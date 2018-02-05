#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

ll cal(ll x, vector<int> v)
{
   // printf("x:%lld\n", x);
    int n = v.size();
    ll res = x;
    for(int i = 1; i < (1<<n); i++){
        int sgn = -1;
        ll cnt = 1;
        for(int j = 0; j < n; j++){
            if(i>>j&1){
                sgn *= -1;
                cnt *= v[j];
                //printf("cnt:%lld\n", cnt);
            }
        }
        res -= sgn*(x/cnt);
    }
    return res;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        ll x, p, k;
        scanf("%lld%lld%lld", &x, &p, &k);
        vector<int> fac;
        for(int i = 2; (ll)i*i <= p; i++){
            if(p%i==0){
                fac.pb(i);
                while(p%i==0)p/=i;
            }
        }
        if(p>1)fac.pb(p);
        k += cal(x, fac);
        ll l = 1, r = 1e12, ans = 1;
        while(l <= r){
            ll m = (l+r)/2;
            if(cal(m, fac) >= k){
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        printf("%lld\n", ans);
    }
	return 0;
}

