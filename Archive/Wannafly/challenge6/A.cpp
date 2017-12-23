#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

ll Findl(ll x)
{
    ll l = 0, r = 100000, res = 0;
    while(l <= r){
        ll m = (l+r)/2;
        if(m*m >= x){
            res = m;
            r = m-1;
        }
        else l = m+1;
    }
    return res;
}

ll Findr(ll x)
{
    ll l = 0, r = 100000, res = 0;
    while(l <= r){
        ll m = (l+r)/2;
        if(m*m <= x){
            res = m;
            l = m+1;
        }
        else r = m-1;
    }
    return res;
}

int main()
{
    int n;
    sc(n);
    for(int i = 0; i < n; i++){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        l = Findl(l);
        r = Findr(r);
        printf("%lld\n", r-l+1);
    }
    return 0;
}

