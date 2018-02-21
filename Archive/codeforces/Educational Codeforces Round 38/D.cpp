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
const int maxn = 2e5+10;
vector<vector<pair<int, ll> > > G(maxn);
ll cost[maxn];
#define pli pair<ll, int>
priority_queue<pli, vector<pli>, greater<pli> >pq;
int n, m;

void update(int u)
{
    for(int i = 0; i < (int)G[u].size(); i++){
        int v = G[u][i].fi;
        ll w = G[u][i].se;
        if(cost[v] > cost[u]+2*w){
            cost[v] = cost[u]+2*w;
            pq.push(mk(cost[v], v));
            //printf("cost[%d]:%lld\n", v, cost[v]);
        }
    }   
}

int main()
{
    sc(n);sc(m);
    for(int i = 0; i < m; i++){
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        G[u].pb(mk(v, w));
        G[v].pb(mk(u, w));
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld\n", &cost[i]);
        pq.push(mk(cost[i], i));
    }
    while(pq.size()){
        pli p = pq.top(); pq.pop();
        int u = p.se;
        if(cost[u] == p.fi)update(u);
    } 
    for(int i = 1; i <= n; i++)printf("%lld%c", cost[i], " \n"[i==n]);
    return 0;
}

