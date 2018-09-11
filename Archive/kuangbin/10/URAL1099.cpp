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
const int maxn = 5e2+10;
vector<int> G[maxn];
int fa[maxn], vis[maxn], mat[maxn], pre[maxn], typ[maxn];
int n, m, tim;
queue<int> q;

void init()
{
    tim = 0;
    memset(vis, 0, sizeof(vis));
    memset(mat, 0, sizeof(mat));
    for(int i = 0; i <= n; i++)G[i].clear();
}

int lca(int x, int y) 
{
    tim++;
    x = fa[x], y = fa[y];
    while(vis[x] != tim){
        if(x){
            vis[x] = tim;
            x = fa[pre[mat[x]]];
        }
        swap(x, y);
    }
    return x;
}

void blossom(int x, int y, int f)
{
    while(fa[x] != f){
        pre[x] = y;
        y = mat[x];
        if(typ[y] == 1){
            typ[y] = 0;
            q.push(y);
        }
        fa[x] = fa[y] = fa[f];
        x = pre[y];
    }
}
bool augument(int s) 
{
    for(int i = 1; i <= n; i++)fa[i] = i;
    memset(typ,-1,sizeof(typ));
    while(!q.empty())q.pop();
    typ[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : G[u]){
            if(typ[v] == -1){
                pre[v] = u;
                typ[v] = 1;
                if(!mat[v]){
                    for(int to = v, from = u; to; from = pre[to]){
                        mat[to] = from;
                        swap(mat[from], to);
                    }
                    return 1;
                }
                typ[mat[v]] = 0;
                q.push(mat[v]);
            }
            else if(typ[v] == 0 && fa[u] != fa[v]){
                int f = lca(u, v);
                blossom(u, v, f);
                blossom(v, u, f);
            }
        }
    }
    return 0;
}

void solve()
{
    int ret = 0;
    for(int i = 1; i <= n; i++){
        if(!mat[i])ret += augument(i);
    }
    printf("%d\n", ret*2);
    for(int i = 1; i <= n; i++){
        if(i < mat[i])printf("%d %d\n", i, mat[i]);
    }
}

int main()
{
    sc(n);
    int u, v;
    while(scanf("%d%d", &u, &v) != EOF){
        G[u].pb(v);
        G[v].pb(u);
    }
    solve();
    return 0;
}

