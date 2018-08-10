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
const int maxn = 1e5+10;
struct edge
{
    int to, nxt;
}es[maxn*4];
int deg[maxn], head[maxn];
vector<vector<int> > ans;
vector<int> seq;
bool vis[maxn];
bool used[maxn*2];
int n, m, cnt;

void init()
{
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    memset(used, 0, sizeof(used));
    ans.clear();
    cnt = 0;
}

void add_edge(int u, int v)
{
    es[cnt].to = v, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

void dfs(int u)
{
    vis[u] = 1;
    for(int i = head[u]; ~i; i = head[u]){
        head[u] = es[i].nxt;
        if(used[i>>1])continue;
        used[i>>1] = 1;
        int v = es[i].to;
        dfs(v);
        seq.pb(i);
    }

}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(int i = 1; i <= m; i++){
            int u, v;
            sc(u); sc(v);
            add_edge(u, v);
            deg[u]++, deg[v]++;
        }
        for(int i = 1; i <= n; i++){
            if(deg[i]&1)add_edge(i, 0);
        }
        for(int i = 0; i <= n; i++){
            if(!vis[i]){
                seq.clear();
                dfs(i);
                vector<int> vec;
                for(auto u : seq){
                    if(!es[u].to || !es[u^1].to){
                        if(SZ(vec)){
                            ans.pb(vec);
                            vec.clear();
                        }
                        else vec.clear();
                    }
                    else{
                        if(u&1)vec.pb(-((u+2)>>1));
                        else vec.pb((u+2)>>1);
                    }
                }
                if(SZ(vec))ans.pb(vec);
            }
        }
        printf("%d\n", SZ(ans));
        for(auto vec : ans){
            printf("%d ", SZ(vec));
            reverse(ALL(vec));
            for(int i = 0; i < SZ(vec); i++){
                printf("%d%c", vec[i], " \n"[i==SZ(vec)-1]);
            }
        }
    }
    return 0;
}


