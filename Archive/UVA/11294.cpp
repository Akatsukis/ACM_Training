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
const int maxn = 1e2+10;
vector<int> G[maxn], G2[maxn], S;
int scc[maxn];
bool vis[maxn];
int n, m, cnt;

void init()
{
    for(int i = 0; i <= 2*n; i++){
        scc[i] = vis[i] = 0;
        G[i].clear(), G2[i].clear();
    }
    S.clear();
    cnt = 0;
}

void dfs1(int u)
{
    if(vis[u])return;
    else vis[u] = 1;
    for(auto v : G[u])dfs1(v);
    S.push_back(u);
}

void dfs2(int u)
{
    if(scc[u])return;
    scc[u] = cnt;
    for(auto v : G2[u])dfs2(v);
}

void korasaju()
{
    for(int i = 0; i < 2*n; i++)dfs1(i);
    for(int i = 2*n-1; i >= 0; i--){
        if(!scc[S[i]]){
            cnt++;
            dfs2(S[i]);
        }
    }
}

void add_edge(int u, int v)
{
    G[u].pb(v); G2[v].pb(u);
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && n){
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            char c, d;
            scanf("%d%c%d%c", &u, &c, &v, &d);
            if(c == 'h' && d == 'h')add_edge(u, v+n), add_edge(v, u+n);
            if(c == 'h' && d == 'w')add_edge(u, v), add_edge(v+n, u+n);
            if(c == 'w' && d == 'h')add_edge(u+n, v+n), add_edge(v, u);
            if(c == 'w' && d == 'w')add_edge(u+n, v), add_edge(v+n, u);
        }
        add_edge(n, 0);
        korasaju();
        bool ok = 1;
        for(int i = 0; i < n; i++){
            if(scc[i] == scc[i+n])ok = 0;
        }
        if(!ok){
            puts("bad luck");
            continue;
        }
        for(int i = 1; i < n; i++){
            if(scc[i] < scc[i+n])printf("%dh%c", i, " \n"[i==n-1]);
            else printf("%dw%c", i, " \n"[i==n-1]);
        }
    }
    return 0;
}
