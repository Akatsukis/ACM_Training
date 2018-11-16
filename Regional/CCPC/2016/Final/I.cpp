#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const int maxw = 1e4+10;
const int maxn = 2e2+10;
int t[maxn], price[maxn], cost[maxn];
ll dp[maxw];
vector<pii> G[maxn];
int m, n, k;

void init()
{
    for(int i = 1; i <= n; i++)cost[i] = 2e4;
    for(int i = 0; i <= m; i++)dp[i] = 0;
    for(int i = 0; i < k; i++)G[i].clear();
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &m, &n, &k);
        init();
        priority_queue<pll, vector<pll>, greater<pll> > pq;
        for(int i = 1; i <= n; i++){
            int t;
            scanf("%d", &t);
            if(t == 0)scanf("%d", &price[i]);
            else scanf("%d%d", &cost[i], &price[i]), pq.push(mk(cost[i], i));
        }
        for(int i = 0; i < k; i++){
            int x, y;
            scanf("%d%d", &x, &y);
            G[i].pb(mk(x, y));
            for(int j = 0; j < y; j++){
                int u, v;
                scanf("%d%d", &u, &v);
                G[i].pb(mk(u, v));
            }
        }
        while(!pq.empty()){
            pll p = pq.top(); pq.pop();
            if(p.fi != cost[p.se])continue;
            for(int i = 0; i < k; i++){
                int v = G[i][0].fi, t = G[i][0].se;
                long long tot = 0;
                for(int j = 1; j <= t; j++){
                    tot += 1LL*cost[G[i][j].fi]*G[i][j].se;
                }
                if(cost[v] > tot){
                    cost[v] = tot;
                    pq.push(mk(cost[v], v));
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j+cost[i] <= m; j++){
                dp[j+cost[i]] = max(dp[j+cost[i]], dp[j]+price[i]);
            }
        }
        ll ans = 0;
        for(int j = 0; j <= m; j++)ans = max(ans, dp[j]);
        printf("Case #%d: %lld\n", kase++, ans);
    }
    return 0;
}
