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
const int maxn = 2e4+10;
ll a[maxn];

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
    sort(a, a+n);
    for(int i = 0; i < n-2; i++){
        if(a[i]+a[i+1] > a[i+2]){
            puts("possible");
            return 0;
        }
    }
    puts("impossible");
    return 0;
}


