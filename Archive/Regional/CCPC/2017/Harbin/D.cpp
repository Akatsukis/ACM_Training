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
#define fst fi
#define scd se
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
int n, m;
const int maxn = 1e3 + 10;
const int maxm = 1e3 + 10;
bool vis[maxn];
vector<vector<int> > G(maxn);
int maxdep, pos;

void dfs(int cur, int f, int dep)
{
    if(vis[cur] && dep > maxdep){
        maxdep = dep;
        pos = cur;
    }
    for(int i = 0; i < (int)G[cur].size(); i++){
        int v = G[cur][i];
        if(v == f)continue;
        dfs(v, cur, dep + 1);
    }
}



void work()
{
    pos = maxdep = -1;
    memset(vis, 0, sizeof(vis));
    sc(n);sc(m);
    for(int i = 0; i < m; i++){
        int v;
        sc(v);
        vis[v] = 1;
    }
    for(int i = 0; i < n - 1; i++){
        int u, v;
        sc(u);sc(v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1, -1, 0);
    maxdep = -1;
    dfs(pos, -1, 0);
    printf("%.2f\n", maxdep / 2 * 1.0);
}

int main()
{
    int T;
    sc(T);
    while(T--){
        work();
    }
    return 0;
}


