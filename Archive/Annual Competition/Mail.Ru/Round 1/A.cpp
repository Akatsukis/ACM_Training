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
    int x, y, z, t1, t2, t3;
    scanf("%d%d%d%d%d%d", &x, &y, &z, &t1, &t2, &t3);
    int ans1 = ABS(z-x)*t2+ABS(x-y)*t2+3*t3;
    int ans2 = ABS(x-y)*t1;
    if(ans1 <= ans2)puts("YES");
    else puts("NO");
    return 0;
}

