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
const int maxn = 110;
const int maxv = 40100;
const int maxe = 1000010;
struct Node
{
    int hor = 0, ver = 0;
    bool white;
    void input(char s[10]){
        ver = 0;
        if(isdigit(s[0])){
            for(int i = 0; i < 3; i++){
                ver = ver*10+s[i]-'0';
            }
        }
        hor = 0;
        if(isdigit(s[4])){
            for(int i = 4; i < 7; i++){
                hor = hor*10+s[i]-'0';
            }
        }
        if(s[0] == '.')white = 1;
        else white = 0;
    }
}mp[maxn][maxn];
struct edge
{
    int to, cap, f, next;
}es[maxe];
int head[maxv];
int iter[maxv];
int lev[maxv];
int cnt;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int from, int to, int cap)
{
    //printf("add(%d,%d,%d)\n", from, to, cap);
    es[cnt].to = to, es[cnt].cap = cap, es[cnt].f = 0, es[cnt].next = head[from];
    head[from] = cnt++;
    es[cnt].to = from, es[cnt].cap = 0, es[cnt].f = 0, es[cnt].next = head[to];
    head[to] = cnt++;
}

bool bfs(int s, int t)
{
    memset(lev, -1, sizeof(lev));
    lev[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int i = head[v]; ~i; i = es[i].next){
            edge &e = es[i];
            if(e.cap > e.f && lev[e.to] < 0){
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
    for(int &i = iter[v]; ~i; i = es[i].next){
        edge &e = es[i];
        if(e.cap > e.f && lev[e.to] == lev[v]+1){
            int d = dfs(e.to, t, min(e.cap-e.f, f-ret));
            if(d){
                e.f += d;
                es[i^1].f -= d;
                ret += d;
                if(ret == f)break;
            }
        }
    }
    return ret;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while(bfs(s, t)){
        memcpy(iter, head, sizeof(head));
        flow += dfs(s, t, INF);
    }
    return flow;
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        int src = n*m*2, dst = src+1;
        int num = dst+1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char s[10];
                scanf("%s", s);
                mp[i][j].input(s);
                if(mp[i][j].white)add_edge(i*m+j, i*m+j+n*m, 8);
            }
        }
        for(int i = 0; i < n; i++)mp[i][m].white = 0;
        for(int i = 0; i < m; i++)mp[n][i].white = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m;){
                if(mp[i][j].hor){
                    int k = 1;
                    while(mp[i][j+k].white)k++;
                    mp[i][j].hor -= k-1;
                    add_edge(src, num, mp[i][j].hor);
                    for(k = 1;; k++){
                        if(!mp[i][j+k].white){
                            j += k;
                            break;
                        }
                        else add_edge(num, i*m+(j+k), INF);
                    }
                    num++;
                }
                else j++;
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;){
                if(mp[j][i].ver){
                    int k = 1;
                    while(mp[j+k][i].white)k++;
                    mp[j][i].ver -= k-1;
                    add_edge(num, dst, mp[j][i].ver);
                    for(k = 1;; k++){
                        if(!mp[j+k][i].white){
                            j += k;
                            break;
                        }
                        else add_edge((j+k)*m+i+n*m, num, INF);
                    }
                    num++;
                }
                else j++;
            }
        }
        max_flow(src, dst);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(mp[i][j].white){
                    for(int k = head[i*m+j]; ~k; k = es[k].next)
                        if(es[k].to == i*m+j+n*m){
                            printf("%d%c", es[k].f+1, " \n"[j==m-1]);
                            break;
                        }
                }
                else printf("_%c", " \n"[j==m-1]);
            }       
    }
    return 0;
}

