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
int x1[maxn], x2[maxn];
int sum[maxn];
int n, h;

int main()
{
    sc(n); sc(h);
    for(int i = 1; i <= n; i++){
        scanf("%d%d", &x1[i], &x2[i]);
        sum[i] = sum[i-1]+x2[i]-x1[i];
    }
    int ans = h;
    for(int i = 1; i <= n; i++){
        int l = i, r = n;
        while(l <= r){
            int m = (l+r)/2;
            int used = (x2[m]-x1[i])-(sum[m]-sum[i-1]);
            if(used < h){
                ans = max(ans, x2[m]-x1[i]+h-used); 
                l = m+1;
            }
            else r = m-1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

