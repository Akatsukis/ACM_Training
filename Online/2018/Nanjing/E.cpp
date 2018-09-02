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
const int maxn = 20;
int a[maxn], b[maxn];
vector<int> vec[maxn];
bool vis[maxn];
bool used[1<<maxn];
ll dp[1<<maxn];

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++){
        int t;
        scanf("%d%d%d", &a[i], &b[i], &t);
        for(int j = 0; j < t; j++){
            int x; sc(x);
            x--;
            vec[i].pb(x);
        }
    }
    ll ans = 0;
    used[0] = 1;
    for(int i = 0; i < (1<<n); i++){
        if(!used[i])continue;
        int cnt = 1;
        for(int j = 0; j < n; j++){
            if((i>>j)&1)vis[j] = 1, cnt++;
            else vis[j] = 0;
        }
        for(int j = 0; j < n; j++){
            if((i>>j)&1)continue;
            bool ok = 1;
            for(auto v : vec[j])if(!vis[v])ok = 0;
            if(!ok)continue;
            dp[i|(1<<j)] = max(dp[i|(1<<j)], dp[i]+1LL*cnt*a[j]+b[j]);
            used[i|(1<<j)] = 1;
            ans = max(ans, dp[i|(1<<j)]);
            
        }
    }
    printf("%lld\n", ans);
    return 0;
}

