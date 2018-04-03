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
const int maxn = 1e2+10;
const int maxm = 1e4+10;
struct edge
{
    int to, cap, nxt;
}es[maxm];
int head[maxn], iter[maxn], lev[maxn];
int deg[maxn];
bool vis[maxn];
int par[maxn];
int cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= 26; i++)par[i] = i;
}

void add_edge(int u, int v, int cap)
{
    //printf("add(%d,%d,%d)\n", u, v, cap);
    es[cnt].to = v, es[cnt].cap = cap, es[cnt].nxt = head[u];
    head[u] = cnt++;
    es[cnt].to = u, es[cnt].cap = 0, es[cnt].nxt = head[v];
    head[v] = cnt++;
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; ~i; i = es[i].nxt){
            edge &e = es[i];
            if(e.cap && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    int ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.cap && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap, f-ret));
            if(d){
                e.cap -= d;
                es[i^1].cap += d;
                ret += d;
                if(ret == f)break;
            }
        }
    }
    if(!ret)lev[v] = 0;
    return ret;
}

int max_flow(int s, int t)
{
    int ret = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        ret += dfs(s, t, INF);
    }
    return ret;
}

int find(int x)
{
    return par[x] == x ? par[x] : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    if(x != y)par[x] = y;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        int n; sc(n);
        init();
        int rt = 0;
        for(int i = 0; i < n; i++){
            char s[50]; int d;
            scanf("%s%d", s, &d);
            int len = strlen(s);
            int u = s[0]-'a', v = s[len-1]-'a';
            unite(u, v);
            vis[u] = vis[v] = 1;
            rt = u;
            deg[u]++, deg[v]--;
            if(d == 1)add_edge(u, v, 1);
        }
        bool flg = 1;
        int src = 27, dst = src+1;
        vector<int> num;
        for(int i = 0; i < 26; i++){
            //printf("deg[%d]:%d\n", i, deg[i]);
            if(deg[i]%2 != 0){
                num.pb(i);
                if(num.size() == 1)deg[i]++;
                else if(num.size() == 2)deg[i]--, add_edge(num[0], i, 1);
                else break;
            }
                if(deg[i] > 0)add_edge(src, i, deg[i]/2);
                else if(deg[i] < 0)add_edge(i, dst, -deg[i]/2);
        }
        //for(int i = 0; i < 26; i++)printf("deg[%d]:%d\n", i, deg[i]); 
        if(num.size() != 2 && num.size() != 0)flg = 0;
        for(int i = 0; i < 26; i++){
            if(!vis[i])continue;
            if(find(i) != find(rt)){
                flg = 0;
                break;
            }
        }
        if(!flg){
            printf("Case %d: Poor boy!\n", kase++);
            continue;
        }
        max_flow(src, dst);
        for(int i = head[src]; ~i; i = es[i].nxt){
            if(es[i].cap){
                flg = 0;
                break;
            }
        }
        if(!flg)printf("Case %d: Poor boy!\n", kase++);
        else printf("Case %d: Well done!\n", kase++);
    }
    return 0;
}

