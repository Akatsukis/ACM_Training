#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 210;
int ans[maxn];
int sum[maxn];
int abr[maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(ans, 0, sizeof(ans));
        memset(sum, 0, sizeof(sum));
        memset(abr, 0, sizeof(abr));
        int n, k;
        ll p;
        scanf("%d%d%lld", &n, &k, &p);
        for(int i = 1; i <= n; i++)abr[i] = 1;
        for(int i = 0; i < k; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            abr[u] = 0;
            ans[u] = w;
        }
        sum[n+1] = 0;
        for(int i = n; i >= 1; i--){
            sum[i] = sum[i+1]+abr[i];
        }
        for(int i = 1; i <= n; i++){
            if(!abr[i])continue;
            else{
                if(sum[i+1] < 63 && p > (1LL<<sum[i+1])){
                    p -= (1LL<<sum[i+1]);
                    ans[i] = 1;
                }
                else ans[i] = 0;
            }
        }
        printf("Case #%d: ", kase++);
        for(int i = 1; i <= n; i++)printf("%d", ans[i]);
        puts("");
    }
    return 0;
}

