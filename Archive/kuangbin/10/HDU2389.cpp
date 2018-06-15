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
const int INF = 0x3f3f3f3f;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e3+10;
vector<int> G[maxn];
struct Point
{
    int x, y;
}gue[maxn], umb[maxn];
int spd[maxn];
bool vis[maxn];
int mtx[maxn], mty[maxn];
int dx[maxn], dy[maxn], dis;
int n, m;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(mtx, 0, sizeof(mtx));
    memset(mty, 0, sizeof(mty));
}

bool bfs()
{
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    dis = INF;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!mtx[i])q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(dx[u] > dis)break;
        for(auto v : G[u]){
            if(dy[v] == -1){
                dy[v] = dx[u]+1;
                if(!mty[v])dis = dy[v];
                else{
                    dx[mty[v]] = dy[v]+1;
                    q.push(mty[v]);
                }
            }
        }
    }
    return dis < INF;
}

bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v] && dy[v] == dx[u]+1){
            vis[v] = 1;
            if(mty[v] && dy[v] == dis)continue;
            else if(!mty[v] || dfs(mty[v])){
                mty[v] = u;
                mtx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int hopcroft()
{
    int ret = 0;
    while(bfs()){
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++){
            if(!mtx[i] && dfs(i))ret++;
        }
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int t; sc(t);
        sc(n);
        init();
        for(int i = 1; i <= n; i++){
            sc(gue[i].x); sc(gue[i].y); sc(spd[i]);
        }
        sc(m);
        for(int i = 1; i <= m; i++){
            sc(umb[i].x); sc(umb[i].y);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(sqr(gue[i].x-umb[j].x)+sqr(gue[i].y-umb[j].y)<=sqr(t*spd[i]))G[i].pb(j); 
            }
        }
        int ans = hopcroft();
        printf("Scenario #%d:\n%d\n\n", kase++, ans);
    }
    return 0;
}

