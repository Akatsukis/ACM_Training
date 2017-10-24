#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fst fi
#define scd se
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3 + 10;
const int maxm = 2e6 + 10;
int n, x, y, z;

struct house
{
    int a, b, c;
}h[maxn];

struct edge
{
    int u, v, w;
}es[maxm];
int in[maxn];
int pre[maxn];
int id[maxn];
int vis[maxn];

int dist(int i, int j)
{
    int res = abs(h[i].a-h[j].a) + abs(h[i].b-h[j].b) + abs(h[i].c-h[j].c);
    return res;
}

ll zhuliu(int root, int V, int E)
{
    ll res = 0;
    while(1){
        for(int i = 0; i < V; i++)in[i] = INF;
        for(int i = 0; i < E; i++){
            int u = es[i].u, v = es[i].v;
            if(u != v && in[v] > es[i].w){
                in[v] = es[i].w;
                pre[v] = u;
            }
        }
        for(int i = 0; i < V; i++){
            if(i != root && in[i] == INF)return -1;
        }
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        int loop = 0;
        for(int i = 0; i < V; i++){
            int v = i;
            res += in[i];
            while(vis[v] != i && id[v] == -1 && v != root){
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
        for(int i = 0; i < V; i++){
            if(id[i] == -1)id[i] = loop++;
        }
        for(int i = 0; i < E; i++){
            int u = es[i].u, v = es[i].v;
            es[i].u = id[u];
            es[i].v = id[v];
            if(es[i].u != es[i].v){
                es[i].w -= in[v];
            }
        }
        V = loop;
        root = id[root];
    }
    return res;
}


void work()
{
    int V = n + 1, E = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d%d%d", &h[i].a, &h[i].b, &h[i].c);
        es[E].u = 0, es[E].v = i, es[E].w = h[i].c * x;
        E++;
    }
    for(int i = 1; i <= n; i++){
        int k;
        sc(k);
        for(int j = 0; j < k; j++){
            int v;
            sc(v);
            es[E].u = i, es[E].v = v, es[E].w = dist(i, v) * y;
            if(h[i].c < h[v].c)es[E].w += z;
            E++;
        }
    }
    ll ans = zhuliu(0, V, E);
    printf("%lld\n", ans);
}

int main()
{
    while(scanf("%d%d%d%d", &n, &x, &y, &z) != EOF && (n || x || y || z)){
        work();
    }
    return 0;
}
