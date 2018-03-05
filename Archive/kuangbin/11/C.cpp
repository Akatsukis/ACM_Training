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
const int maxn = 1010;
const int maxv = 2010;
string P[maxn], name[maxn], T[maxn], S1[maxn], S2[maxn];
map<string, int> id, mp;
struct es
{
    int to, cap, rev;
};
vector<es> G[maxv];
int lev[maxv];
int iter[maxv];

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
        int u = q.front(); q.pop();
        for(int i = 0; i < (int)G[u].size(); i++){
            es &e = G[u][i];
            if(e.cap > 0 && lev[e.to] < 0){
                lev[e.to] = lev[u]+1;
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
    int n;
    sc(n);
    for(int i = 1; i <= n; i++){
        cin >> P[i];
        if(!id.count(P[i]))id[P[i]] = id.size()+1;
        mp[P[i]]++;
    }
    int m;
    sc(m);
    for(int i = 1; i <= m; i++){
        cin >> name[i] >> T[i];
        if(!id.count(T[i]))id[T[i]] = id.size()+1;
    }
    int t;
    sc(t);
    for(int i = 1; i <= t; i++){
        cin >> S1[i] >> S2[i];
        if(!id.count(S1[i]))id[S1[i]] = id.size()+1;
        if(!id.count(S2[i]))id[S2[i]] = id.size()+1;
    }
    int p = id.size();
    int st = 0, ed = p+m+1;
    for(int i = 1; i <= m; i++){
        add_edge(st, p+i, 1);
        //printf("%d %d\n", st, p+i);
    }
    for(map<string, int>::iterator i = id.begin(); i != id.end(); i++){
        if(mp[(*i).fi])add_edge(id[(*i).fi], ed, mp[(*i).fi]);
        //if(mp[(*i).fi])printf("%d %d\n", id[(*i).fi], ed);
    }
    for(int i = 1; i <= m; i++){
        add_edge(i+p, id[T[i]], 1);
        //printf("%d %d\n", i+p, id[T[i]]);
    }
    for(int i = 1; i <= t; i++){
        add_edge(id[S1[i]], id[S2[i]], INF);
        //printf("%d %d\n", id[S1[i]], id[S2[i]]);
    }
    int ans = max_flow(st, ed);
    printf("%d\n", m-ans);
    return 0;
}

