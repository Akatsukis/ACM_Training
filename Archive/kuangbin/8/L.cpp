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
const int mod = 10007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 310;
int G[maxn][maxn];
int x[maxn];
int y[maxn];
int n, r;

bool same(int i, int j, int k)
{
    return (x[i]-x[j])*(y[j]-y[k])==(x[j]-x[k])*(y[i]-y[j])
    && x[k]>=min(x[i], x[j]) && x[k]<=max(x[i], x[j])
    && y[k]>=min(y[i], y[j]) && y[k]<=max(y[i], y[j]);
}

int det()
{
    int ret = 1;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            while(G[j][i]){
                int t = G[i][i]/G[j][i];
                for(int k = i; k < n; k++){
                    G[i][k] = (G[i][k]-t*G[j][k])%mod;
                }
                for(int k = i; k < n; k++){
                    swap(G[i][k], G[j][k]);
                }
                ret = -ret;
            }
        }
        if(!G[i][i])return -1;
        ret = ret*G[i][i]%mod;
    }
    return (ret+mod)%mod;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        memset(G, 0, sizeof(G));
        sc(n); sc(r);
        for(int i = 0; i < n; i++){
            sc(x[i]); sc(y[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(sqr(x[i]-x[j])+sqr(y[i]-y[j])<=r*r){
                    bool flg = 1;
                    for(int k = 0; k < n; k++){
                        if(k != i && k != j && same(i, j, k)){
                            flg = 0;
                            break;
                        }
                    }
                    if(flg){
                        G[i][j] = G[j][i] = -1;
                        G[i][i]++;
                        G[j][j]++;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                G[i][j] %= mod;
            }
        }
        int ans = det();
        printf("%d\n", ans);
    }
    return 0;
}
