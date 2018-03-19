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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 4e5+10;
map<int, int> mp;
int n, m;

ll solve(int x, int l)
{
    ll ret = 1LL*l*(l+1)/2;
    int num = x;
    vector<int> v;
    for(int i = 2; i*i <= num; i++){
        if(num%i==0){
            v.pb(i);
            while(num%i==0)num/=i;
        }
    }
    if(num != 1)v.pb(num);
    int sz = v.size();
    for(int i = 1; i < (1<<sz); i++){
        int sgn = 1, now = 1;
        for(int j = 0; j < sz; j++){
            if((i>>j)&1){
                now *= v[j];
                sgn *= -1;
            }
        }
        int u = l/now;
        ret += 1LL*sgn*(now+now*u)*u/2;
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        mp.clear();
        scanf("%d%d", &n, &m);
        int t, l, r, u;
        for(int i = 0; i < m; i++){
            sc(t);
            if(t == 1){
                sc(l); sc(r); sc(u);
                ll ans = solve(u, r)-solve(u, l-1);
                for(auto it : mp){
                    int x = it.fi, y = it.se;
                    if(x >= l && x <= r){
                        if(gcd(x, u) == 1)ans -= x;
                        if(gcd(y, u) == 1)ans += y;
                    }   
                }   
                printf("%lld\n", ans);
            }
            else{
                sc(l); sc(u);
                mp[l] = u;
            }
        }
    }
    return 0;
}

