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
vector<int> G[maxn];
int dep[maxn];
bool mark[maxn];
int ans, root;

void init(int n)
{
    for(int i = 0; i <= n; i++)G[i].clear();
    memset(mark, 0, sizeof(mark));
}

void dfs(int u, int f)
{
    dep[u] = dep[f]+1;
    if(dep[u] > ans && mark[u]){
        ans = dep[u];
        root = u;
    }
    for(auto v : G[u]){
        if(v == f)continue;
        else dfs(v, u);
    }
}

int main()
{
    int T;
    sc(T);
    while(T--){
        int n, m;
        sc(n); sc(m);
        init(n);
        vector<int> vec;
        for(int i = 0; i < m; i++){
            int x; sc(x);
            vec.pb(x);
            mark[x] = 1;
        }
        for(int i = 0; i < n-1; i++){
            int u, v;
            sc(u); sc(v);
            G[u].pb(v);
            G[v].pb(u);
        }
        ans = 0;
        root = vec[0];
        dep[0] = 0;
        dfs(root, 0);
        dep[0] = 0;
        dfs(root, 0);
        printf("%d.00\n", (ans-1)/2);

    }
    return 0;
}

