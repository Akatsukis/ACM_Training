#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define pb push_back
#define mk make_pair
#define fi first
#define se second
const int maxm = 1e7+10;
const int maxn = 6e3+10;
const int mod = 6e3;
vector<pii> G[maxm], upd, vec;
int mp[maxn][maxn];
bool vis[maxn][maxn];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, 1, -1};
int n, m;

void init()
{
    for(int i = 0; i < maxn; i++){
        for(int j = i; j < maxn; j++){
            if(i*i+j*j < maxm)G[i*i+j*j].pb(mk(i, j));
            else break;
        }
    }
}

inline bool in(int x, int y)
{
    return x >= 1 && x <= mod && y >= 1 && y <= mod;
}

inline void update(int x, int y, int w)
{
    if(!in(x, y) || vis[x][y] || !mp[x][y])return;
    vis[x][y] = 1;
    upd.pb(mk(x, y));
    mp[x][y] += w;
}

inline int query(int x, int y)
{
    if(!in(x, y) || vis[x][y] || !mp[x][y])return 0;
    vis[x][y] = 1;
    upd.pb(mk(x, y));
    return mp[x][y];
}

int main()
{
    init();
    int T, kase = 1;
    scanf("%d", &T);
    vector<pii> vec;
    while(T--){
        for(auto p : vec)mp[p.fi][p.se] = 0;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++){
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            mp[x][y] += w;
            vec.push_back(mk(x, y));
        }
        long long ans = 0;
        printf("Case #%d:\n", kase++);
        for(int i = 0; i < m; i++){
            int t, x, y, k, w;
            scanf("%d%d%d", &t, &x, &y);
            if(t == 3 || t == 4)scanf("%d", &k);
            if(t == 1 || t == 3)scanf("%d", &w);
            x = (ans+x)%mod+1, y = (ans+y)%mod+1;
            if(t == 1)mp[x][y] = w, vec.pb(mk(x, y));
            if(t == 2)mp[x][y] = 0;
            if(t == 3){
                for(auto p : G[k]){
                    for(int j = 0; j < 4; j++){
                        int nx = x+p.fi*dx[j], ny = y+p.se*dy[j];
                        update(nx, ny, w);
                        nx = x+p.se*dx[j], ny = y+p.fi*dy[j];
                        update(nx, ny, w);
                    }
                }
                for(auto p : upd)vis[p.fi][p.se] = 0;
                upd.clear();
            }
            if(t == 4){
                ans = 0;
                for(auto p : G[k]){
                    for(int j = 0; j < 4; j++){
                        int nx = x+p.fi*dx[j], ny = y+p.se*dy[j];
                        ans += query(nx, ny);
                        nx = x+p.se*dx[j], ny = y+p.fi*dy[j];
                        ans += query(nx, ny);
                    }
                }
                for(auto p : upd)vis[p.fi][p.se] = 0;
                upd.clear();
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
