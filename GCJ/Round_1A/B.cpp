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
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
ll n, m, k;
ll M[maxn], S[maxn], P[maxn];

bool solve(ll t)
{
    ll tmp[maxn];
    for(int i = 0; i < k; i++){
        if(t-P[i] < 0)tmp[i] = 0;
        else{
            tmp[i] = (t-P[i])/S[i];
            tmp[i] = min(tmp[i], M[i]);
        }
    }
    sort(tmp, tmp+k);
    ll now = 0;
    for(int i = k-1; i >= k-n; i--){
        now += tmp[i];
    }
    return now >= m;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        scanf("%lld%lld%lld", &n, &m, &k);
        for(int i = 0; i < k; i++){
            scanf("%lld%lld%lld", &M[i], &S[i], &P[i]);
        }
        ll l = 0, r = INF64, ans = 0;
        while(l <= r){
            ll mid = (l+r)>>1;
            if(solve(mid)){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

