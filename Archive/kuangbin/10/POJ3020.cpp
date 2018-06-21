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
const int INF = 0x3f3f3f3f;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxs = 50;
const int maxn = 2e2+10;
char mp[maxs][maxs];
int cod[maxs][maxs];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int distx[maxn], disty[maxn];
int mtx[maxn], mty[maxn], dis;
bool vis[maxn];
int n, m, totx, toty;
vector<int> G[maxn];

void get_cod()
{
    totx = toty = 0;
    for(int i = 0; i < n; i++){
        for(int j = i%2?1:0; j < m; j += 2){
            cod[i][j] = ++totx;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i%2?0:1; j < m; j += 2){
            cod[i][j] = ++toty;
        }
    }
}

void init()
{
    for(int i = 0; i  <= totx; i++)G[i].clear();
    memset(mtx, 0, sizeof(mtx));
    memset(mty, 0, sizeof(mty));
}

bool bfs()
{
    memset(distx, -1, sizeof(distx));
    memset(disty, -1, sizeof(disty));
    queue<int> q;
    dis = INF;
    for(int i = 1; i <= totx; i++){
        if(!mtx[i])q.push(i), distx[i] = 0;
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(distx[u] > dis)break;
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i];
            if(disty[v] == -1){
                disty[v] = distx[u]+1;
                if(!mty[v])dis = disty[v];
                else{
                    distx[mty[v]] = disty[v]+1;
                    q.push(mty[v]);
                }
            }
        }
    }
    return dis < INF;
}

int dfs(int u)
{
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(!vis[v] && disty[v] == distx[u]+1){
            vis[v] = 1;
            if(mty[v] && disty[v] == dis)continue;
            else if(!mty[v] || dfs(mty[v])){
                mty[v] = u, mtx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int max_match()
{
    int ret = 0;
    while(bfs()){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= totx; i++){
            if(!mtx[i] && dfs(i))ret++;
        }
    }
    return ret;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)scanf("%s", mp[i]);
        get_cod();
        init();
        for(int i = 0; i < n; i++){
            for(int j = i%2?1:0; j < m; j += 2){
                if(mp[i][j] == 'o')continue;
                for(int k = 0; k < 4; k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && mp[nx][ny] == '*'){
                        int u = cod[i][j], v = cod[nx][ny];
                        G[u].pb(v);
                        //printf("%d->%d\n", u, v);
                    }
                }
            }
        }
        int ans = max_match();
        for(int i = 0; i < n; i++){
            for(int j = i%2?1:0; j < m; j += 2){
                if(mp[i][j] == '*' && !mtx[cod[i][j]])ans++;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = i%2?0:1; j < m; j += 2){
                if(mp[i][j] == '*' && !mty[cod[i][j]])ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

