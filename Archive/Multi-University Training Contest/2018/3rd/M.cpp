#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> VI;
typedef vector<VI> mat;
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
const int INF = 0x3f3f3f3f;
const int maxk = 101, maxn = 50;

mat operator * (const mat &lhs, const mat &rhs)
{
    int n = lhs.size();
    mat ret(n, VI(n, INF));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ret[i][j] = min(ret[i][j], lhs[i][k]+rhs[k][j]);
            }
        }
    }
    return ret;
}

int main()
{
    int T; sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        vector<mat> A(maxk, mat(n, VI(n, INF))), B(maxk, mat(n, VI(n, INF)));
        mat G(n, VI(n, INF));
        for(int i = 0; i < n; i++){
            A[0][i][i] = B[0][i][i] = 0;
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            u--, v--;
            G[u][v] = min(G[u][v], w);
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);
                }
            }
        }
        for(int i = 1; i < maxk; i++)B[i] = B[i-1]*G;
        for(int i = 1; i < maxk; i++)A[i] = A[i-1]*B[100];
        int q; sc(q);
        for(int i = 0; i < q; i++){
            int s, t, k;
            sc(s); sc(t); sc(k);
            s--, t--;
            int a = k/100, b = k%100;
            int ans = INF;
            for(int j = 0; j < n; j++)ans = min(ans, A[a][s][j]+B[b][j][t]);
            if(ans == INF)puts("-1");
            else printf("%d\n", ans);
        }
    }
    return 0;
}


