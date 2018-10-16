#include <bits/stdc++.h>
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ALL(A) A.begin(),A.end()
#define fi first
#define se second
#define sc(x) scanf("%d",&x)
#define pr(x) printf(#x":%d\n", x)
#define Abs(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
template<class T>T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int n;
pii p[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++){
            sc(p[i].se); sc(p[i].fi);
        }
        sort(p, p+n);
        ll now = 0, ans = 0;
        for(int i = 0; i < n; i++){
            now += p[i].se;
            //printf(">>%lld fi=%lld\n", now, p[i].fi);
            if(now > p[i].fi)ans = max(ans, now-p[i].fi);
        }
        printf("Case %d: %lld\n", kase++, ans);
    }
    return 0;
}
