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
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 20;
int a[maxn][maxn];
int n, ans;

int dfs(int x, int y, int cnt)
{
    int ret = INF;
    for(int i = x; i < n; i++){
        for(int j = i==x?y:0; j < n; j++){
            if(x+1 < n && y < n && a[x+1][y] == a[x][y]){
                int col = a[x][y];
                ret = min(ret, dfs(x, y+1, cnt+1));
            }
        }
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)sc(a[i][j]);
        }
        ans = dfs(0, 0, 0);
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

