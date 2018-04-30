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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int maxn = 510;
ll dp[maxn][2][2][2];
ll mod;

ll dfs(int n, int adv, int a, int b)
{
    ll &ret = dp[n][adv][a][b];
    if(~ret)return ret;
    else ret = 0;
    if(a && b){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                int now = num[i]+num[j]+num[(i+j+adv)%10];
                if(now > n)continue;
                int nadv = (i+j+adv)/10;
                ret = (ret+dfs(n-now, nadv, 1, 1))%mod;
                if(i)ret = (ret+dfs(n-now, nadv, 0, 1))%mod;
                if(j)ret = (ret+dfs(n-now, nadv, 1, 0))%mod;
                if(i&&j)ret = (ret+dfs(n-now, nadv, 0, 0))%mod;
            }
        }
    }
    else if(a){
        for(int i = 0; i < 10; i++) {
            int now = num[i]+num[(i+adv)%10];
            if(now > n)continue;
            int nadv = (i+adv)/10;
            ret = (ret+dfs(n-now, nadv, 1, 0))%mod;
            if(i)ret = (ret+dfs(n-now, nadv, 0, 0))%mod;
        }
    }
    else if(b){
        for(int j = 0; j < 10; j++){
            int now = num[j]+num[(j+adv)%10];
            if(now > n)continue;
            int nadv = (j+adv)/10;
            ret = (ret+dfs(n-now, nadv, 0, 1))%mod;
            if(j)ret = (ret+dfs(n-now, nadv, 0, 0))%mod;
        }
    }
    else{
        if(adv && n == 2)ret = 1;
        else if(!adv && n == 0)ret = 1;
        else ret = 0;
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n;
        memset(dp, -1, sizeof(dp));
        scanf("%d%lld", &n, &mod);
        n -= 3;
        printf("Case #%d: %lld\n", kase++, dfs(n, 0, 1, 1));
    }
    return 0;
}

