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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
vector<pii> G[maxn];
int deg[maxn];
struct edge
{
    int u, v;
}es[maxn];
pii vis[maxn];
int cnt[maxn];

void init(int n)
{
    memset(deg, 0, sizeof(deg));
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i <= n; i++)G[i].clear();
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        init(n);
        for(int i = 1; i <= m; i++){
            int u, v;
            sc(u); sc(v);
            es[i].u = u, es[i].v = v;
            deg[u]++, deg[v]++;
        }
        for(int i = 1; i <= m; i++){
            int u = es[i].u, v = es[i].v;
            if(deg[u] < deg[v] || (deg[u] == deg[v] && u < v))G[u].pb(mk(v, i));
            else G[v].pb(mk(u, i));
        }
        for(int i = 1; i <= m; i++){
            int u = es[i].u, v = es[i].v;
            for(auto w : G[u])vis[w.fi].fi = i, vis[w.fi].se = w.se;
            for(auto w : G[v]){
                if(vis[w.fi].fi == i){
                    cnt[i]++; cnt[w.se]++, cnt[vis[w.fi].se]++;
                }
            }
        }
        ll ans = 0;
        for(int i = 1; i <= m; i++){
            ans += 1LL*cnt[i]*(cnt[i]-1)/2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

