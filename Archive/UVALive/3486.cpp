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
#define ALL(x) x.begin(), x.ed()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 2e7+10;
vector<int> G[maxn];
int beg[maxn], ed[maxn];
bool vis[maxn];
int n, idx;

void init()
{
    for(int i = 0; i < min(maxn, n*100); i++)G[i].clear(), vis[i] = 0;
    idx = 1;
}

void solve()
{
    stack<int> sk;
    sk.push(0);
    idx = 0;
    while(!sk.empty()){
        int u = sk.top();
        if(!vis[u]){
            vis[u] = 1;
            beg[u] = idx++;
            for(auto v : G[u])sk.push(v);
        }
        else{
            ed[u] = idx++;
            sk.pop();
        }
    }
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n);
        init();
        for(int i = 0; i < n; i++){
            int x; sc(x);
            for(int j = idx; j < idx+x; j++)G[i].pb(j);
            idx += x;
        }
        solve();
        printf("Case %d:\n", kase++);
        int q; sc(q);
        for(int i = 0; i < q; i++){
            int u, v;
            sc(u); sc(v);
            if(beg[u] < beg[v] && ed[u] > beg[v])puts("Yes");
            else puts("No");
        }
        if(T)puts("");
    }
    return 0;
}

