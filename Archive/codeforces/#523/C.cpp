#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
const int maxn = 1e6+10;
const int mod = 1e9+7;
int mp[maxn], a[maxn];
int n;

int main()
{
    sc(n);
    int ans = 0;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        vector<pii> vec;
        for(int j = 1; j*j <= a[i]; j++){
            if(a[i]%j == 0){
                vec.pb(mk(j, mp[j-1]));
                if(a[i]/j != j)vec.pb(mk(a[i]/j, mp[a[i]/j-1]));
            }   
        }
        for(auto p : vec)mp[p.fi] = (mp[p.fi]+p.se)%mod, ans = (ans+p.se)%mod;
    }
    printf("%d\n", ans);
    return 0;
}

