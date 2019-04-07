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
const int maxn = 5e2+10;
int A[maxn][maxn], B[maxn][maxn];
int row[maxn], col[maxn];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)sc(A[i][j]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)sc(B[i][j]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(A[i][j] != B[i][j])row[i] ^= 1, col[j] ^= 1;
        }
    }
    bool ok = 1;
    for(int i = 0; i < n; i++)if(row[i])ok = 0;
    for(int i = 0; i < m; i++)if(col[i])ok = 0;
    if(ok)puts("Yes");
    else puts("No");
    return 0;
}

