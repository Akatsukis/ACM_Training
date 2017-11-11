#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e3+10;
int n;
int a[maxn];
int mx[maxn][maxn];
int mn[maxn][maxn];
int f[maxn][maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 1; i <= n; i++){
            sc(a[i]);
            mx[i][i] = a[i];
            mn[i][i] = a[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                mx[i][j] = max(mx[i][j - 1], a[j]);
                mn[i][j] = min(mn[i][j - 1], a[j]);
            }
        }
        for(int i = 1; i <= n; i++){
            int cnt = 1;
            f[i][i] = 1;
            for(int j = i + 1; j <= n; j++){
                if(mn[i][j - 1] != mn[i][j])cnt = 0;
                if(mx[i][j] - mn[i][j] == j-i)f[i][j] = ++cnt;
            }
        }
        int ans = f[1][n];
        for(int i = 1; i <= n; i++){
            if(i == 1 || (mn[1][i-1] == 1 && f[1][i-1])){
                for(int j = i; j <= n; j++){
                    if(f[i][j]){
                        int x = mx[i][j];
                        if(x == n || (mx[x+1][n] == n && f[x+1][n])){
                            for(int k = x; k > j; k--){
                                if(f[k][x] && mn[k][x] == i){
                                    ans = max(ans, f[1][i-1]+1+f[j+1][k-1]+1+f[x+1][n]);
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


