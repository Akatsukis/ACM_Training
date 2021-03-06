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
const int maxn = 100 + 10;
vector<vector<int> > G(maxn);
int n, m, s;
bool mp[maxn][maxn];
int ans;

void dfs(int now, int tmp[], int cur)
{
    if(cur == s){
        ans++;
        return;
    }
    for(int i = 0; i < (int)G[now].size(); i++){
        bool flag = 1;
        for(int j = 0; j < cur; j++){
            if(!mp[G[now][i]][tmp[j]]){
                flag = 0;
                break;
            }
        }
        if(flag){
            tmp[cur] = G[now][i];
            dfs(G[now][i], tmp, cur + 1);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        ans = 0;
        memset(mp, 0, sizeof(mp));
        scanf("%d%d%d", &n ,&m, &s);
        for(int i = 1; i <=n; i++){
            G[i].clear();
        }
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            if(u > v){
                G[u].pb(v);
            }
            else{
                G[v].pb(u);
            }
            mp[v][u] = mp[u][v] = 1;
        }
        for(int i = 1; i <= n; i++){
            int tmp[maxn];
            tmp[0] = i;
            dfs(i, tmp, 1);
        }
        printf("%d\n", ans);
    }
	return 0;
}


