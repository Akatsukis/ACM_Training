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
ll a[maxn], b[maxn];
vector<int> G[maxn];
bool vis[maxn];
int par[maxn];
struct Point
{
    int id;
    ll a, b;
    Point(){}
    Point(int id, ll a, ll b):id(id), a(a), b(b){}
    bool operator < (const Point &rhs)const
    {
        bool u = b>a, v = rhs.b>rhs.a;
        if(u != v)return u < v;
        else if(u && v)return a > rhs.a;
        else return b < rhs.b;
    }
};
priority_queue<Point> pq;
int n;

int find(int x)
{
    return vis[par[x]]?par[x]=find(par[x]):par[x];
}

void init()
{
    while(!pq.empty())pq.pop();
    for(int i = 0; i <= n; i++)G[i].clear(), vis[i] = 0;
    a[1] = b[1] = 0;
}

void dfs(int u, int f)
{
    par[u] = f;
    for(auto v : G[u]){
        if(v != f)dfs(v, u);
    }
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n);
        init();
        for(int i = 2; i <= n; i++)scanf("%lld%lld", &a[i], &b[i]);
        for(int i = 0; i < n-1; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        dfs(1, 0);
        for(int i = 2; i <= n; i++)pq.push(Point(i, a[i], b[i]));
        while(!pq.empty()){
            Point v = pq.top(); pq.pop();
            if(vis[v.id] || a[v.id] != v.a || b[v.id] != v.b)continue;
            vis[v.id] = 1;
            int fa = find(v.id);
            a[fa] += max(0LL, v.a-b[fa]);
            b[fa] = b[v.id]+max(0LL, b[fa]-v.a);
            if(fa != 1)pq.push(Point(fa, a[fa], b[fa]));
        }
        printf("%lld\n", a[1]);
    }
    return 0;
}


