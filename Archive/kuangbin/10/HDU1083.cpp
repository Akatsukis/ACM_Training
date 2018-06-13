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
const int maxn = 3e2+10;
vector<int> G[maxn];
int mat[maxn];
bool vis[maxn];
int n, m;

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

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n); sc(m);
        init();
        for(int i = 1; i <= n; i++){
            int k; sc(k);
            for(int j = 1; j <= k; j++){
                int t; sc(t);
                G[i].pb(t);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i))ans++;
        }
        if(ans == n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

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
const int maxn = 3e2+10;
vector<int> G[maxn];
int mat[maxn];
bool vis[maxn];
int n, m;

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

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n); sc(m);
        init();
        for(int i = 1; i <= n; i++){
            int k; sc(k);
            for(int j = 1; j <= k; j++){
                int t; sc(t);
                G[i].pb(t);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i))ans++;
        }
        if(ans == n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

