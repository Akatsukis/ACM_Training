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
#define Abs(x) ((x)>=0?(x):(-(x)))
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
const int maxn = 52;
bool mp[maxn][maxn];
ll G[maxn][maxn];
int n, m, k;

ll det()
{
    ll ret = 1;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            while(G[j][i]){
                ll t = G[i][i]/G[j][i];
                for(int k = i; k < n; k++){
                    G[i][k] -= G[j][k]*t;
                }
                for(int k = i; k < n; k++){
                    swap(G[i][k], G[j][k]);
                }
                ret = -ret;
            }
        }
        if(!G[i][i])return 0;
        ret *= G[i][i];
    }
    return Abs(ret);
}

int main()
{
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        memset(mp, 1, sizeof(mp));
        memset(G, 0, sizeof(G));
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            u--, v--;
            mp[u][v] = mp[v][u] = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(mp[i][j]){
                    G[i][j] = G[j][i] = -1;
                    G[i][i]++;
                    G[j][j]++;
                }
            }
        }
        ll ans = det();
        printf("%lld\n", ans);
    }
    return 0;
}

