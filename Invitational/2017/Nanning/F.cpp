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
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
const int maxm = 2e5+10;
struct edge
{
    int u, v, w;
    bool operator < (const edge &rhs)const
    {
        return w > rhs.w;
    }
}es[maxm];
int par[maxn];
int n, m;
bool flg;

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x =find(x), y = find(y);
    par[x] = y;
}

pii kruskal()
{
    pii ret(0, 0);
    sort(es, es+m);
    for(int i = 0; i < m; i++){
        if(find(es[i].u) != find(es[i].v)){
            unite(es[i].u, es[i].v);
        }
        else ret.fi++, ret.se+= es[i].w;
    }
    return ret;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++)par[i] = i;
        for(int i = 1; i <= n; i++)scanf("%*d%*d");
        flg = 1;
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            es[i].u = u, es[i].v = v, es[i].w = w;
        }
        pii ans = kruskal();
        printf("%d %d\n", ans.fi, ans.se);
    }
    return 0;
}

