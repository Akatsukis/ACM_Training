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
const int maxn = 7e3+10;
map<ll, int> mp;
ll a[maxn];
int n;

int main()
{
    int T, kase = 1; 
    sc(T);
    while(T--){
        mp.clear();
        sc(n);
        int zero = 0;
        for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
        for(int i = 0; i < n; i++){
            if(!a[i])zero++;
        }
        sort(a, a+n, greater<ll>());
        ll ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(mp.count(a[i]*a[j]))ans += mp[a[i]*a[j]];
            }
            mp[a[i]]++;
        }
        ans += 1LL*zero*(zero-1)/2*(n-zero);
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}


