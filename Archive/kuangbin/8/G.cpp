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
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1010;
const int maxe = 11010;
struct edge
{
    int u, v, w;
}es[maxe];
int in[maxn];
int vis[maxn];
int pre[maxn];
int id[maxn];
int n, m;

int zhuliu(int root, int &ans, int V, int E)
{
    int ret = 0;
    while(1){
        memset(in, 0x3f, sizeof(in));
        memset(vis, -1, sizeof(vis));
        memset(id, -1, sizeof(id));
        for(int i = 0; i < E; i++)if(es[i].u!=es[i].v&&in[es[i].v]>es[i].w){
            in[es[i].v] = es[i].w;
            pre[es[i].v] = es[i].u;
            if(es[i].u == root)ans = i;
        }
        for(int i = 0; i < V; i++)if(i != root && in[i] == INF)return INF;
        in[root] = 0;
        int loop = 0;
        for(int i = 0; i < V; i++){
            ret += in[i];
            int v = i;
            while(vis[v] != i && v != root && id[v] == -1){
                vis[v] = i;
                v = pre[v];
            }
            if(vis[v] == i){
                for(int j = pre[v]; j != v; j = pre[j])id[j] = loop;
                id[v] = loop++;
            }
        }
        if(!loop)break;
        for(int i = 0; i < V; i++)if(id[i] == -1)id[i] = loop++;
        for(int i = 0; i < E; i++){
            int v = es[i].v;
            es[i].u = id[es[i].u];
            es[i].v = id[es[i].v];
            if(es[i].u != es[i].v)es[i].w -= in[v];
        }
        root = id[root];
        V = loop;
    }
    return ret;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        int sum = 1;
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            es[i].u = u, es[i].v = v, es[i].w = w;
            sum += w;
        }
        for(int i = 0; i < n; i++){
            es[m+i].u = n;
            es[m+i].v = i;
            es[m+i].w = sum;
        }
        int root;
        int ans = zhuliu(n, root, n+1, n+m);
        if(ans-sum >= sum)printf("impossible\n\n");
        else printf("%d %d\n\n", ans-sum, root-m);
    }
    return 0;
}

