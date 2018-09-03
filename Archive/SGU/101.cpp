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
const int maxn = 10;
const int maxm = 2e2+10;
int deg[maxn];
int head[maxn];
struct edge
{
    int to, nxt;
    edge(){}
    edge(int to, int nxt):to(to), nxt(nxt){}
}es[maxm];
bool vis[maxn];
bool used[maxm];
vector<pair<int, char> > ans;
vector<int> seq;
int cnt;

void dfs(int u)
{
    vis[u] = 0;
    for(int i = head[u]; ~i; i = es[i].nxt){
        if(used[i>>1])continue;
        used[i>>1] = 1;
        dfs(es[i].to);
        seq.pb(i);
    }
}

void add_edge(int u, int v)
{
    es[cnt] = edge(v, head[u]);
    head[u] = cnt++;
    es[cnt] = edge(u, head[v]);
    head[v] = cnt++;
}

int main()
{
    memset(head, -1, sizeof(head));
    int n; sc(n);
    int st = 0;
    for(int i = 0; i < n; i++){
        int u, v; 
        sc(u); sc(v);
        st = u;
        vis[u] = vis[v] = 1;
        deg[u]++, deg[v]++;
        add_edge(u, v);
    }
    int cnt = 0;
    for(int i = 0; i <= 6; i++){
        if(deg[i]%2){
            cnt++; st = i;
        }
    }
    if(cnt > 2)printf("No solution\n");
    else{
        dfs(st);
        for(int i = 0; i <= 6; i++){
            if(vis[i]){
                printf("No solution\n");
                return 0;
            }
        }
        for(auto u : seq){
            if(u%2 == 0)ans.pb(mk((u+2)>>1, '+'));
            else ans.pb(mk((u+2)>>1, '-'));
        }
        reverse(ALL(ans));
        for(auto p : ans)printf("%d %c\n", p.fi, p.se);
    }
    return 0;
}

