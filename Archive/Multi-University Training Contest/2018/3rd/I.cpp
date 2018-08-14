#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> VI;
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
template<class T>T _gcd(T a, T b){return b?_gcd(b, a%b):a;}
const int mod = 1e9+7;
const int maxn = 1e2+10;
const int maxS = 2e3+10;
int a[maxn], v[maxn];
int dp[2][maxS];
int id[maxn][maxn][maxn];
int gcd[maxn][maxn];
vector<VI> vec;

void init()
{
    vec.clear();
    memset(dp, 0, sizeof(dp));
}

void _init()
{
    for(int i = 1; i < maxn; i++){
        for(int j = 1; j < maxn; j++)gcd[i][j] = _gcd(i, j);
    }
}

void _add(int &a, int b)
{
    a = a+b>=mod?a+b-mod:a+b;
}

int qpow(ll a, ll n)
{
    ll ret = 1;
    while(n){
        if(n&1LL)ret = ret*a%mod;
        a = a*a%mod;
        n >>= 1;
    }
    return ret;
}

int main()
{
    _init();
    int T; sc(T);
    while(T--){
        init();
        int n, m;
        sc(n); sc(m);
        for(int i = 1; i <= n; i++)sc(a[i]);
        for(int i = 1; i <= m; i++)sc(v[i]);
        int cnt = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= i; j++){
                if(i%j != 0)continue;
                for(int k = 1; k <= j; k++){
                    if(j%k != 0)continue;
                    id[i][j][k] = cnt++;
                    vec.pb(VI{i, j, k});
                }
            }
        }
        int cur = 0, nxt = 1;
        for(int i = 1; i <= m; i++)if(a[3] == i || !a[3]){
            for(int j = 1; j <= m; j++)if(a[2] == j|| !a[2]){
                for(int k = 1; k <= m; k++)if(a[1] == k || !a[1]){
                    int x = i, y = gcd[i][j], z = gcd[y][k];
                    dp[cur][id[x][y][z]]++;
                }
            }
        }
        for(int i = 4; i <= n; i++){
            for(int j = 1; j <= m; j++)if(a[i] == j || !a[i]){
                for(int k = 0; k < SZ(vec); k++){
                    if(!dp[cur][k])continue;
                    int x = vec[k][0], y = vec[k][1], z = vec[k][2];
                    int nx = j, ny = gcd[j][x], nz = gcd[j][y];
                    _add(dp[nxt][id[nx][ny][nz]], 1LL*dp[cur][id[x][y][z]]*v[gcd[j][z]]%mod);
                }
            }
            swap(cur, nxt);
            memset(dp[nxt], 0, sizeof(dp[nxt]));
        }
        int P = 0, Q = 1;
        for(int i = 1; i <= n; i++)if(!a[i])Q = 1LL*Q*m%mod;
        for(int i = 0; i < SZ(vec); i++)_add(P, dp[cur][i]);
        int ans = 1LL*P*qpow(Q, mod-2)%mod;
        printf("%d\n", ans);
    }
    return 0;
}


