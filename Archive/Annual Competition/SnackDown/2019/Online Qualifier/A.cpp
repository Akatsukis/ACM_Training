#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
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
const int maxn = 1e5+10;
int a[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        int n, k;
        sc(n); sc(k);
        for(int i = 0; i < n; i++)sc(a[i]);
        sort(a, a+n, greater<int>());
        int ans = k;
        for(int i = k; i < n; i++){
            if(a[i] == a[k-1])ans++;
            else break;
        }
        printf("%d\n", ans);
    }
    return 0;
}

