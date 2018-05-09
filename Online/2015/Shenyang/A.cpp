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
const int mod = 10007;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
const int maxs = 2e5+10;
const int maxb = 15;
int dp[maxn][maxs];
int base[maxb];
bool ban[maxn];
int nxt[5];

void init()
{
    base[0] = 1;
    for(int i = 1; i < maxb; i++)base[i] = base[i-1]*3;
}

int get(int state, int pos)
{
    return state/base[pos]%3;
}

void add(int &a, int b)
{
    a = (a+b)%mod;
}

int main()
{
    init();
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(dp, 0, sizeof(dp));
        memset(ban, 0, sizeof(ban));
        int n, p, k;
        sc(n); sc(p); sc(k);
        for(int i = 0; i < k; i++){
            int u; sc(u);
            ban[u-1] = 1;
        }
        nxt[0] = 0, nxt[1] = 2, nxt[2] = p+1;
        memset(dp, 0, sizeof(dp));
        int state = base[p+2];
        dp[0][state-1] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < state; j++){
                if(!dp[i][j])continue;
                if(ban[i]){
                    if(get(j, 0) == 2)add(dp[i+1][j/3+2*base[p+1]], dp[i][j]);
                    continue;
                }
                //0
                if(get(j, 0) == 2)add(dp[i+1][j/3], dp[i][j]);
                //1
                for(int u = 0; u < 3; u++){
                    if(get(j, nxt[u]) < 2){
                        int nj = j+base[nxt[u]];
                        if(get(nj, 0) == 2)add(dp[i+1][nj/3+base[p+1]], dp[i][j]);
                    }
                }
                //2
                for(int u = 0; u < 3; u++){
                    for(int v = u+1; v < 3; v++){
                        if(get(j, nxt[u]) < 2 && get(j, nxt[v]) < 2){
                            int nj = j+base[nxt[u]]+base[nxt[v]];
                            if(get(nj, 0) == 2)add(dp[i+1][nj/3+2*base[p+1]], dp[i][j]);
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n", kase++, dp[n][state-1]);
    }
    return 0;
}
