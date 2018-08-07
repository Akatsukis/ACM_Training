#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 2e5+10;
vector<int> row[maxn];
vector<int> col[maxn];
int par[maxn];
int vis[maxn];
bool vr[maxn], vc[maxn];
map<int, int> mp;

int find(int x)
{
    return x == par[x] ? x : par[x] = find(par[x]);
}

void unite(int x, int y)
{
    x = find(x); y = find(y);
    if(x != y)par[x] = y;
}

void init()
{
    for(int i = 0; i < maxn; i++)par[i] = i, vis[i] = 0;
    mp.clear();
}

int main()
{
    int n, m, q;
    sc(n); sc(m); sc(q);
    for(int i = 0; i < q; i++){
        int r, c;
        sc(r); sc(c);
        row[r].pb(c);
        col[c].pb(r);
        vr[r] = vc[c] = 1;
    }
    init();
    for(int i = 1; i <= n; i++){
        for(auto u : row[i]){
            if(vis[u])unite(vis[u], i);
            else vis[u] = i;
        }
    }
    for(int i = 1; i <= n; i++)mp[find(i)]++;
    int ans1 = mp.size()-1;
    for(int i = 1; i <= m; i++)if(!vc[i])ans1++;
    
    init();
    for(int i = 1; i <= m; i++){
        for(auto u : col[i]){
            if(vis[u])unite(vis[u], i);
            else vis[u] = i;
        }
    }
    for(int i = 1; i <= m; i++)mp[find(i)]++;
    int ans2 = mp.size()-1;
    for(int i = 1; i <= n; i++)if(!vr[i])ans2++;
    printf("%d\n", min(ans1, ans2));
    return 0;
}


