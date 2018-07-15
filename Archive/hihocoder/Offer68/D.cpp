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
int dep[maxn];
int mx, root;

void dfs(int u, int f)
{
    dep[u] = dep[f]+1;
    if(dep[u] > mx){
        mx = dep[u];
        root = u;
    }
    for(auto v : G[u]){
        if(v == f)continue;
        dfs(v, u);
    }
}

int main()
{
    int n; sc(n);
    if(n == 1 || n == 2){
        printf("%d\n", 0);
        return 0;
    }
    for(int i = 0; i < n-1; i++){
        int u, v;
        sc(u); sc(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    mx = root = 1;
    dfs(root, 0);
    mx = 1;
    dfs(root, 0);
    int ans = 0;
    while(mx > 2){
        mx -= (mx-1)/2;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

