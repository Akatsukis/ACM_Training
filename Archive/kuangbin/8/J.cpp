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
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 210;
ll mp[maxn][maxn];
int n;
ll mod;

ll det()
{
    ll ret = 1;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            while(mp[j][i]){
                ll t = mp[i][i]/mp[j][i];
                for(int k = i; k < n; k++){
                    mp[i][k] = (mp[i][k]-t*mp[j][k]%mod+mod)%mod;
                }
                for(int k = i; k < n; k++){
                    swap(mp[i][k], mp[j][k]);
                }
                ret = (-ret%mod+mod)%mod;
            }
        }
        if(!mp[i][i])return 0;
        ret = (ret*mp[i][i]%mod+mod)%mod;
    }
    return ret;
}

int main()
{
    while(scanf("%d%lld", &n, &mod) != EOF){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%lld", &mp[i][j]);
                mp[i][j] = (mp[i][j]+mod)%mod;
            }
        }
        ll ans = det();
        printf("%lld\n", ans);
    }
    return 0;
}

