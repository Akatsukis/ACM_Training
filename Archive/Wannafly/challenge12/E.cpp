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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 10;
int val[maxn];
int S[maxn];
int V[maxn];
int a, b, n, u, v;

int main()
{
    int st = clock();
    scanf("%d%d%d", &a, &b, &n);
    memset(val, INF, sizeof(val));
    for(int i = 0; i < n; i++)sc(S[i]);
    for(int i = 0; i < n; i++)sc(V[i]);
    for(int i = 0; i < n; i++)val[S[i]] = min(val[S[i]], V[i]);
    scanf("%d%d", &u, &v);
    int c = gcd(a, b);
    ll mn = INF64;
    ll ans = -1, now = 10;
    if(u == v && u%c == 0 && val[u] != INF){
        ans = u, mn = val[u];
        if(u == 0){
            printf("%d\n", 0);
            return 0;
        }
    }
    for(; clock()-st<1.8*CLOCKS_PER_SEC; now *= 10){
        ll num = u*now+v;
        while(num/now==u && num%c && clock()-st<1.8*CLOCKS_PER_SEC){
            num += 10;
        }
        while(num/now == u && clock()-st<1.8*CLOCKS_PER_SEC){
            ll tmp = num, cnt = 0;
            while(tmp){
                if(val[tmp%10]==INF)break;
                else cnt += val[tmp%10];
                tmp /= 10;
            }
            if(!tmp && cnt < mn){
                mn = cnt;
                ans = num;
            }
            num += c*10;
        }
    }
    printf("%lld\n", ans);
    return 0;
}

