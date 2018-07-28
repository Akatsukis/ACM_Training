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
const int maxn = 30;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n, m, p, q;
        scanf("%d%d%d%d", &n, &m, &p, &q);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)sc(a[i][j]);
        }
        for(int i = 0; i < p; i++){
            for(int j = 0; j < q; j++)sc(b[i][j]);
        }
        printf("Case %d:\n", kase++);
        if(m != p)puts("ERROR");
        else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < q; j++){
                    c[i][j] = 0;
                    for(int k = 0; k < m; k++){
                        c[i][j] += a[i][k]*b[k][j];
                    }
                }
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < q; j++)printf("%d%c", c[i][j], " \n"[j==q-1]);
            }
        }
    }
    return 0;
}


