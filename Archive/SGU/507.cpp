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
const int maxn = 5e4+10;
set<int> st[maxn];
vector<int> G[maxn];
int id[maxn];
int ans[maxn];

void dfs(int u)
{
    for(auto v : G[u]){
        dfs(v);
        ans[u] = min(ans[u], ans[v]);
        int p = id[u], q = id[v];
        if(SZ(st[p]) > SZ(st[q]))swap(p, q);
        for(auto it = st[p].begin(); it != st[p].end(); it++){
            auto t1 = st[q].lower_bound(*it);
            if(t1 != st[q].end())ans[u] = min(ans[u], *t1-*it);
            if(t1 != st[q].begin()){
                t1--;
                ans[u] = min(ans[u], *it-*t1);
            }
            st[q].insert(*it);
        }
        id[u] = q;
    }
}

int main()
{
    int n, m;
    sc(n); sc(m);
    for(int i = 1; i <= n; i++)ans[i] = (1LL<<31)-1, id[i] = i;
    for(int i = 2; i <= n; i++){
        int f; sc(f);
        G[f].pb(i);
    }
    for(int i = n-m+1; i <= n; i++){
        int x; sc(x);
        st[i].insert(x);
    }
    dfs(1);
    for(int i = 1; i <= n-m; i++)printf("%d%c", ans[i], " \n"[i==n-m]);
    return 0;
}

