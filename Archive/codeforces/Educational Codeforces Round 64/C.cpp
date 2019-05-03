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
const int maxn = 2e5+10;
int a[maxn];

int main()
{
    int n, z;
    scanf("%d%d", &n, &z);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    sort(a, a+n);
    int l = 0, r = n/2+1;
    while(l < r-1){
        int m = (l+r)/2;
        bool ok = 1;
        for(int i = 0; i < m; i++){
            ok &= (a[i+n-m]-a[i])>=z;
        }
        if(ok)l = m;
        else r = m;
    }
    printf("%d\n", l);
    return 0;
}

