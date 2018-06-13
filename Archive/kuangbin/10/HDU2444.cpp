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
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e2+10;
vector<int> G[maxn];
int col[maxn];
bool vis[maxn], flg;
int n, m, cnt1, cnt2;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(vis, 0, sizeof(vis));
    memset(col, -1, sizeof(col));
    flg = 1;
}

void dfs(int u)
{
    vis[u] = 0;
    if(col[u])cnt1++;
    else cnt2++;
    for(auto v : G[u]){
        if(!vis[u] && col[v] == col[u])flg = 0;
        else if(vis[v]){
            col[v] = (col[u]+1)%2;
            dfs(v);
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF){
        init();
        for(int i = 0; i < m; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
            vis[u] = vis[v] = 1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i]){
                col[i] = cnt1 = cnt2 = 0;
                dfs(i);
                ans += min(cnt1, cnt2);
            }   
        }
        if(flg)printf("%d\n", ans);
        else printf("No\n");
    }
    return 0;
}

