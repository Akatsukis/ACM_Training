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
    int n, m;
    sc(n); sc(m);
    ll tot = 0;
    for(int i = 0; i < m; i++){
        int x, d;
        sc(x); sc(d);
        tot += (ll)n*x;
        if(d >= 0)tot += (ll)n*(n-1)/2*d;
        else{
            if(n%2)tot += (ll)(1+n/2)*(n/2)*d;
            else tot += ((ll)(1+n/2)*(n/2)-n/2)*d;
        }
    }
    double ans = (double)tot/n;
    printf("%.10f\n", ans);
    return 0;
}


