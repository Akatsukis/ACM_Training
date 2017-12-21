#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e5+10;
vector<vector<int> > G(maxn);
int dfn[maxn], low[maxn];
int xl[maxn], xr[maxn];
int cnt, dep;
stack<int> sk;
int to[maxn];
ll sum[maxn];

void dfs(int u, int f)
{
    dfn[u] = low[u] = ++dep;
    sk.push(u);
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i];
        if(v == f)continue;
        if(!dfn[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]){
        xl[cnt] = xr[cnt] = u;
        while(sk.top() != u){
            xl[cnt] = min(xl[cnt], sk.top());
            xr[cnt] = max(xr[cnt], sk.top());
            sk.pop();
        }
        sk.pop();
        cnt++;

    }
}

int main()
{
    int n, m;
    sc(n);sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u);sc(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i])dfs(i, 0);
    }
    for(int i = 1; i <= n; i++)to[i] = n;
    for(int i = 0; i < cnt; i++){
        if(xl[i] != xr[i]){
            to[xl[i]] = xr[i] - 1;
        }
    }

    for(int i = n-1; i >= 1; i--){
        to[i] = min(to[i], to[i+1]);
    }
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i-1] + (to[i]-i+1);
    }
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        int l, r, p, L, R;
        sc(L);sc(R);
        l = L, r = R, p = R+1;
        while(l <= r){
            int m = (l+r)/2;
            if(to[m] >= R){
                p = m;
                r = m-1;
            }
            else l = m+1;
        }
        //pr(p);
        ll ans = sum[p-1] - sum[L-1] + (ll)(R-p+2)*(R-p+1)/2;
        printf("%lld\n", ans);
    }
    return 0;
}

