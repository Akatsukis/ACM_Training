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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn= 5e3+10;
vector<int> G[maxn];
vector<int> cyc;
bool vis[maxn], flg;
int pre[maxn];
int dist[maxn];
int n;

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    cyc.clear();
    for(int i = 0; i <= n; i++)G[i].clear();
    flg = 0;
}

void dfs(int u, int f)
{
    vis[u] = 1;
    for(auto v : G[u]){
        if(v == f)continue;
        if(!vis[v]){
            pre[v] = u;
            dfs(v, u);
        }
        else{
            if(flg)continue;
            for(int i = pre[u]; i != v; i = pre[i]){
                cyc.pb(i);
            }
            cyc.pb(u); cyc.pb(v);
            flg = 1;
        }
    }
}

priority_queue<pii, vector<pii>, greater<pii> > pq;
void dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    for(auto u : cyc)dist[u] = 0, pq.push(mk(0, u));
    while(!pq.empty()){
        pii u = pq.top(); pq.pop();
        for(auto v : G[u.se]){
            if(dist[v] > dist[u.se]+1){
                dist[v] = dist[u.se]+1;
                pq.push(mk(dist[v], v));
            }
        }
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n);
        init();
        for(int i = 1; i <= n; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1, 0);
        dijkstra();
        printf("Case #%d: ", kase++);
        for(int i = 1; i <= n; i++){
            printf("%d%c", dist[i], " \n"[i==n]);
        }
    }
    return 0;
}

