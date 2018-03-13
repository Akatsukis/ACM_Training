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
const int maxn = 17;
int n, m;
int a[maxn][maxn];
int tmp[maxn][maxn];
int now[maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string ans;
int step;
int cnt;

void flip(int x, int y)
{
    tmp[x][y] = !tmp[x][y];
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m){
            tmp[nx][ny] = !tmp[nx][ny];
        }
    }
}

void solve()
{

    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tmp[i - 1][j] == 1){
                flip(i, j);
                cnt++;
                now[i][j] = 1;
            }
            else now[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++){
        if(tmp[n - 1][i] == 1)return;
    }
    string res;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res.pb(now[i][j]);
        }
    }
    if(ans.size() == 0 || cnt < step || (cnt == step && res < ans)){
        step = cnt;
        ans = res;

    }
}

int main()
{
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            sc(a[i][j]);
        }
    }
    for(int i = 0; i < (1 << m); i++){
        memcpy(tmp, a, sizeof(tmp));
        memset(now, 0, sizeof(now));
        cnt = 0;
        for(int j = 0; j < m; j++){
            if((i >> j) & 1){
                flip(0, j);
                now[0][j] = 1;
                cnt++;
            }
            else now[0][j] = 0;
        }
        solve();
    }
    if(ans.size() == 0){
        printf("IMPOSSIBLE\n");
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d%c", ans[i * m + j], j == m - 1 ? '\n' : ' ');
        }
    }
    return 0;
}


