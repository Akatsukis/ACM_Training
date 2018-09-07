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
    int s, p;
    sc(s); sc(p);
    int ans = 0;
    if(p-s >= 1800)ans = 4;
    else if(p-s >= 900)ans = 3;
    else if(p-s >= 300)ans = 2;
    else if(p-s > 0)ans = 1;
    else ans = 0;
    printf("%d\n", ans);
    return 0;
}

