#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%hd", &x)
#define pb push_back
const int maxn = 37;
short dp[maxn][maxn][maxn][maxn];
bool vis[maxn][maxn][maxn][maxn][maxn];
short p[maxn], a[maxn], c[maxn], m[maxn], g[maxn];

int main()
{
    short n; sc(n);
    for(short i = 0; i < n; i++){
        sc(p[i]); sc(a[i]); sc(c[i]); sc(m[i]); sc(g[i]);
    }
    short pm, am, cm, mm;
    scanf("%hd%hd%hd%hd", &pm, &am, &cm, &mm);
    for(short i = 0; i < n; i++){
        for(short j = pm; j >= p[i]; j--){
            for(short k = am; k >= a[i]; k--){
                for(short h = cm; h >= c[i]; h--){
                    for(short l = mm; l >= m[i]; l--){
                        if(dp[j][k][h][l] < dp[j-p[i]][k-a[i]][h-c[i]][l-m[i]]+g[i]){
                            dp[j][k][h][l] = dp[j-p[i]][k-a[i]][h-c[i]][l-m[i]]+g[i];
                            vis[i][j][k][h][l] = 1;
                        }
                    }
                }
            }
        }
    }
    vector<short> ans;
    for(short i = n-1, j = pm, k = am, h = cm, l = mm; i >= 0; i--){
        if(vis[i][j][k][h][l]){
            ans.pb(i);
            j -= p[i];
            k -= a[i];
            h -= c[i];
            l -= m[i];
        }
    }
    short sz = (short)ans.size();
    printf("%hd\n", sz);
    for(short i = 0; i < sz; i++){
        printf("%hd%c", ans[i], " \n"[i==sz-1]);
    }
}
