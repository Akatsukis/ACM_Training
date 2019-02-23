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
vector<int> vec[maxn];
int par[maxn];

int find(int x)
{
    return par[x] == x ? x : par[x] = find(par[x]);
}

int main()
{
    int n;
    sc(n);
    for(int i = 1; i <= n; i++)par[i] = i, vec[i].pb(i);
    for(int i = 0; i < n-1; i++){
        int x, y;
        sc(x); sc(y);
        int u = find(x), v = find(y);
        if(SZ(vec[u]) >= SZ(vec[v])){
            for(auto x : vec[v])vec[u].pb(x);
            par[v] = u;
        }
        else{
            for(auto x : vec[u])vec[v].pb(x);
            par[u] = v;
        }
    }
    for(int i = 1; i <= n; i++){
        if(SZ(vec[i]) == n){
            for(auto u : vec[i])printf("%d ", u);
        }
    }
    return 0;
}

