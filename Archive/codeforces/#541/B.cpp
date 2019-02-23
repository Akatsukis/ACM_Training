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
    int n, pa = 0, pb = 0, lst = 0;
    sc(n);
    int ans = 1;
    for(int i = 0; i < n; i++){
        int a, b;
        sc(a); sc(b);
        int l = max(lst+1, max(pa, pb)), r = min(a, b);
        //printf("l=%d, r=%d, lst=%d\n", l, r, lst);
        if(r >= l)lst = r, ans += r-l+1;
        pa = a, pb = b;
    }
    printf("%d\n", ans);
    return 0;
}

