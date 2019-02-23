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

int main()
{
    int n;
    sc(n);
    vector<ll> ans;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            ll k = i;
            ll val = (n-k)*(n/k)/2+(n/k);
            ans.pb(val);
            if(n/i != i){
                ll k = n/i;
                ll val = (n-k)*(n/k)/2+(n/k);
                ans.pb(val);
            }
        }
    }
    sort(ALL(ans));
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%lld%c", ans[i], " \n"[i==(int)ans.size()-1]);
    }
    return 0;
}

