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
int n, k, root;
const int maxn = 1e5+10;
int w[maxn];
int del[maxn];
int f[maxn];
vector<vector<int> > G(maxn);

void dfs(int u, int fa)
{
    if(w[u] < k && u != root){
        del[u] = 1;
        //pr(u);
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i];
            f[v] = fa;
        }
    }
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        dfs(v, f[v]);
    }
}

int main()
{
    sc(n);sc(k);
    for(int i = 1; i <= n; i++){
        sc(w[i]);
    }
    for(int i = 1; i <= n; i++){
        int u;
        sc(u);
        if(!u)root = i;
        else{
            f[i] = u;
            G[u].pb(i);
        }
    }
    dfs(root, root);
    for(int i = 1; i <= n; i++){
        if(del[i])printf("-1%c", " \n"[i==n]);
        else printf("%d%c", f[i], " \n"[i==n]);
    }
    return 0;
}

