#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 110;
int a[maxn][maxn];

int solve(int x, int y)
{
    int sum = a[x][y]+a[x][y+1]+a[x][y+2];
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for(int i = 0; i < 3; i++){
        sum1 = 0, sum2 = 0;
        for(int j = 0; j < 3; j++){
            sum1 += a[x+i][y+j];
            sum2 += a[x+j][y+i];
        }
        if(sum1 != sum || sum2 != sum)return 0;
    }
    sum3 = a[x][y] + a[x+1][y+1] + a[x+2][y+2];
    sum4 = a[x][y+2] + a[x+1][y+1] + a[x+2][y];
    if(sum3 != sum || sum4 != sum)return 0;
    return 1;
}

int main()
{
    int n, m;
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sc(a[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i + 2 < n; i++){
        for(int j = 0; j + 2 < m; j++){
            ans += solve(i, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}

