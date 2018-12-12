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
    int n, k;
    sc(n); sc(k);
    multiset<ll> st;
    for(int i = 0; i < n; i++){
        int x; sc(x);
        st.insert(x);
    }
    ll sub = 0;
    for(int i = 0; i < k; i++){
        if(st.empty()){
            puts("0");
            continue;
        }
        auto it = st.begin();
        ll val = max(0LL, *it-sub);
        st.erase(it);
        if(!val){
            i--;
            continue;
        }
        printf("%lld\n", val);
        sub += val;
    }
    return 0;
}
