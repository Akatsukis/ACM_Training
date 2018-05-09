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
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e3+10;
const int maxm = 1e4+10;
int head[maxn], iter[maxn], lev[maxn];
struct edge
{
    int to, cap, nxt;
}es[maxm];
int cnt;

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
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int i = head[v]; ~i; i = es[i].nxt){
            edge &e = es[i];
            if(e.cap && lev[e.to] == -1){
                lev[e.to] = lev[v]+1;
                if(e.to == t)return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

ll dfs(int v, int t, ll f)
{
    if(v == t)return f;
    ll ret = 0;
    for(int &i = iter[v]; ~i; i = es[i].nxt){
        edge &e = es[i];
        if(e.cap && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min((ll)e.cap, f-ret));
            if(d){
                ret += d;
                e.cap -= d;
                es[i^1].cap += d;
                if(ret == f)break;
            }
        }
    }
    if(!ret)lev[v] = 0;
    return ret;
}

ll max_flow(int s, int t)
{
    ll ret = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        ret += dfs(s, t, INF64);
    }
    return ret;
}

struct Trie
{
    int nxt[maxn][2], cost[maxn][2];
    int idx;
    void init()
    {
        idx = 3;
        memset(nxt, 0, sizeof(nxt));
    }
    void insert(int x)
    {
        int rt = 1;
        for(int i = 7; i >= 0; i--){
            int u = (x>>i)&1;
            if(!nxt[rt][u]){
                nxt[rt][u] = idx++;
                cost[rt][u] = INF;
            }
            rt = nxt[rt][u];
        }
        int prt = rt;
        rt = 2;
        for(int i = 0; i <= 7; i++){
            int u = (x>>i)&1;
            if(!nxt[rt][u]){
                nxt[rt][u] = idx++;
                cost[rt][u] = INF;
            }
            rt = nxt[rt][u];
        }
        int srt = rt;
        add_edge(prt, srt, INF);
    }
    void update(int rt, char s[], int val)
    {
        int len = strlen(s);
        for(int i = 0; i < len; i++){
            int u = s[i]-'0';
            if(!nxt[rt][u])return;
            if(i == len-1)cost[rt][u] = min(cost[rt][u], val);
            rt = nxt[rt][u];
        } 
    }
    void dfs(int u, int k)
    {
        for(int i = 0; i < 2; i++){
            if(nxt[u][i]){
                if(k == 1)add_edge(u, nxt[u][i], cost[u][i]);
                else add_edge(nxt[u][i], u, cost[u][i]);
                dfs(nxt[u][i], k);
            }
        }
    }   
    void build()
    {
        dfs(1, 1); dfs(2, 2);
    }
}trie;

void init()
{
    trie.init();
    memset(head, -1, sizeof(head));
    cnt = 0;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        init();
        int n, m;
        sc(n); sc(m);
        for(int i = 0; i < n; i++){
            int x; sc(x);
            trie.insert(x);
        }
        for(int i = 0; i < m; i++){
            char s[10], t[10];
            int w;
            scanf("%s%s%d", s, t, &w);
            int k = s[0]=='P'?1:2;
            if(k == 2)reverse(t, t+strlen(t));
            trie.update(k, t, w);
        }
        int src = 1, dst = 2;
        trie.build();
        ll ans = max_flow(src, dst);
        if(ans >= INF)printf("Case #%d: -1\n", kase++);
        else printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}

