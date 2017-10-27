#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl
#define pli pair<long long, int>

const ll mod = 1e9+7;
const int INF = 2e9+5;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 53000;
int n, m;
int d[maxn];
ll pre[maxn];
bool vis[maxn];
ll sum = 0;
map<int, ll> dis;
vector<int> tb;
map<int, ll> mp[maxn];

ll bfs(int x, int y)
{
    for(int i = 0; i < (int)tb.size(); i++){
        int u = tb[i], v = x;
        if(u > v)swap(u, v);
        ll now = min(pre[v-1] - pre[u-1], sum - (pre[v-1] - pre[u-1]));
        if(!mp[u].count(v))mp[u][v] = mp[v][u] = now;
        else mp[u][v] = mp[v][u] = min(mp[u][v], now);
    }
    dis.clear();
    for(int i = 0; i < (int)tb.size(); i++)dis[tb[i]] = INF64, vis[tb[i]] = 0;
    dis[x] = 0;
    vis[x] = 0;
    while(1){
        int v = -1;
        for(auto i = dis.begin(); i != dis.end(); i++){
            if(!vis[i->fi] && (v == -1 || i->se < dis[v]))v = i->fi;
        }
        if(v == -1)break;
        vis[v] = 1;
        for(auto i = dis.begin(); i != dis.end(); i++){
            i->se = min(i->se, dis[v] + mp[v][i->fi]);
            //printf("u=%d dis=%d\n", i->fi, i->se);
        }
    }
    ll ans = INF64;
    int u, v;
    u = x, v = y;
    if(u > v)swap(u, v);
    ll now = min(pre[v-1] - pre[u-1], sum - (pre[v-1] - pre[u-1]));
    ans = min(ans, now);
    for(int i = 0; i < (int)tb.size(); i++){
        u = tb[i], v = y;
        if(u > v)swap(u, v);
        ll now = dis[tb[i]] + min(pre[v-1] - pre[u-1], sum - (pre[v-1] - pre[u-1]));
        ans = min(ans, now);
    }
    return ans;
}

int main()
{
    sc(n);sc(m);
    for(int i = 1; i <= n; i++){
        sc(d[i]);
        sum += d[i];
        pre[i] = pre[i - 1] + d[i];
    }
    for(int i = 0; i < m; i++){
        int u, v, w;
        sc(u);sc(v);sc(w);
        if(!mp[u].count(v))mp[u][v] = mp[v][u] = w;
        else mp[u][v] = mp[v][u] = min((ll)w, mp[v][u]);
        tb.pb(u);
        tb.pb(v);
        if(u > v)swap(u, v);
        ll now = min(pre[v-1] - pre[u-1], sum - (pre[v-1] - pre[u-1]));
        mp[v][u] = mp[u][v] = min(now, mp[v][u]);
    }
    int q;
    sc(q);
    for(int i = 0; i < q; i++){
        int x, y;
        sc(x);sc(y);
        ll ans = bfs(x, y);
        printf("%lld\n", ans);
    }
    return 0;
}


