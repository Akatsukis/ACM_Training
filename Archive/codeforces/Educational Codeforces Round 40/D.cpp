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
const int maxn = 1100;
int d1[maxn], d2[maxn];
bool vis[maxn];
bool mp[maxn][maxn];
vector<int> G[maxn];
int n, m, s, t;

void spfa(int dist[], int st)
{
    for(int i = 0; i <= n; i++)dist[i] = INF;
    memset(vis, 0, sizeof(vis));
    dist[st] = 0; vis[st] = 1;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i];
            if(dist[v] > dist[u]+1){
                dist[v] = dist[u]+1;
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        vis[u] = 0;
    }
}

int main()
{
    sc(n); sc(m); sc(s); sc(t);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v);
        G[v].pb(u);
        mp[u][v] = mp[v][u] = 1;
    }
    spfa(d1, s);
    spfa(d2, t);
    int ans = n*(n-1)/2-m;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(mp[i][j])continue;
            if((d1[i]+d2[j]+1<d1[t])||(d1[j]+d2[i]+1<d1[t])){
                ans--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

