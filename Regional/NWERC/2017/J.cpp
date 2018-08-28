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
const int maxn = 1e5+10;
ll a[maxn], b[maxn], ans[3];
ll sum[3];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);
    for(int i = 1; i <= n; i++)scanf("%lld", &b[i]);
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j <= n; j += 3)sum[i] += a[j];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 3; j++){
            ans[j] += b[i]*sum[(j-i%3+2)%3];
        }
    }
    for(int i = 0; i < 3; i++)printf("%lld%c", ans[i], " \n"[i==2]);
    return 0;
}
