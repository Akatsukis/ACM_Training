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
const int maxs = 6e2+10;
const int maxn = 2e5+10;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char mp[maxs][maxs];
int cod[maxs][maxs];
bool vis[maxn];
int mtx[maxn], mty[maxn], dis;
int distx[maxn], disty[maxn];
vector<int> G[maxn];
int n, totx;

void init()
{
    for(int i = 0; i <= totx; i++)G[i].clear();
    memset(mtx, 0, sizeof(mtx));
    memset(mty, 0, sizeof(mty));
}

void get_cod()
{
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i%2?1:0; j < n; j += 2){
            cod[i][j] = ++cnt;
            //printf("cod[%d][%d]=%d\n", i, j, cnt);
        }
    }
    totx = cnt;
    cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i%2?0:1; j < n; j += 2){
            cod[i][j] = ++cnt;
        }
    }
}

bool bfs()
{
    memset(distx, -1, sizeof(distx));
    memset(disty, -1, sizeof(disty));
    dis = INF;
    queue<int> q;
    for(int i = 1; i <= totx; i++){
        if(!mtx[i])q.push(i), distx[i] = 0;
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G[u]){
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

bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v] && disty[v] == distx[u]+1){
            vis[v] = 1;
            if(mty[v] && disty[v] == dis)continue;
            else if(!mty[v] || dfs(mty[v])){
                mty[v] = u; mtx[u] = v;
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
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++){
            scanf("%s", mp[i]);
        }
        get_cod();
        init();
        for(int i = 0; i < n; i++){
            for(int j = i%2?1:0; j < n; j += 2){
                if(mp[i][j] == '.')continue;
                //printf("(%d, %d)\n", i, j);
                for(int k = 0; k < 4; k++){
                    int nx = i+dx[k], ny = j+dy[k];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n && mp[nx][ny] == '#'){
                        int u = cod[i][j], v = cod[nx][ny];
                        //printf("%d(%d,%d)->%d(%d,%d)\n", u, i, j, v, nx, ny);
                        G[u].pb(v);
                    }
                }
            }
        }
        int ans = max_match();
        printf("Case %d: %d\n", kase++, ans);
    }
    return 0;
}

