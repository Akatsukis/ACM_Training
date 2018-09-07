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
const int INF = 0x3f3f3f3f;
const int maxn = 2e2+10;
vector<pii> G[maxn];
vector<int> vec, tmp;
bool vis[maxn], used[maxn], ban[maxn];
int deg[maxn], a[maxn];
int ans;

void dfs(int u, int t)
{
    if(t)vec.pb(u);
    else tmp.pb(u);
    vis[u] = 0;
    for(auto v : G[u]){
        if(vis[v.fi] && !ban[v.se])dfs(v.fi, t);
    }
}

void solve()
{
    for(auto u : vec)vis[u] = 1;
    for(auto u : vec){
        for(auto v : G[u])used[v.se] = 0;
    }
    for(auto u : vec){
        if(vis[u]){
            tmp.clear();
            dfs(u, 0);
            int tot = 0;
            for(auto v : tmp){
                for(auto w : G[v]){
                    if(used[w.se] || ban[w.se])continue;
                    else used[w.se] = 1;
                    tot += a[w.se];
                }
            }
            ans = max(ans, tot);
        }
    }
}

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++){
        int u, v, w;
        sc(u); sc(w); sc(v);
        deg[u]++, deg[v]++;
        G[u].pb(mk(v, i)), G[v].pb(mk(u, i));
        a[i] = w;
        vis[u] = vis[v] = 1;
    }
    for(int i = 1; i <= 4; i++){
        if(vis[i]){
            vec.clear();
            dfs(i, 1);
            int cnt = 0, tot = 0;
            for(auto u : vec){
                if(deg[u]%2)cnt++;
                for(auto v : G[u]){
                    if(used[v.se])continue;
                    else used[v.se] = 1;
                    tot += a[v.se];
                }   
            }
            if(cnt <= 2)ans = max(ans, tot);
            else{
                for(auto u : vec){
                    for(auto v : G[u]){
                        if(u == v.fi)continue;
                        ban[v.se] = 1;
                        solve();
                        ban[v.se] = 0;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
