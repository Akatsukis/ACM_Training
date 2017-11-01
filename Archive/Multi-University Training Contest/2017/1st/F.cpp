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

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5 + 10;
int n, m;
bool vis[maxn];
int a[maxn][2];
vector<int> v;
map<int, int> mp;
int kase;

void dfs(int u, int d, int t)
{
    //printf("dfs(%d,%d,%d)\n", u, d, t);
    if(vis[u]){
        if(t == 0)v.pb(d);
        else mp[d] += d;
        return;
    }
    else{
        vis[u] = 1;
        dfs(a[u][t], d + 1, t);
    }
}

void init()
{
    mp.clear();
    v.clear();
}

void work()
{
    init();
    for(int i = 0; i < n; i++){
        sc(a[i][0]);
    }
    for(int i = 0; i < m; i++){
        sc(a[i][1]);
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
        if(!vis[i])dfs(i, 0, 0);
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < m; i++){
        if(!vis[i])dfs(i, 0, 1);
    }
    ll ans = 1;
    for(int i = 0; i < (int)v.size(); i++){
        ll tmp = 0;
        for(auto j = mp.begin(); j != mp.end(); j++){
            if(v[i] % j->fi == 0){
                tmp += j->se;
            }
        }
        ans *= tmp;
    }
    printf("Case #%d: %lld\n", kase++, ans);
}

int main()
{
    kase = 1;
    while(scanf("%d%d", &n, &m) != EOF){
        work();
    }
    return 0;
}


