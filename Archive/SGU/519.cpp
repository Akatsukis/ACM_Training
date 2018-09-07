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
const int maxn = 1e2+10;
int mat[maxn][maxn];
char s[maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 1; i <= n; i++){
        scanf("%s", s+1);
        for(int j = 1; j <= m; j++)mat[i][j] = s[j]-'0';
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(mat[i][j])ans += 2;
            for(int k = 0; k < 4; k++){
                int nx = i+dx[k], ny = j+dy[k];
                ans += max(0, mat[i][j]-mat[nx][ny]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

