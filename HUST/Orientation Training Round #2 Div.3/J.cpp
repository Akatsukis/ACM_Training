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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
int n, m;
bool mp[maxn][maxn];
int cost[maxn][maxn];
int fire[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int stx, sty;
vector<pii> f;

int bfs()
{
    queue<pii> q;
    memset(fire, INF, sizeof(fire));
    for(int i = 0; i < (int)f.size(); i++){
        fire[f[i].fi][f[i].se] = 0;
        q.push(mk(f[i].fi, f[i].se));
    }
    while(q.size()){
        pii tmp = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            int nx = tmp.fi + dx[i], ny = tmp.se + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(mp[nx][ny] && fire[nx][ny] > fire[tmp.fi][tmp.se] + 1){
                    fire[nx][ny] = fire[tmp.fi][tmp.se] + 1;
                    q.push(mk(nx, ny));
                }
            }
        }
    }
    q.push(mk(stx, sty));
    memset(cost, INF, sizeof(cost));
    cost[stx][sty] = 0;
    while(q.size()){
        pii tmp = q.front();q.pop();
        if(tmp.fi == 0 || tmp.fi == n - 1 || tmp.se == 0 || tmp.se == m - 1)return cost[tmp.fi][tmp.se] + 1;
        for(int i = 0; i < 4; i++){
            int nx = tmp.fi + dx[i], ny = tmp.se + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(mp[nx][ny] && cost[nx][ny] > cost[tmp.fi][tmp.se] + 1 && cost[tmp.fi][tmp.se] + 1 < fire[nx][ny]){
                    cost[nx][ny] = cost[tmp.fi][tmp.se] + 1;

                    q.push(mk(nx, ny));
                }
            }
        }
    }
    return -1;
}

void work()
{
    sc(n);sc(m);
    memset(mp, 0, sizeof(mp));
    f.clear();
    for(int i = 0; i < n; i++){
        char s[maxn];
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] != '#')mp[i][j] = 1;
            if(s[j] == 'J'){
                stx = i, sty = j;
            }
            if(s[j] == 'F'){
                f.pb(mk(i, j));
            }
        }
    }
    int ans = bfs();
    if(ans != -1)printf("%d\n", ans);
    else printf("IMPOSSIBLE\n");
}

int main()
{
    int T;
    sc(T);
    while(T--){
        work();
    }
    return 0;
}


