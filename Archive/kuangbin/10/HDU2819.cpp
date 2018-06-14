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
const int maxn = 1e2+10;
vector<int> G[maxn];
bool vis[maxn];
int mat[maxn];
vector<pii> res;
int n;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(mat, 0, sizeof(mat));
    res.clear();
}

bool dfs(int u)
{
    for(auto v : G[u]){
        if(!vis[v]){
            vis[v] = 1;
            if(!mat[v] || dfs(mat[v])){
                mat[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

void get_ans(int u)
{
    vis[u] = 1;
    if(!vis[mat[u]]){
        res.pb(mk(u, mat[u]));
        get_ans(mat[u]);
    }
}

int main()
{
    while(scanf("%d", &n) != EOF){
        init();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int t; sc(t);
                if(t)G[i].pb(j);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i))ans++;
        }
        if(ans != n)printf("-1\n");
        else{
            memset(vis, 0, sizeof(vis));
            for(int i = 1; i <= n; i++){
                if(!vis[i])get_ans(i);
            }
            printf("%d\n", (int)res.size());
            for(auto p : res)printf("R %d %d\n", p.fi, p.se);
        }
    }
    return 0;
}

