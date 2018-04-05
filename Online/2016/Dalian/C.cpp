#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pli pair<ll, int>
#define pll pair<ll, ll>
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
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e4+10;
vector<pii> G[maxn];
int dist1[maxn], dist2[maxn];
ll cnt1[maxn], cnt2[maxn];
ll hash_cnt[maxn], hash_dist[maxn];
pll qry[maxn];
int ls[maxn*32], rs[maxn*32], sum[maxn*32], root[maxn*32];
int n, m, x, idx;
priority_queue<pli, vector<pli>, greater<pli> >pq;

void init(int n)
{
    memset(dist1, 0x3f, sizeof(dist1));
    memset(dist2, 0x3f, sizeof(dist2));
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    idx = 0;
    for(int i = 0; i <= n; i++)G[i].clear();
}

void dijkstra(int s, int dist[], ll cnt[])
{
    dist[s] = 0; cnt[s] = 1;
    pq.push(mk(0LL, s));
    while(!pq.empty()){
        ll w = pq.top().fi; int u = pq.top().se; pq.pop();
        if(w > dist[u])continue;
        for(auto v : G[u]){
            if(dist[v.fi] > dist[u]+v.se){
                dist[v.fi] = dist[u]+v.se;
                cnt[v.fi] = cnt[u];
                pq.push(mk(dist[v.fi], v.fi));
            }
            else if(dist[v.fi] == dist[u]+v.se){
                cnt[v.fi] += cnt[u];
                if(cnt[v.fi] > x)cnt[v.fi] = x;
            }
        }
    }
}

void build(int &rt, int l, int r)
{
    rt = ++idx;
    sum[rt] = ls[rt] = rs[rt] = 0;
    if(l == r-1)return;
    int m = (l+r)>>1;
    build(ls[rt], l, m);
    build(rs[rt], m, r);
}

void update(int &rt, int l, int r, int last, int val)
{
    //printf("update(%d,%d,%d)\n", l, r, val);
    rt = ++idx;
    sum[rt] = sum[last]+1, ls[rt] = ls[last], rs[rt] = rs[last];
    if(l == r-1)return;
    int m = (l+r)>>1;
    if(val < m)update(ls[rt], l, m, ls[last], val);
    else update(rs[rt], m, r, rs[last], val);
}


int query(int rt, int l, int r, int qval)
{
    //printf("query(%d,%d,%d)\n", l, r, qval);
    //printf("sum[%d]:%d\n", rt, sum[rt]);
    if(qval <= l)return sum[rt];
    if(qval >= r)return 0;
    int ret = 0;
    int m = (l+r)>>1;
    ret += query(ls[rt], l, m, qval);
    ret += query(rs[rt], m, r, qval);
    return ret;
}

int main()
{
    while(scanf("%d%d", &n, &m) != EOF && (n||m)){
        sc(x);
        init(n);
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb(mk(v, w));
            G[v].pb(mk(u, w));
        }
        dijkstra(1, dist1, cnt1);
        dijkstra(n, dist2, cnt2);
        //for(int i = 1; i <= n; i++){
            //printf("dist1[%d]=%lld, dist2[%d]=%lld\n", i, dist1[i], i, dist2[i]);
            //printf("cnt1[%d]=%lld, cnt2[%d]=%lld\n", i, cnt1[i], i, cnt2[i]);
        //}
        for(int i = 1; i <= n; i++){
            qry[i] = mk(dist1[i], cnt1[i]);
            hash_cnt[i] = cnt1[i];
            hash_dist[i] = dist1[i];
        }
        sort(qry+1, qry+n+1);
        sort(hash_cnt+1, hash_cnt+n+1);
        sort(hash_dist+1, hash_dist+n+1);
        int tot = unique(hash_cnt+1, hash_cnt+n+1)-(hash_cnt+1);
        build(root[0], 0, tot);
        for(int i = 1; i <= n; i++){
            int val = lower_bound(hash_cnt+1, hash_cnt+tot+1, qry[i].se)-(hash_cnt+1);
            update(root[i], 0, tot, root[i-1], val);
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            int qrd = dist1[n]-dist2[i]-1;
            //printf("qrd=%d\n", qrd);
            if(qrd < 0 || !cnt2[i])continue;
            int rt = (upper_bound(hash_dist+1, hash_dist+n+1, qrd)-(hash_dist+1));
            int qval = lower_bound(hash_cnt+1, hash_cnt+tot+1, (x-1)/cnt2[i]+1)-(hash_cnt+1);
            ans += query(root[rt], 0, tot, qval);
            for(auto u : G[i]){
                if(dist1[u.fi]+dist2[i]+1 <= dist1[n] && 1LL*cnt1[u.fi]*cnt2[i] >= x)ans--;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
