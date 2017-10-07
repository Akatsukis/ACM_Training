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
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define mid(l,r) ((l)+((r)-(l))/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i,n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson(rt) (rt*2+1)
#define rson(rt) (rt*2+2)
#define lb puts("")
#define debug cout<<"???"<<endl
#define PI 3.1415926535897932
const ll mod = 1000000007;
const ll INF = 2123456789;
const ll INF64 = 1223372036854775807;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
int n, p;
const int maxn = 1e5 + 10;
vector<vector<pii> > G(maxn);
int dep[maxn];
ll cost[maxn];
ll ans;

void dfs(int now, int d, int f)
{
    dep[now] = d;
    for(int i = 0; i < (int)G[now].size(); i++){
        if(G[now][i].fi == f)continue;
        dfs(G[now][i].fi, d + 1, now);
    }
}

void dfs2(int now, vector<int> pre, int f)
{
    for(int i = 0; i < (int)G[now].size(); i++){
        pii t = G[now][i];
        if(t.fi == f)continue;
        vector<int> tmp = pre;
        if(dep[t.fi] <= 2){
            cost[t.fi] = (ll)t.se * t.se;
            tmp.pb(t.se);
            ans = max(ans, cost[t.fi]);
        }
        else{
            ll cur = 0;
            for(int i = 0; i < (int)tmp.size(); i++){
                cur += 2LL * tmp[i] * t.se;
            }

            if(tmp.size() && cur < p){
                tmp.pb(t.se);
                cost[t.fi] = cost[now] + (ll)t.se * t.se + cur;
            }
            else{
                tmp.clear();
                cost[t.fi] = cost[now] + (ll)t.se * t.se + p;
            }
            ans = max(ans, cost[t.fi]);
        }
        dfs2(t.fi, tmp, now);
    }
}


int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        ans = 0;
        memset(dep, 0, sizeof(dep));
        memset(cost, 0, sizeof(cost));
        scanf("%d%d", &n, &p);
        for(int i = 0; i <= n; i++){
            G[i].clear();
        }
        for(int i = 0; i < n - 1; i++){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            G[u].pb(mk(v, w));
            G[v].pb(mk(u, w));
        }
        dfs(1, 1, -1);
        vector<int> v;
        v.clear();
        dfs2(1, v, -1);
//        for(int i = 1; i <= n; i++){
//            printf("cost[%d]:%lld\n", i, cost[i]);
//        }
        printf("%lld\n", ans);
    }
	return 0;
}


