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
string s, t;
int n, k;

int main()
{
    sc(n); sc(k);
    cin >> s >> t;
    ll u = 0, v = 0, pre = 0, ans = 0;
    for(int i = 0; i < n && k; i++){
        u = u*2+s[i]-'a', v = v*2+t[i]-'a';
        //printf("u=%lld, v=%lld\n", u, v);
        ll cur = min(1LL*k, v-u+1-pre);
        k -= cur; pre += cur;
        ans += cur*(n-i);
        //printf("ans+=%lld*%d\n", cur, n-i);
    }
    printf("%lld\n", ans);
    return 0;
}

