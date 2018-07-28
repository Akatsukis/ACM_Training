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
const int INF = 0x3f3f3f3f;
const int maxn = 30;
int sumr[maxn], sumc[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(sumr, 0, sizeof(sumr));
        memset(sumc, 0, sizeof(sumc));
        int n, m;
        sc(n); sc(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int x; sc(x);
                sumr[i] += x;
                sumc[j] += x;
            }
        }
        int ans = INF;
        for(int i = 0; i <= 400; i++){
            for(int j = 0; j <= 400; j++){
                if(i*n != j*m)continue;
                int now1 = 0, now2 = 0;
                for(int k = 0; k < n; k++)now1 += ABS(sumr[k]-i);
                for(int k = 0; k < m; k++)now2 += ABS(sumc[k]-j);
                int now = max(now1, now2);
                ans = min(ans, now);
            }
        }
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}


