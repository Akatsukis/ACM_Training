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
int low[maxn], dfn[maxn], rev[maxn], cut[maxn];
vector<int> bcc[maxn], G[maxn];
stack<pii> sk;
int n, idx, cnt;

void init()
{
    for(int i = 0; i < maxn; i++){
        low[i]= dfn[i] = rev[i] = cut[i] = 0;
        bcc[i].clear(); G[i].clear();
    }
    idx = cnt = 0;
}

void dfs(int u, int f)
{
    low[u] = dfn[u] = ++idx;
    int chd = 0;
    for(auto v : G[u]){
        if(v == f)continue;
        if(!dfn[v]){
            sk.push(mk(u, v));
            chd++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]){
                cut[u] = 1;
                cnt++;
                while(1){
                    pii p = sk.top(); sk.pop();
                    if(rev[p.fi] != cnt){
                        rev[p.fi] = cnt;
                        bcc[cnt].pb(p.fi);
                    }
                    if(rev[p.se] != cnt){
                        rev[p.se] = cnt;
                        bcc[cnt].pb(p.se);
                    }
                    if(p.fi == u && p.se == v)break;
                }
            }
        }
        else if(dfn[v] < dfn[u]){
            sk.push(mk(u, v));
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(chd == 1 && !f)cut[u] = 0;
}

void tarjan()
{
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
}

int main()
{
    int kase = 1;
    while(scanf("%d", &n) != EOF && n){
        init();
        for(int i = 0; i < n; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v); G[v].pb(u);
        }
        tarjan();
        printf("Case %d: ", kase++);
        ll ans1 = 0, ans2 = 1;
        for(int i = 1; i <= cnt; i++){
            int num = 0;
            for(auto u : bcc[i])if(cut[u])num++;
            if(num == 1)ans1++, ans2 *= SZ(bcc[i])-num;
        }
        if(cnt == 1)ans1 = 2, ans2 = 1LL*SZ(bcc[1])*(SZ(bcc[1])-1)/2;
        printf("%lld %lld\n", ans1, ans2);
    }
    return 0;
}

