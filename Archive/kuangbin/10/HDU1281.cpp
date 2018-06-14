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
int tmp[maxn];
int n, m, k;

void init()
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(mat, 0, sizeof(mat));
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

bool dfs1(int u, int p, int q)
{
    for(auto v : G[u]){
        if(v == p && u == q)continue;
        if(!vis[v]){
            vis[v] = 1;
            if(!mat[v] || dfs1(mat[v], p, q)){
                mat[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int kase = 1;
    while(scanf("%d%d%d", &n, &m, &k) != EOF){
        init();
        for(int i = 0; i < k; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
        }
        int ans1 = 0, ans2 = 0;
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i))ans2++;
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= m; i++){
            if(mat[i])vis[mat[i]] = 1;
        }
        vector<int> vec;
        for(int i = 1; i <= n; i++){
            if(!vis[i])vec.pb(i);
        }
        ans1 = ans2;
        for(int i = 1; i <= m; i++){
            memset(vis, 0, sizeof(vis));
            if(mat[i]){
                memcpy(tmp, mat, sizeof(tmp));
                int u = mat[i];
                mat[i] = 0;
                vec.pb(u);
                for(auto v : vec){
                    if(dfs1(v, i, u)){
                        ans1--;
                        break;
                    }
                }
                vec.pop_back();
                memcpy(mat, tmp, sizeof(tmp));
            }
        }
        printf("Board %d have %d important blanks for %d chessmen.\n", kase++, ans1, ans2);
    }
    return 0;
}

