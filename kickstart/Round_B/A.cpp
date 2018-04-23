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
const int maxn = 50;
int bit[maxn];
ll dp[maxn];

ll dfs(int pos, bool bound, int now)
{
    //printf("dfs(%d,%d,%d)\n", pos, (int)bound, now);
    if(pos == -1){
        if(now%9==0)return 0;
        else return 1;
    }
    if(!bound && dp[pos] != -1)return dp[pos];
    ll ret = 0;
    int to = bound?bit[pos]:9;
    for(int i = 0; i <= to; i++){
        if(i == 9)continue;
        ret += dfs(pos-1, bound && i == to, now+i);
    }
    if(!bound)dp[pos] = ret;
    return ret;
}

ll solve(ll t)
{
    int cnt = 0;
    while(t){
        bit[cnt++] = t%10;
        t /= 10;
    }
    return dfs(cnt-1, 1, 0);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int T, kase = 1;
    sc(T);
    while(T--){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        ll ans = solve(r)-solve(l-1);
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

