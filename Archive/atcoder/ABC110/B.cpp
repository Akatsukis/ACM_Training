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
    int n, m, x, y;
    sc(n); sc(m); sc(x); sc(y);
    int mx = -1e9, mn = 1e9;
    for(int i = 0; i < n; i++){
        int u; sc(u);
        mx = max(mx, u);
    }
    for(int i = 0; i < m; i++){
        int u; sc(u);
        mn = min(mn, u);
    }
    int u = max(mx, x)+1;
    int v = min(mn, y);
    if(u <= v)puts("No War");
    else puts("War");
    return 0;
}

