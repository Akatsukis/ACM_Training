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
    int n, d;
    sc(n); sc(d);
    int q; sc(q);
    for(int i = 0; i < q; i++){
        int x, y;
        sc(x); sc(y);
        if(y >= x-d && y <= x+d && y >= -x+d && y <= -x+2*n-d)puts("YES");
        else puts("NO");
    }
    return 0;
}

