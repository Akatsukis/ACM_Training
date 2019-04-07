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
    vector<ll> vec(n, 0);
    for(auto &u : vec)scanf("%lld", &u);
    ll two = 0, ans = 0;
    for(int i = n-1; i >= 0; i--){
        two += vec[i]/2;
        if(vec[i]%2 && two)two--, ans++;
    }
    ans += two*2/3;
    printf("%lld\n", ans);
    return 0;
}

