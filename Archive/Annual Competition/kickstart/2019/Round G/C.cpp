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
const int maxn = 21;
int a[maxn], b[maxn];
long long val[1<<maxn];

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        memset(val, 0, sizeof(val));
        int n, h;
        scanf("%d%d", &n, &h);
        for(int i = 0; i < n; i++) {    
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++) {    
            scanf("%d", &b[i]);
        }
        for(int i = 0; i < (1<<n); i++) {
            long long tot = 0;
            for(int j = 0; j < n; j++) {
                if(i>>j&1) {
                    tot += a[j];
                }
            }
            if(tot >= h) {
                val[i]++;
            }
        }
        for(int i = 0; i < maxn; i++) {
            for(int j = 0; j < (1<<n); j++) {
                if(j>>i&1) {
                    val[j^(1<<i)] += val[j];
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < (1<<n); i++) {
            long long tot = 0;
            int state = 0;
            for(int j = 0; j < n; j++) {
                if(i>>j&1) {
                    tot += b[j];
                }
                else state |= 1<<j;
            }
            if(tot >= h) {
                ans += val[state];
            }
        }
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

