#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pli pair<ll, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define lson (k*2+1)
#define rson (k*2+2)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6;
int tree[maxn][2];
ll val[maxn];
vector<pii> G[maxn];
ll dist[maxn];
priority_queue<pli, vector<pli>, greater<pli>  > pq;
int nv;

void build(int k, int l, int r)
{
    tree[k][0] = ++nv; tree[k][1] = ++nv;
    if(k){
        G[tree[(k-1)/2][0]].pb(mk(tree[k][0], 0));
        G[tree[k][1]].pb(mk(tree[(k-1)/2][1], 0));
    }
    if(l == r-1){
        G[tree[k][0]].pb(mk(l+1, 0));
        G[l+1].pb(mk(tree[k][1], 0));
        return;
    }
    int m = (l+r)/2;
    build(lson, l, m);
    build(rson, m, r);
}

void update(int a, int b, int k, int l, int r, int v, int w, int t)
{
    if(l >= b || r <= a)return;
    if(l >= a && r <= b){
        if(t == 0)G[v].pb(mk(tree[k][0], w));
        else G[tree[k][1]].pb(mk(v, w));
        //printf("u=%d v=%d, w=%d\n", tree[k], v, w);
        return;
    }
    int m = (l+r)/2;
    update(a, b, lson, l, m, v, w, t);
    update(a, b, rson, m, r, v, w, t);
}

void dijkstra(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    pq.push(mk(0, s));
    while(!pq.empty()){
        int u = pq.top().se;
        ll w = pq.top().fi; 
        pq.pop();
        if(dist[u] < w)continue;
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i].fi, cost = G[u][i].se;
            if(dist[v] > dist[u]+cost){
                dist[v] = dist[u]+cost;
                pq.push(mk(dist[v], v));
            }
        }
    }
}

int main()
{
    int n, q, s;
    sc(n); sc(q); sc(s);
    nv = n;
    build(0, 0, n);
    for(int i = 0; i < q; i++){
        int t, v, l, r, w;
        sc(t);
        if(t == 1){
           sc(l); sc(r); sc(w);
           G[l].pb(mk(r, w));
        }
        else if(t == 2){
            scanf("%d%d%d%d", &v, &l, &r, &w);
            update(l-1, r, 0, 0, n, v, w, 0);
        }
        else{
            scanf("%d%d%d%d", &v, &l, &r, &w);
            update(l-1, r, 0, 0, n, v, w, 1);
        }
    }
    dijkstra(s);
    for(int i = 1; i <= n; i++){
        printf("%lld%c", dist[i]==INF64?-1:dist[i], " \n"[i==n]);
    }
    return 0;
}
