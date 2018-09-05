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
const int maxn = 1e4+10;
vector<int> prime, sp;
set<int> st;
int dp[maxn];
int pre[maxn];
bool vis[maxn];

int main()
{
    int n; sc(n);
    vis[1] = 1;
    for(int i = 2; i <= n; i++){
        if(!vis[i])prime.pb(i);
        for(int j = 0; j < SZ(prime) && i*prime[j] <= n; j++){
            vis[i*prime[j]] = 1;
            if(i%prime[j] == 0)break;
        }
    }
    for(int i = 0; i < SZ(prime); i++){
        if(!vis[i+1])sp.pb(prime[i]), st.insert(prime[i]);
    }
    int m = sp.size();
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i < m; i++){
        for(int j = sp[i]; j <= n; j++){
            if(dp[j] > dp[j-sp[i]]+1){
                dp[j] = dp[j-sp[i]]+1;
                pre[j] = j-sp[i];
            }
        }
    }
    if(pre[n] == 0 && !st.count(n)){
        puts("0");
        return 0;
    }
    vector<int> ans;
    for(int i = n; i; i = pre[i])ans.pb(i-pre[i]);
    printf("%d\n", SZ(ans));
    for(int i = 0; i < SZ(ans); i++)printf("%d%c", ans[i], " \n"[i==SZ(ans)-1]);
    return 0;
}

