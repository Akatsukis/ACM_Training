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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const int maxn = 5e5+10;
int S[maxn], X[maxn];
int sumo[maxn];
ll sum[maxn];
ll D;

//void build(int k, int l, int r)
//{
    //if(l == r-1){
        //tr[k] = sum[l];
        //return;
    //}

//}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int N, O, A, B, C, M, L;
        scanf("%d%d%lld%d%d%d%d%d%d%d", &N, &O, &D, &X[1], &X[2], &A, &B, &C, &M, &L);
        for(int i = 3; i <= N; i++){
            X[i] = (1LL*A*X[i-1]+1LL*B*X[i-2]+C)%M;
        }
        for(int i = 1; i <= N; i++){
            S[i] = X[i]+L;
            sumo[i] = sumo[i-1]+(ABS(S[i])%2==1);
            sum[i] = sum[i-1]+S[i];
        }
        ll ans = -INF64;
        for(int i = 1; i <= N; i++){
            int l = i, r = N, now = i-1;
            while(l <= r){
                int m = (l+r)>>1;
                if(sumo[m]-sumo[i-1] <= O){
                    now = m;
                    l = m+1;
                }
                else r = m-1;
            }
            ll mx = -INF64;
            for(int j = i; j <= now; j++){
                if(sum[j]-sum[i-1] <= D)mx = max(mx, sum[j]-sum[i-1]);
            }
            ans = max(ans, mx);
        }
        if(ans == -INF64)printf("Case #%d: IMPOSSIBLE\n", kase++);
        else printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}


