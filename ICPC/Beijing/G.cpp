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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int vis[1010][1010];

void dfs(int x, int y, int n, int m, int dir)
{
    //cout << x << y << n << m << endl;
    vis[x][y]++;
    if(x == 1 && y == 1 && dir != 0)return;
    if(x == 1 && y == m)return;
    if(x == n && y == 1)return;
    if(x == n && y == m)return;
    if(x == 1 && dir != 0){
        if(dir == 1)dfs(x + 1, y + 1, n, m, 0);
        if(dir == 2)dfs(x + 1, y - 1, n, m, 3);
        return;
    }
    else if(x == n){
        if(dir == 0)dfs(x - 1, y + 1, n, m, 1);
        if(dir == 3)dfs(x - 1, y - 1, n, m, 2);
        return;
    }
    else if(y == 1 && dir != 0){
        if(dir == 2)dfs(x - 1, y + 1, n, m, 1);
        if(dir == 3)dfs(x + 1, y + 1, n, m, 0);
        return;
    }
    else if(y == m){
        if(dir == 0)dfs(x + 1, y - 1, n, m, 3);
        if(dir == 1)dfs(x - 1, y - 1, n, m, 2);
        return;
    }
    if(dir == 0)dfs(x + 1, y + 1, n, m, dir);
    else if(dir == 1)dfs(x - 1, y + 1, n, m, dir);
    else if(dir == 2)dfs(x - 1, y - 1, n, m, dir);
    else if(dir == 3)dfs(x + 1, y - 1, n, m, dir);
}

int main()
{
//    int n,m;
//    n = 5, m = 25;
//    dfs(1, 1, n, m, 0);
//    for(int i = 1; i <= n; i++){
//        for(int j = 1; j <= m; j++){
//            printf("%d", vis[i][j]);
//        }
//        printf("\n");
//    }
    //freout;
    for(int i = 2; i <= 20; i++){
        for(int j = 2; j <= 20; j++){
            memset(vis, 0, sizeof(vis));
            dfs(1, 1, i, j, 0);
            int ans = 0;
            for(int k = 1; k <= i; k++){
                for(int l = 1; l <= j; l++){
                    if(vis[k][l] == 1)ans++;
                }
            }
            //ans = i + j - 2 - gcd(i - 1, j - 1) + 1 + ;
            //printf("%3d", ans);
            int gcdd = gcd(i - 1, j - 1);
            int now = gcdd + 1;
            //if(gcdd != i && gcdd != j)now +=
            if(now != ans)cout << i-1 << " " << j-1 << " "  << ans - now << endl;
            //printf("%3d", ans);
        }
        printf("\n");
    }
	return 0;
}


