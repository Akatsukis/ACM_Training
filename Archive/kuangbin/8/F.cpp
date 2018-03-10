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
const int maxe = 40100;
struct edge
{
    int u, v, w;
}es[maxe];
int vis[maxn];
int id[maxn];
int pre[maxn];
int in[maxn];
int n, m;

int zhuliu(int root)
{
    int ret = 0;
    while(1){
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        memset(in, INF, sizeof(in));
        for(int i = 0; i < m; i++)if(es[i].u != es[i].v && in[es[i].v] > es[i].w){
            in[es[i].v] = es[i].w;
            pre[es[i].v] = es[i].u;
        }
        for(int i = 0; i < n; i++)if(i != root && in[i] == INF)return INF;
        in[root] = 0;
        int loop = 0;
        for(int i = 0; i < n; i++){
            ret += in[i];
            int v = i;
            while(v != root && id[v] == -1 && vis[v] != i){
                vis[v] = i;
                v = pre[v];
            }
            if(vis[v] == i){
                for(int j = pre[v]; j != v; j = pre[j])id[j] = loop;
                id[v] = loop++;
            }
        }
        if(!loop)break;
        for(int i = 0; i < n; i++)if(id[i] == -1)id[i] = loop++;
        for(int i = 0; i < m; i++){
            int v = es[i].v;
            es[i].u = id[es[i].u];
            es[i].v = id[es[i].v];
            if(es[i].u != es[i].v)es[i].w -= in[v];
        }
        root = id[root];
        n = loop;
    }
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(m);
        for(int i = 0; i < m; i++){
            int u, v, w;
            sc(u); sc(v); sc(w);
            es[i].u = u, es[i].v = v, es[i].w = w;
        }
        int ans = zhuliu(0);
        if(ans == INF)printf("Case #%d: Possums!\n", kase++);
        else printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

