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
#define Abs(x) ((x)>=0?(x):(-(x)))
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
const int maxe = 1001010;
int n, m, cnt;
int a[maxn], b[maxn], c[maxn];
struct edge
{
    int u, v, w;
}es[maxe];
int in[maxn];
int pre[maxn];
int id[maxn];
int vis[maxn];

int dis(int i, int j)
{
    return Abs(a[i]-a[j])+Abs(b[i]-b[j])+Abs(c[i]-c[j]);
}

ll zhuliu(int root, int V, int E)
{
    ll ret = 0;
    while(1){
        memset(in, 0x3f, sizeof(in));
        memset(vis, -1, sizeof(vis));
        memset(id, -1, sizeof(id));
        for(int i = 0; i < E; i++)if(es[i].u != es[i].v && in[es[i].v] > es[i].w){
            in[es[i].v] = es[i].w;
            pre[es[i].v] = es[i].u;
        }
        for(int i = 0; i < V; i++)if(i != root && in[i] == INF)return -1;
        int loop = 0;
        in[root] = 0;
        for(int i = 0; i < V; i++){
            ret += in[i];
            int v = i;
            while(id[v] == -1 && v != root && vis[v] != i){
                vis[v] = i;
                v = pre[v];
            }
            if(vis[v] == i){
                for(int j = pre[v]; j != v; j = pre[j]){
                    id[j] = loop;
                }
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
        V = loop;
        root = id[root];
    }
    return ret;
}

int main()
{
    int n, x, y, z;
    while(scanf("%d%d%d%d", &n, &x, &y, &z) != EOF && (n||x||y||z)){
        cnt = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
            es[cnt].u = 0, es[cnt].v = i, es[cnt].w = x*c[i];
            cnt++;
        }
        int k, v;
        for(int i = 1; i <= n; i++){
            sc(k);
            for(int j = 0; j < k; j++){
                sc(v);
                es[cnt].u = i, es[cnt].v = v, es[cnt].w=y*dis(i, v)+(c[i]<c[v]?z:0);
                cnt++;
            }
        }
        ll ans = zhuliu(0, n+1, cnt);
        printf("%lld\n", ans);
    }
    return 0;
}

