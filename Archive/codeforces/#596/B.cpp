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
constexpr int maxn = 1e5+10;
int cnt[maxn];
int a[maxn];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int res = 1, ask = 1;
        for(int j = 2; a[i] != 1; j++) {
            if(j*j > a[i]) {
                j = a[i];
            }
            if(a[i]%j == 0) {
                int num = 0;
                while(a[i]%j == 0) {
                    a[i] /= j;
                    num++;
                }
                num %= k;
                for(int u = 0; u < num; u++) {
                    res *= j;
                }
                for(int u = 0; u < (k-num)%k; u++) {
                    ask = min(1LL*ask*j, maxn-1LL);
                }
            }
        }
        ans += cnt[ask];
        cnt[res]++;
    }
    printf("%lld\n", ans);
    return 0;
}

