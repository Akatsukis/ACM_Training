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
const int maxn = 5010;
char s[maxn][maxn];
char words[maxn][maxn];
int mat[maxn][maxn];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(mat, 0, sizeof(mat));
        int R, C, W;
        scanf("%d%d%d", &R, &C, &W);
        for(int i = 1; i <= R; i++){
            scanf("%s", s[i]+1);
        }
        for(int i = 0; i < W; i++){
            scanf("%s", words[i]);
        }
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                for(int k = 0; k < W; k++){
                    if(s[i][j] == words[k][0])mat[i][j]++;
                }
            }
        }
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                mat[i][j] = mat[i][j]+mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
        }
        pii ans = mk(0, 1);
        int cnt = 0;
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                for(int k = i; k <= R; k++){
                    for(int l = j; l <= C; l++){
                        int tot = mat[k][l]-mat[i-1][l]-mat[k][j-1]+mat[i-1][j-1];
                        tot *= 4;
                        int len = (k-i+1)+(l-j+1);
                        int d = gcd(tot, len);
                        tot /= d, len /= d;
                        if(tot*ans.se > len*ans.fi){
                            ans = mk(tot, len);
                            cnt = 1;
                        }
                        else if(tot*ans.se == len*ans.fi)cnt++;
                    }
                }
            }
        }
        printf("Case #%d: %d/%d %d\n", kase++, ans.fi, ans.se, cnt);
    }
    return 0;
}


