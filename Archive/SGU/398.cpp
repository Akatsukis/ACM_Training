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
const int maxn = 60;
vector<int> ans;
vector<int> G[maxn];
int dist[maxn];

void bfs(int s)
{
    memset(dist, -1, sizeof(dist));
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : G[u]){
            if(dist[v] == -1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, x;
    sc(n); sc(x);
    for(int i = 1; i <= n; i++){
        int t; sc(t);
        for(int j = 0;j < t; j++){
            int k; sc(k);
            G[i].pb(k);
        }
    }
    bfs(x);
    for(int i = 1; i <= n; i++)if(dist[i] == 2)ans.pb(i);
    printf("%d\n", SZ(ans));
    for(int i = 0; i < SZ(ans); i++){
        printf("%d%c", ans[i], " \n"[i==SZ(ans)-1]);
    }
    return 0;
}

