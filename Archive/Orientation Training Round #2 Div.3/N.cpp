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
const int maxn = 210;
int n, m;
bool mp[maxn][maxn];
int cost[2][maxn][maxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pii> V;
vector<pii> K;

void bfs(int id)
{
    memset(cost[id], INF, sizeof(cost[id]));
    queue<pii> q;
    q.push(V[id]);
    cost[id][V[id].fi][V[id].se] = 0;
    while(q.size()){
        pii now = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            int nx = now.fi + dx[i], ny = now.se + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny]){
                if(cost[id][nx][ny] > cost[id][now.fi][now.se] + 1){
                    cost[id][nx][ny] = cost[id][now.fi][now.se] + 1;
                    q.push(mk(nx, ny));
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        memset(mp, 0, sizeof(mp));
        V.clear();
        K.clear();
        for(int i = 0; i < n; i++){
            char s[maxn];
            scanf("%s", s);
            for(int j = 0; j < m; j++){
                if(s[j] != '#')mp[i][j] = 1;
                if(s[j] == 'Y' || s[j] == 'M')V.pb(mk(i, j));
                if(s[j] == '@')K.pb(mk(i, j));
            }
        }
        bfs(0);
        bfs(1);
        int ans = INF;
        for(int i = 0; i < (int)K.size(); i++){
            ans = min(ans, cost[0][K[i].fi][K[i].se] + cost[1][K[i].fi][K[i].se]);
        }
        printf("%d\n", ans * 11);
    }
    return 0;
}


