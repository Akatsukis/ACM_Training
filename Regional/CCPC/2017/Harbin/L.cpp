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
const int maxn = 1e5+10;
vector<int> G[maxn];
vector<int> ra[maxn], rb[maxn];
int mx[maxn], mn[maxn], sz[maxn];
int n;
bool flg;

void init()
{
    for(int i = 0; i <= n; i++){
        G[i].clear();
        ra[i].clear();
        rb[i].clear();
    }
}

void get_size(int u, int f)
{
    sz[u] = 1;
    for(auto v : G[u]){
        if(v == f)continue;
        get_size(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int f, int m)
{
    for(auto v : ra[u])mn[u] = max(mn[u], v);
    for(auto v : rb[u])mx[u] = min(mx[u], m-v);
    int l = 0, r = 1;
    for(auto v : G[u]){
        if(v == f)continue;
        dfs(v, u, m);
        l += mn[v], r += mx[v];
    }
    mn[u] = max(mn[u], l), mx[u] = min(mx[u], r);
    if(mn[u] > mx[u])flg = 0;
}

bool judge(int m)
{
    flg = 1;
    for(int i = 1; i <= n; i++){
        mn[i] = 0, mx[i] = sz[i];
    }
    dfs(1, 0, m);
    if(mn[1] > m | mx[1] < m)flg = 0;
    return flg;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        sc(n);
        init();
        for(int i = 0; i < n-1; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        int a, b;
        sc(a);
        for(int i = 0; i < a; i++){
            int u, x;
            scanf("%d%d", &u, &x);
            ra[u].pb(x);
        }
        sc(b);
        for(int i = 0; i < b; i++){
            int u, x;
            scanf("%d%d", &u, &x);
            rb[u].pb(x);
        }
        get_size(1, 0);
        int l = 0, r = n, ans = -1;
        while(l <= r){
            int m = (l+r)>>1;
            if(judge(m)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

