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
#define fst first
#define scd second
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
const int maxn = 3e3 + 10;
int n, m, k;
int x[3];
int y[3];
char s[maxn];
int mp[maxn][maxn];
int cost[maxn][maxn];
queue<pii> q;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void solve()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cost[i][j] = INF;
        }
    }
    x[1]--;y[1]--;x[2]--;y[2]--;
    cost[x[1]][y[1]] = 0;
    q.push(mk(x[1], y[1]));
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            for(int j = 1; j <= k; j++){
                int nx = tmp.fst + dx[i] * j, ny = tmp.scd + dy[i] * j;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny]){
                    if(cost[nx][ny] > cost[tmp.fst][tmp.scd] + 1){
                        cost[nx][ny] = cost[tmp.fst][tmp.scd] + 1;
                        //printf("cost[%d][%d]:%d\n", nx, ny, cost[nx][ny]);
                        q.push(mk(nx, ny));
                    }
                    else if(cost[nx][ny] < cost[tmp.fst][tmp.scd] + 1)break;
                }
                else break;
            }
        }
    }
}

int main()
{
    sc(n);sc(m);sc(k);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] == '.')mp[i][j] = 1;
            else mp[i][j] = 0;
        }
    }
    scanf("%d%d%d%d", &x[1], &y[1], &x[2], &y[2]);
    solve();
    if(cost[x[2]][y[2]] == INF)printf("-1\n");
    else printf("%d\n", cost[x[2]][y[2]]);
    return 0;
}


