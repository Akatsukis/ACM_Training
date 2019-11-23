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
constexpr int maxn = 1e3+10;
int c[maxn], sum[maxn];
int ans[maxn];

int main()
{
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
    }
    for(int i = m; i >= 1; i--) {
        sum[i] = sum[i+1]+c[i];
    }
    int x = 0;
    for(int j = 1; j <= m; j++) {
        int nx = x+d;
        if(nx-1+sum[j] > n) {
            nx = n-sum[j]+1;
        }
        for(int k = 0; k < c[j]; k++) {
            ans[nx+k] = j;
        }
        x = nx+c[j]-1;
    }
    if(x+d > n) {
        puts("YES");
        for(int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], " \n"[i==n]);
        }
    }
    else puts("NO");
    return 0;
}

