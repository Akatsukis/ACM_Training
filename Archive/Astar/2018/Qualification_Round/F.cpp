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
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+10;
struct edge
{
    int u, v, w;
    char s[2];
    bool operator < (const edge &rhs)const
    {
        return w < rhs.w;
    }
}es[maxn];
int par[maxn];
bool vis[maxn][2];
int n, m;

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

bool unite(int x, int y)
{
    x = find(x), y = find(y);
    if(x != y){
        par[x] = y;
        return 1;
    }
    return 0;
}

int kruskal(int k)
{
    for(int i = 1; i <= n; i++)par[i] = i;
    int ret = 0;
    for(int i = 1; i <= m; i++){
        if(k == 0 && es[i].s[0] == 'B')continue;
        if(k == 1 && es[i].s[0] == 'R')continue;
        int u = es[i].u, v = es[i].v;
        if(unite(u, v))vis[i][k] = 1, ret += es[i].w;
    }
    for(int i = 2; i <= n; i++)if(find(i) != find(1))return INF;
    return ret;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(es, 0, sizeof(es));
        memset(vis, 0, sizeof(vis));
        sc(n); sc(m);
        for(int i = 1; i <= m; i++)scanf("%d%d%d%s", &es[i].u, &es[i].v, &es[i].w, es[i].s);
        sort(es+1, es+1+m);
        int ans1 = kruskal(0);
        int ans2 = kruskal(1);
        printf("Case #%d:\n", kase++);
        int pt1 = 1, pt2 = 1;
        for(int i = 1; i <= m; i++){
            if(i < n-1)puts("-1");
            else{
                int ans = min(ans1, ans2);
                if(ans >= INF)puts("-1");
                else printf("%d\n", ans);
                while(pt1 <= m && vis[pt1][0])pt1++;
                while(pt2 <= m && vis[pt2][1])pt2++;
                ans1 += es[pt1++].w;
                ans2 += es[pt2++].w;
            }
        }
    }
    return 0;
}


