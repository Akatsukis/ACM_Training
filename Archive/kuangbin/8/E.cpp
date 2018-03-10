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
const int maxn = 110;
const int maxe = 10010;
struct edge
{
    int from, to;
    double w;
}es[maxe];
double x[maxn];
double y[maxn];
double in[maxn];
int vis[maxn];
int id[maxn];
int pre[maxn];
int n, m;

double zhuliu(int root)
{
    double ret = 0;
    while(1){
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        for(int i = 1; i <= n; i++)in[i] = INF;
        for(int i = 0; i < m; i++){
            if(es[i].from != es[i].to && in[es[i].to] > es[i].w){
                in[es[i].to] = es[i].w;
                pre[es[i].to] = es[i].from;
            }   
        }
        for(int i = 1; i <= n; i++)if(i != root && fabs(in[i]-INF)<eps)return INF;
        in[root] = 0;
        int loop = 0;
        for(int i = 1; i <= n; i++){
            ret += in[i];
            int v = i;
            while(v != root && id[v] == -1 && vis[v] != i){
                vis[v] = i;
                v = pre[v];
            }
            if(vis[v] == i){
                ++loop;
                for(int j = pre[v]; j != v; j = pre[j])id[j] = loop;
                id[v] = loop;
            }
        }
        if(!loop)break;
        for(int i = 1; i <= n; i++)if(id[i] == -1)id[i] = ++loop;
        for(int i = 0; i < m; i++){
            int v = es[i].to;
            es[i].from = id[es[i].from];
            es[i].to = id[es[i].to];
            if(es[i].from != es[i].to){
                es[i].w -= in[v];
            }
        }
        n = loop;
        root = id[root];
    }
    return ret;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%lf%lf", &x[i], &y[i]);
        }
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            es[i].from = u, es[i].to = v, es[i].w = sqrt(sqr(x[u]-x[v])+sqr(y[u]-y[v]));
        }
        double ans = zhuliu(1);
        if(fabs(ans-INF) < eps)printf("poor snoopy\n");
        else printf("%.2f\n", ans);
    }
    return 0;
}

