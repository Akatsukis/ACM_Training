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
const int maxn = 2e3+10;
vector<pii> G[maxn], seq;
int deg[maxn];
bool used[maxn], vis[maxn];

void init()
{
    memset(deg, 0, sizeof(deg));
    memset(used, 0, sizeof(used));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < maxn; i++)G[i].clear();
    seq.clear();
}

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : G[u]){
        if(!used[v.se]){
            used[v.se] = 1;
            dfs(v.fi);
            seq.pb(mk(u, v.fi));
        }
    }
}

int main()
{
    int T, kase = 1; 
    bool fst = 1;
    sc(T);
    while(T--){
        init();
        int n; sc(n);
        int st = 1;
        for(int i = 1; i <= n; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            G[x].pb(mk(y, i));
            G[y].pb(mk(x, i));
            deg[x]++, deg[y]++;
            st = x;
        }
        bool ok = 1;
        for(int i = 1; i < maxn; i++){
            if(deg[i]&1)ok = 0;
        }
        if(fst)fst = 0;
        else puts("");
        printf("Case #%d\n", kase++);
        dfs(st);
        for(int i = 0; i < maxn; i++){
            if(deg[i] && !vis[i])ok = 0;
        }
        if(!ok)puts("some beads may be lost");
        else{
            reverse(ALL(seq));
            for(auto p : seq)printf("%d %d\n", p.fi, p.se);
        }   
    }
    return 0;
}

