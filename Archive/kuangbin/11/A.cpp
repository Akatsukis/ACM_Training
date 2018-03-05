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
const int maxp = 20;
struct es
{
    int to, cap, rev;
};
vector<es> G[maxn];
int p, n;
int Q[maxn], S[maxn][maxp], D[maxn][maxp];
int lev[maxn];
int iter[maxn];
map<pii, int> mp;
int res[maxn][maxn];
struct Link
{
    int from, to, cap;
};
vector<Link> ans;

void add_edge(int from, int to, int cap)
{
    G[from].pb((es){to, cap, (int)G[to].size()});
    G[to].pb((es){from, 0, (int)G[from].size()-1});
}

void bfs(int s)
{
    memset(lev, -1, sizeof(lev));
    queue<int> q;
    lev[s] = 0;
    q.push(s);
    while(q.size()){
        int v = q.front(); q.pop();
        for(int i = 0; i < (int)G[v].size(); i++){
            es &e = G[v][i];
            if(e.cap > 0 && lev[e.to] < 0){
                lev[e.to] = lev[v]+1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if(v == t)return f;
    for(int &i = iter[v]; i < (int)G[v].size(); i++){
        es &e = G[v][i];
        if(e.cap > 0 && lev[e.to] > lev[v]){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                int nu = v>n?v-n:v, nv = e.to>n?e.to-n:e.to;
                mp[mk(nu, nv)] += d;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while(1){
        bfs(s);
        if(lev[t] < 0)return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, INF)) > 0){
            flow += f;
        }
    }
    return flow;
}

int main()
{
    sc(p);sc(n);
    for(int i = 1; i <= n; i++){
        sc(Q[i]);
        for(int j = 1; j <= p; j++){
            sc(S[i][j]);
        }
        for(int j = 1; j <= p; j++){
            sc(D[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        add_edge(i, i+n, Q[i]);
    }
    int st = 0, ed = 2*n+1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= p; j++){
            if(S[i][j] == 1)break;
            if(j == p)add_edge(st, i, INF);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            for(int k = 1; k <= p; k++){
                if((S[j][k]==1&&D[i][k]==0)||(S[j][k]==0&&D[i][k]==1))break;
                if(k == p)add_edge(i+n, j, INF);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= p; j++){
            if(D[i][j] != 1)break;
            if(j == p)add_edge(i+n, ed, INF);
        }
    }
    int mx = max_flow(st, ed);
    for(map<pii, int>::iterator i = mp.begin(); i != mp.end(); i++){
        res[((*i).fi).fi][((*i).fi).se] += (*i).se;        
    }
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int f = res[i][j] - res[j][i];
            if(f > 0)ans.pb((Link){i, j, f});
            else if(f < 0)ans.pb((Link){j, i, -f});
        }
    }
    printf("%d %d\n", mx, (int)ans.size());
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d %d %d\n", ans[i].from, ans[i].to, ans[i].cap);
    }
    return 0;
}

