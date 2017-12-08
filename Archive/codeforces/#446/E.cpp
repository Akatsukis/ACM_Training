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
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e5+10;
const int maxh = 50;
int n, m;
struct edge
{
    int u, v, w, next;
}es[maxn*2], es2[maxn*2];
int par[maxn];
int head[maxn];
vector<vector<pii> > G(maxn);
int cnt;
ll d[maxn];
int anc[maxn][maxh];
int dep[maxn];
int info[maxn];


bool cmp(const edge& e1, const edge& e2)
{
    return e1.w < e2.w;
}

int find(int x)
{
    if(x == par[x])return x;
    else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x != y)par[x] = y;
}

void addedge(int u, int v, int w)
{
    es2[cnt].u = u, es2[cnt].v = v, es2[cnt].w = w, es2[cnt].next = head[u], head[u] = cnt;
    cnt++;
    es2[cnt].u = v, es2[cnt].v = u, es2[cnt].w = w, es2[cnt].next = head[v], head[v] = cnt;
    cnt++;
}

ll kru()
{
    sort(es + 1, es + m + 1, cmp);
    for(int i = 0; i <= n; i++)par[i] = i;
    ll res = 0;
    for(int i = 1; i <= m; i++){
        if(find(es[i].u) != find(es[i].v)){
            int u = es[i].u, v = es[i].v, w = es[i].w;
            unite(es[i].u, es[i].v);
            G[u].pb(mk(v, w));
            G[v].pb(mk(u, w));
            addedge(u, v, w);
            res += es[i].w;
        }
    }
    return res;
}

void dij(int s)
{
    priority_queue<pii, vector<pii>, greater<pii> >q;
    fill(d + 1, d + n + 1, INF);
    d[s] = 0;
    q.push(mk(0, s));
    while(!q.empty()){
        pii p = q.top();q.pop();
        int v = p.se;
        if(d[v] < p.fi)continue;
        for(int i = 0; i < (int)G[v].size(); i++){
            pii e = G[v][i];
            if(d[e.fi] > d[v] + e.se){
                q.push(mk(d[e.fi], e.se));
            }
        }
    }
}

void dfs(int root)
{
    static int Stack[maxn];
    int top = 0;
    dep[root] = 1;
    for(int i = 0; i < maxh; i++){
        anc[root][i] = root;
    }
    Stack[++top] = root;
    memcpy(head, info, sizeof(head));
    while(top){
        int x= Stack[top];
        if(x != root){
            for(int i = 1; i < maxh; i++){
                int y = anc[x][i - 1];
                anc[x][i] = anc[y][i-1];
            }
        }
        for(int &i = head[x]; ~i; i = es2[i].next){
            int y = es2[i].v;
            if(y != anc[x][0]){
                dep[y] = dep[x] + 1;
                anc[y][0] = x;
                Stack[++top] = y;
            }
        }
        while(top && head[Stack[top]] == 0)top--;
    }
}

void swim(int &x, int H)
{
    for(int i = 0; H > 0; i++){
        if(H&1)x = anc[x][i];
        H /= 2;
    }
}

int lca(int x, int y)
{
    int i;
    if(dep[x] > dep[y])swap(x, y);
    swim(y, dep[y] - dep[x]);
    if(x == y)return x;
    for(;;){
        for(i = 0; anc[x][i] != anc[y][i]; i++){
            if(i == 0){
                return anc[x][0];
            }
            x = anc[x][i-1];
            y = anc[y][i-1];
        }
    }
}

int main()
{
    sc(n);sc(m);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        sc(u);sc(v);sc(w);
        es[i].u = u, es[i].v = v, es[i].w = w;
    }
    memset(head, -1, sizeof(-1));
    kru();
    dij(1);
    dfs(1);
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        int k;
        sc(k);
        set<int> st;
        bool flag = 1;
        for(int j = 0; j < k; j++){
            int t;
            sc(t);
            int u = es[t].u, v = es[t].v;
            int f = lca(u, v);
            if(d[u]+d[v]-2*d[f] != es[t].w)flag = 0;
        }
        if(flag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

