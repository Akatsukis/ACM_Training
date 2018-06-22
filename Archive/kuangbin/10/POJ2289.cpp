#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;
#define pb push_back
#define mk make_pair
#define fi first
#define se second
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int maxs = 1e5+10;
const int maxn = 2e3+10;
const int maxm = 1e6+10;
char s[maxs];
vector<pii> tb;
int head[maxn], lev[maxn], iter[maxn];
struct edge
{
    int to, cap, nxt;
}es[maxm];
int n, m, src, dst, cnt;

void init()
{
    tb.clear();
}

void add_edge(int u, int v, int cap)
{
    //printf("add_edge(%d, %d,%d)\n", u, v, cap);
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
            if(e.cap && lev[e.to] < 0){
                lev[e.to] = lev[v]+1;
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

void build(int mid)
{
    memset(head, -1, sizeof(head));
    cnt = 0;
    for(int i = 0; i < (int)tb.size(); i++){
        pii ele = tb[i];
        add_edge(ele.fi, ele.se, 1);
    }
    for(int i = 0; i < n; i++){
        add_edge(src, i, 1);
    }
    for(int i = 0; i < m; i++){
        add_edge(i+n, dst, mid);
    }
}

int main()
{
    while(scanf("%d%d ", &n, &m) != EOF && (n||m)){
        init();
        for(int i = 0; i < n; i++){
            fgets(s, maxn, stdin);
            int len = strlen(s);
            bool flg = 1;
            int now = 0;
            for(int j = 0; j < len; j++){
                if(isdigit(s[j])){
                    flg = 0;
                    now = now*10+s[j]-'0';
                }
                else if(!flg){
                    tb.pb(mk(i, n+now));
                    //printf("now=%d\n", now);
                    now = 0;
                }
            }
        }
        src = n+m, dst = src+1;
        int l = 0, r = n, ans = 0;
        while(l <= r){
            int mid = (l+r)>>1;
            build(mid);
            if(max_flow(src, dst) == n){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        printf("%d\n", ans);
    }
}
