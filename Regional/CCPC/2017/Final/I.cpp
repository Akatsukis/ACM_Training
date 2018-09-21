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
const int maxn = 2e5+10;
struct edge
{
    int u, v, w, nxt;
    edge(){}
    edge(int u, int v, int w, int nxt):u(u), v(v), w(w), nxt(nxt){}
}es[maxn*2];
map<pii, int> mp;
map<int, int> num[maxn], loop;
stack<int> sk;
int head[maxn];
int low[maxn], dfn[maxn];
int tot[maxn];
bool inc[maxn];
int n, m, idx, cnt, col;

void init()
{
    mp.clear(); loop.clear();
    for(int i = 1; i <= n; i++){
        head[i] = -1; low[i] = dfn[i] = tot[i] = inc[i] = 0;
        num[i].clear();
    }
    idx = cnt = col = 0;
}

void add_edge(int u, int v, int w)
{
    es[cnt] = edge(u, v, w, head[u]);
    head[u] = cnt++;
    es[cnt] = edge(v, u, w, head[v]);
    head[v] = cnt++;
}

void dfs(int u, int f)
{
    low[u] = dfn[u] = ++idx;
    sk.push(u);
    for(int i = head[u]; ~i; i = es[i].nxt){
        if(es[i].v == f)continue;
        if(!dfn[es[i].v]){
            dfs(es[i].v, u);
            low[u] = min(low[u], low[es[i].v]);
        }
        else if(!inc[es[i].v])low[u] = min(low[u], dfn[es[i].v]);
    }
    if(low[u] == dfn[u]){
        int pre = 0;
        while(1){
            int x = sk.top(); sk.pop();
            if(pre)inc[mp[mk(pre, x)]] = 1;
            else inc[mp[mk(u, x)]] = 1;
            pre = x;
            if(x == u)break;
        }
    }
}
void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(m);
        init();
        for(int i = 0; i < n; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            add_edge(u, v, w);
            mp[mk(u, v)] = mp[mk(v, u)] = i;
        }
        tarjan(); 
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = head[i]; ~j; j = es[j].nxt){
                num[i][es[j].w]++;
                if(num[i][es[j].w] == 1)tot[i]++;
                if(inc[j>>1]){
                    loop[es[j].w]++;
                    if(loop[es[j].w] == 1)col++;
                }   
            }
            ans += tot[i];
        }
        if(col == 1)ans -= n-1;
        else ans -= n;
        printf("Case #%d:\n", kase++);
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            int id = mp[mk(u, v)];
            int pre = es[id*2].w;
            num[u][pre]--; num[v][pre]--;
            if(num[u][pre] == 0){
                num[u].erase(pre);
                tot[u]--;
                ans--;
            }
            if(num[v][pre] == 0){
                num[v].erase(pre);
                tot[v]--;
                ans--;
            }
            if(inc[id]){
                loop[pre]--;
                if(loop[pre] == 0){
                    loop.erase(pre); col--;
                    if(col == 1)ans++;
                }
            }
            es[id*2].w = es[id*2+1].w = w;
            num[u][w]++, num[v][w]++;
            if(num[u][w] == 1)tot[u]++, ans++;
            if(num[v][w] == 1)tot[v]++, ans++;
            if(inc[id]){
                loop[w]++;
                if(loop[w] == 1){
                    col++;
                    if(col == 2)ans--;
                }
            }
            printf("%d\n", ans);

        }
    }
    return 0;
}

