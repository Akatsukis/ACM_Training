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
const ll mod = 1000000000;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxv = 100;
const int maxn = 11;
char s[maxn][maxn];
int mp[maxn][maxn];
ll G[maxv][maxv];
int V;

ll det()
{
    ll ret = 1;
    for(int i = 1; i < V; i++){
        for(int j = i+1; j < V; j++){
            while(G[j][i]){
                ll t = G[i][i]/G[j][i];
                for(int k = i; k < V; k++){
                    G[i][k] = (G[i][k]-t*G[j][k]%mod+mod)%mod;
                }
                for(int k = i; k < V; k++){
                    swap(G[i][k], G[j][k]);
                }
                ret = (-ret%mod+mod)%mod;
            }   
        }
        if(!G[i][i])return 0;
        ret = (ret*G[i][i]%mod+mod)%mod;
    }
    return ret;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.'){
                mp[i][j] = V++;
                if(i&&s[i-1][j]=='.'){
                    int u = mp[i][j], v = mp[i-1][j];
                    G[u][v] = G[v][u] = -1;
                    G[u][u]++;
                    G[v][v]++;
                }
                if(j&&s[i][j-1]=='.'){
                    int u = mp[i][j], v = mp[i][j-1];
                    G[u][v] = G[v][u] = -1;
                    G[u][u]++;
                    G[v][v]++;
                }
            }
        }
    }
    if(!V){
        printf("0\n");
        return 0;
    }
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            G[i][j] = (G[i][j]%mod+mod)%mod;
        }
    }
    ll ans = det();
    printf("%lld\n", ans);
    return 0;
}

