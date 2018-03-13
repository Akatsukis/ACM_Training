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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 20;
int n, m;
bool mp[maxn][maxn];
int cost[maxn][maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pii> v;

int bfs(int t, int k)
{
    //cout << t << k << endl;
    memset(cost, INF, sizeof(cost));
    queue<pii> q;
    q.push(v[t]);
    q.push(v[k]);
    cost[v[t].fi][v[t].se] = 0;
    cost[v[k].fi][v[k].se] = 0;
    while(q.size()){
        pii now = q.front();q.pop();
        for(int i = 0; i < 4; i++){
            int nx = now.fi + dx[i], ny = now.se + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if(mp[nx][ny] && cost[nx][ny] > cost[now.fi][now.se] + 1){
                cost[nx][ny] = cost[now.fi][now.se] + 1;
                q.push(mk(nx, ny));
            }
        }
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j])res = max(res, cost[i][j]);
        }
    }
    return res;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        memset(mp, 0, sizeof(mp));
        v.clear();
        sc(n);sc(m);
        for(int i = 0; i < n; i++){
            char s[maxn];
            scanf("%s", s);
            for(int j = 0; j < m; j++){
                if(s[j] == '#'){
                    mp[i][j] = 1;
                    v.pb(mk(i, j));
                }
            }
        }
        if(v.size() <= 2){
            printf("Case %d: 0\n", kase++);
        }
        else{
            int ans = INF;
            for(int i = 0; i < (int)v.size(); i++){
                for(int j = i + 1; j < (int)v.size(); j++){
                    ans = min(ans, bfs(i, j));
                }
            }
            if(ans == INF)printf("Case %d: -1\n", kase++);
            else printf("Case %d: %d\n", kase++, ans);
        }
    }
    return 0;
}


