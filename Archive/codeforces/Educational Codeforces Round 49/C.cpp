#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> VI;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+10;
map<int, int> mp;

int main()
{
    int T; sc(T);
    while(T--){
        mp.clear();
        int n; sc(n);
        bool flg = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int x; sc(x);
            mp[x]++;
            if(mp[x] >= 4){
                flg = 1;
                ans = VI{x, x, x, x};
            }
        }
        if(flg){
            printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
            continue;
        }
        vector<int> vec;
        for(auto p : mp){
            if(p.se >= 2)vec.pb(p.fi);
        }
        ll u = INF, v = 1;
        for(int i = 0; i < SZ(vec)-1; i++){
            ll a = sqr(2LL*(vec[i]+vec[i+1])), b = 1LL*vec[i]*vec[i+1];
            if(a*v < u*b){
                u = a, v = b;
                ans = VI{vec[i], vec[i], vec[i+1], vec[i+1]};
            }
        }
        printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
    }
    return 0;
}


