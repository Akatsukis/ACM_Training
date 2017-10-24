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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x"=%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3 + 10;
const int maxm = 2e4 + 10;
int n, m;
struct edge
{
    int u, v;
    ll w;
}es[maxm];
int id[maxn];
int vis[maxn];
int pre[maxn];
ll in[maxn];
int minroot;


ll zhuliu(int root, int V, int E)
{
    ll res = 0;
    while(1){
        for(int i = 0; i < V; i++)in[i] = INF64;
        for(int i = 0; i < E; i++){
            int u = es[i].u, v = es[i].v;
            if(u != v && in[v] > es[i].w){
                in[v] = es[i].w;
                pre[v] = u;
                if(u == root)minroot = i;
            }
        }
        for(int i = 0; i < V; i++){
            if(i != root && in[i] == INF64)return -1;
        }
        memset(id, -1, sizeof(id));
        memset(vis,  -1, sizeof(vis));
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
            es[i].u = id[es[i].u];
            es[i].v = id[es[i].v];
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
    ll sum = 1;
    for(int i = 0; i < m; i++){
        int u, v, w;
        sc(u);sc(v);sc(w);
        es[i].u = u, es[i].v = v, es[i].w = w;
        sum += es[i].w;
    }
    for(int i = 0; i < n; i++){
        es[i + m].u = n;
        es[i + m].v = i;
        es[i + m].w = sum;
    }
    ll ans = zhuliu(n, n + 1, n + m);
    if(ans == -1 || ans - sum >= sum)printf("impossible\n\n");
    else printf("%lld %d\n\n", ans - sum, minroot - m);
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        work();
    }
	return 0;
}


