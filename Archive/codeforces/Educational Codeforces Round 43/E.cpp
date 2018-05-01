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
const int maxn = 2e5+10;
int n, a, b;
ll hp[maxn], dmg[maxn];
struct atom
{
    ll x;
    int id;
    bool operator < (const atom &rhs)const
    {
        return x > rhs.x;
    }
}add[maxn];
bool vis[maxn];

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld", &hp[i], &dmg[i]);
        ans += dmg[i];
    }
    if(!b){
        printf("%lld\n", ans);
        return 0;
    }
    for(int i = 1; i <= n; i++){
        add[i].x = max(0LL, hp[i]-dmg[i]);
        add[i].id = i;
    }
    sort(add+1, add+1+n);
    for(int i = 1; i <= min(n, b); i++)vis[add[i].id] = 1, ans += add[i].x;
    ll min_add = add[min(n, b)].x;
    ll mx = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i]){
            ll now = hp[i]*(1<<a)-max(hp[i], dmg[i]);
            mx = max(mx, now);
        }
        else{
            ll now = hp[i]*(1<<a)-dmg[i]-min_add;
            mx = max(mx, now);
        }
    }
    ans += mx;
    printf("%lld\n", ans);
    return 0;
}

