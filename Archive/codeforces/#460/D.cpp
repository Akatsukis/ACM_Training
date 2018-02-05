#include <bits/stdc++.h>
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
#define sc(x) scanf("%d", &x)
#define pr(x) printf("x:%dn", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 3e5+10;
int n, m;
string s;
vector<vector<int> > G(maxn);
int dp[maxn][30];
int in[maxn];
bool vis[maxn];
queue<int> q;

int solve()
{
    for(int i = 1; i <= n; i++){
        if(!in[i]){
            q.push(i);
            vis[i] = 1;
            dp[i][s[i-1]-'a']=1;
        }
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i];
            in[v]--;
            for(int j = 0; j < 26; j++){
                dp[v][j] = max(dp[v][j], dp[u][j]);
            }
            if(!in[v]){
                q.push(v);
                vis[v] = 1;
                dp[v][s[v-1]-'a']++;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i])return -1;
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 26; j++){
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main()
{
    cin >> n >> m >> s;
    for(int i = 0; i  < m; i++){
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        in[v]++;
    }
    int ans = solve();
    printf("%d\n", ans);
	return 0;
}

