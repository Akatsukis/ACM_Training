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

int solve(int p, int a, int b, int l)
{
    if(a > l)return p;
    int y = b;
    b += a;
    b += max(0, (2*y-b+a-1)/a)*a;
    while(b < 2*y)b += a;
    return solve(p^1, b, a, l);
}

int main()
{
    int a, b, l;
    scanf("%d%d%d", &a, &b, &l);
    int ans = solve(0, a, b, l);
    if(!ans)printf("Yes ");
    else printf("No ");
    ans = solve(0, b, a, l);
    if(!ans)printf("No\n");
    else printf("Yes\n");
    return 0;
}

