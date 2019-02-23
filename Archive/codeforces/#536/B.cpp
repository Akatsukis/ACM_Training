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
const int maxn = 1e5+10;
int a[maxn], c[maxn];
int n, m;
set<pii> st;

int main()
{
    sc(n); sc(m);
    for(int i = 1; i <= n; i++)sc(a[i]);
    for(int i = 1; i <= n; i++)sc(c[i]), st.insert(mk(c[i], i));
    for(int i = 0; i < m; i++){
        int t, d;
        sc(t); sc(d);
        ll ans = 0;
        if(a[t]){
            int used = min(d, a[t]);
            st.erase(mk(c[t], t));
            d -= used, a[t] -= used, ans += 1LL*used*c[t];
            if(a[t])st.insert(mk(c[t], t));
        }
        while(!st.empty() && d){
            auto it = *st.begin(); t = it.se;
            int used = min(d, a[t]);
            st.erase(mk(c[t], t));
            d -= used, a[t] -= used, ans += 1LL*used*c[t];
            if(a[t])st.insert(mk(c[t], t));
        }
        if(d)ans = 0;
        printf("%lld\n", ans);
    }    
    return 0;
}

