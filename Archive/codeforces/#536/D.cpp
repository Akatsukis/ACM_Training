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

int main()
{
    int n, m;
    sc(n); sc(m);
    vector<vector<int> > G(n, vector<int>());
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u); sc(v);
        u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    vector<bool> vis(n, 0);
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(0);
    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        if(!vis[u])vis[u] = 1;
        else continue;
        ans.pb(u);
        for(auto v : G[u]){
            if(!vis[v])pq.push(v);
        }
    }
    for(auto u : ans)printf("%d ", u+1);
    return 0;
}

