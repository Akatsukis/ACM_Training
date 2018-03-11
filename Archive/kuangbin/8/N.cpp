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
const int maxn = 15;
ll mat[maxn][maxn];
int n, m;

ll det()
{
    ll ret = 1;
    for(int i = 1; i < n; i++){
        for(int j = i+1; j < n; j++){
            while(mat[j][i]){
                ll t = mat[i][i]/mat[j][i];
                for(int k = i; k < n; k++){
                    mat[i][k] -= mat[j][k]*t;
                }
                for(int k = i; k < n; k++){
                    swap(mat[i][k], mat[j][k]);
                }
                ret = -ret;
            }
        }
        if(!mat[i][i])return 0;
        ret *= mat[i][i];
    }
    return (ret>=0?ret:-ret);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        memset(mat, 0, sizeof(mat));
        sc(n); sc(m);
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            mat[u][v] = mat[v][u] = -1;
            mat[u][u]++;
            mat[v][v]++;
        }
        ll ans = det();
        printf("%lld\n", ans);
    }
    return 0;
}

