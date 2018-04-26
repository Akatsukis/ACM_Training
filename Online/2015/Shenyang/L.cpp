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
const int maxn = 5e6+10;
ll t[maxn];
struct Node
{
    ll x;
    int id;
    bool operator < (const Node &rhs)
    {
        return x < rhs.x;
    }
}ans1[maxn], ans2[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n;
        ll a, b;
        scanf("%d%lld%lld", &n, &a, &b);
        for(int i = 0; i < n; i++){
            scanf("%lld", &t[i]);
            ans1[i].id = ans2[i].id = i;
            ans1[i].x = a*t[i]*t[i]; ans2[i].x = b*t[i];
        }
        sort(ans1, ans1+n);
        sort(ans2, ans2+n);
        ll ans;
        if(ans1[n-1].id != ans2[n-1].id)ans = ans1[n-1].x + ans2[n-1].x;
        else ans = max(ans1[n-1].x+ans2[n-2].x, ans1[n-2].x+ans2[n-1].x);
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

