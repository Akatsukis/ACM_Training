#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
list<int> lst;
vector<vector<int> > G(maxn);
bool vis[maxn];
bool ban[maxn];
int n, m;
vector<int> ans;

int bfs(int u)
{
    queue<int> q;
    q.push(u);
    int res = 0;
    while(!q.empty()){
        int v = q.front();q.pop();
        if(vis[v] == 1)continue;
        vis[v] = 1;res++;
        for(auto &w: G[v])ban[w] = 1;
        for(auto it = lst.begin(); it != lst.end();){
            int w = *it;
            if(!ban[w]){
               q.push(w);
               lst.erase(it++);
            }
            else it++;
        }
        for(auto &w:G[v])ban[w] = 0;
    }
    return res;
}

int main()
{
    sc(n);sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u);sc(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        lst.pb(i);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ans.pb(bfs(i));
        }
    }
    sort(ALL(ans));
    printf("%d\n", (int)ans.size());
    for(int i = 0; i < (int)ans.size(); i++){
        printf("%d%c", ans[i], " \n"[i+1==(int)ans.size()]);
    }
	return 0;
}

