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
const int maxn = 1e3+10;
const int maxm = 1e5+10;
struct edge
{
    int u, v, w;
    bool operator < (const edge& rhs)const
    {
        return w < rhs.w;
    }
}es[maxm];
int mat[maxn], rev[maxn], vis[maxn];
vector<int> G[maxn];
vector<int> G2[maxn];

bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v]){
            vis[v] = 1;
            if(!mat[v] || dfs(mat[v])){
                mat[v] = u;
                rev[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

bool dfs2(int u)
{
    for(auto v : G[u]){
        if(!vis[v]){
            vis[v] = 1;
            if(!rev[v] || dfs2(rev[v])){
                rev[v] = u;
                mat[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &es[i].u, &es[i].v, &es[i].w);
    }
    sort(es, es+m);
    int ans = 0, cnt = 0;
    for(int i = 0; i < m; i++){
        int u = es[i].u, v = es[i].v, w = es[i].w;
        //printf("u=%d v=%d w=%d\n", u, v, w);
        G[u].pb(v);
        G2[v].pb(u);
        ans = w;
        if(!rev[u]){
            memset(vis, 0, sizeof(vis));
            if(dfs(u)){
                cnt++;
                printf("%d%c", ans, " \n"[cnt==n]);
            }
        }
        if(!mat[v]){
            memset(vis, 0, sizeof(vis));
            if(dfs2(v)){
                cnt++;
                printf("%d%c", ans, " \n"[cnt==n]);
            }
        }
        //for(int j = 1; j <= n; j++)printf(">>%d ", mat[j]);
        //puts("");
    }
    cnt++;
    for(; cnt <= n; cnt++)printf("-1%c", " \n"[cnt==n]);
    return 0;
}

