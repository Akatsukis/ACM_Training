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
const int maxc = 1e4+10;
struct atom
{
    int d, s, id;
    bool operator < (const atom &rhs)
    {
        return s-d < rhs.s-rhs.d;
    }
}tb[maxn];
int dp[maxn][maxc];
int pre[maxn][maxc];
bool vis[maxn][maxc];


int main()
{
    int n, c;
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; i++)scanf("%d%d", &tb[i].d, &tb[i].s), tb[i].id = i;
    sort(tb+1, tb+n+1);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= c; j++)dp[i][j] = dp[i-1][j];
        for(int j = 0; j+max(tb[i].d, tb[i].s) <= c; j++){
            if(dp[i-1][j]+1 > dp[i][j+tb[i].s]){
                dp[i][j+tb[i].s] = dp[i-1][j]+1;
                pre[i][j+tb[i].s] = j;
                vis[i][j+tb[i].s] = 1;
            }   
        }
    }
    int ans = 0, val = 0;
    for(int i = 0; i <= c; i++){
        if(dp[n][i] > ans){
            ans = dp[n][i];
            val = i;
        }
    }
    vector<int> vec;
    for(int i = n; i >= 1; i--){
        if(vis[i][val]){
            vec.pb(tb[i].id);
            val = pre[i][val];
        }
    }
    printf("%d\n", ans);
    for(int i = SZ(vec)-1; i >= 0; i--)printf("%d%c", vec[i], " \n"[i==0]);
    return 0;
}


