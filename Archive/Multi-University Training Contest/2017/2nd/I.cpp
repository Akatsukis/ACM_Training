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
#define fi first
#define se second
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
const int maxn = 2e5;
int n;
int a[maxn];
int num[maxn];
int pre[maxn];
int prime[10000];
bool vis[maxn];
int cnt[maxn];

void init()
{
    int cur = 0;
    for(int i = 2; i < maxn; i++){
        if(!vis[i]){
            prime[cur++] = i;
            for(int j = i*2; j < maxn; j += i){
                vis[j] = 1;
            }
        }
    }
}

ll quick(ll b, int m)
{
    ll res = 1;
    while(m){
        if(m&1)res = (res * b) % mod;
        b = b*b%mod;
        m >>= 1;
    }
    return res;
}

ll cal(int t, int mx)
{
    ll res = 1;
    for(int i = t, j = 1; i <= mx; i += t, j++){
        int cur = pre[i+t-1] - pre[i-1];
        if(cur){
            res *= quick(j, cur);
            res %= mod;
            //printf("%d %d\n", j, cur);
        }
        //printf("res:%lld\n", res);
        //printf("pre[%d]-pre[%d]=%d\n", i+t-1, i-1, pre[i+t-1]-pre[i-1]);
    }
    return res % mod;
}

int main()
{
#ifdef Akatsuki
    frein;
    freout;
#endif
    init();
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(cnt, 0, sizeof(cnt));
        memset(pre, 0, sizeof(pre));
        memset(num, 0, sizeof(num));
        sc(n);
        int mn = INF, mx = 0;
        for(int i = 0; i < n; i++){
            sc(a[i]);
            num[a[i]]++;
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        for(int i = 1; i < maxn; i++)pre[i] = pre[i - 1] + num[i];
        ll ans = 0;
        for(int i = 2; i <= mn; i++){
            //printf("cnt[%d]:%d\n", i, cnt[i]);
            if(cnt[i] != 1){
                ll tmp = cal(i, mx);
                int tb = 1 - cnt[i];
                ans += tmp * tb;
                ans = (ans+mod)%mod;
                for(int j = i; j <= mn; j += i){
                    cnt[j] += tb;
                }
            }
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}


