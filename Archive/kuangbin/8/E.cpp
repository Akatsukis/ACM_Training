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
#define pr(x) printf("x:%dn", x)
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
const double INF = 213456789.0;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 100 + 10;
const int maxm = 2000 + 10;
struct edge
{
    int u, v;
    double w;
}es[maxm];
int n, m;
int x[maxn];
int y[maxn];
int pre[maxn];
int id[maxn];
double in[maxn];
int vis[maxn];

double dist(int i, int j)
{
    double res = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
    return sqrt(res);
}

void add_edge(int i, int u, int v)
{
    es[i].u = u, es[i].v = v, es[i].w = dist(u, v);
}

double zhuliu(int root)
{
    double res = 0;
    while(1){
        for(int i = 1; i <= n; i++){
            in[i] = INF;
        }
        for(int i = 0; i < m; i++){
            edge cur = es[i];
            if(cur.u != cur.v && in[cur.v] > cur.w){
                in[cur.v] = cur.w;
                pre[cur.v] = cur.u;
                //printf("in[%d]:%f\n", cur.v, in[cur.v]);
            }
        }
        for(int i = 0; i < n; i++){
            if(i != root && abs(in[i] - INF) < eps){
                return INF;
            }
        }
        int loop = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        for(int i = 1; i <= n; i++){
            int v;
            res += in[i];
            //printf("in[%d]:%f\n", i, in[i]);
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root){
                vis[v] = i;
                v = pre[v];
            }
            if(id[v] == -1 && v != root){
                for(int j = pre[v]; j != v; j = pre[j]){
                    id[j] = loop;
                }
                id[v] = loop++;
            }
        }
        //printf("res=%f\n", res);
        if(!loop)break;
        for(int i = 1; i <= n; i++){
            if(id[i] != -1){
                id[i] = loop++;
            }
        }
        for(int i = 0; i < m; i++){
            int v;
            v = es[i].v;
            es[i].u = id[es[i].u];
            es[i].v = id[es[i].v];
            if(es[i].u != es[i].v){
                es[i].w -= in[v];
            }
        }
        n = loop;
        root = id[root];
    }
    return res;
}

void work()
{
    for(int i = 1; i <= n; i++){
        sc(x[i]);sc(y[i]);
    }
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u);sc(v);
        add_edge(i, u, v);
    }
    double ans = zhuliu(1);
    if(abs(ans - INF) < eps){
        printf("poor snoopy\n");
    }
    else printf("%.2f\n", ans);
}


int main()
{
    while(scanf("%d %d", &n, &m) != EOF){
        work();
    }
	return 0;
}


