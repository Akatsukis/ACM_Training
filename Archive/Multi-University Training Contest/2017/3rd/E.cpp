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
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e6 + 10;
int n, k;
vector<vector<pii> > G(maxn);
int sub[maxn];
ll ans;

void dfs(int t, int f)
{
    sub[t] = 1;
    for(int i = 0; i < (int)G[t].size(); i++){
        pii p = G[t][i];
        if(p.fi == f)continue;
        else{
            dfs(p.fi, t);
            ans += (ll)p.se * min(k, sub[p.fi]);
            sub[t] += sub[p.fi];

        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &k) != EOF){
        memset(sub, 0, sizeof(sub));
        ans = 0;
        for(int i = 0; i <= n; i++)G[i].clear();
        int u, v, w;
        for(int i = 0; i < n - 1; i++){
            sc(u);sc(v);sc(w);
            G[u].pb(mk(v, w));
            G[v].pb(mk(u, w));
        }
        dfs(1, -1);
        printf("%lld\n", ans);
    }
    return 0;
}

