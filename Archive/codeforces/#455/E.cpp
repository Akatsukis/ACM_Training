#include <bits/stdc++.h>

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
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
int n, m;
int dp[maxn];
int s[maxn];
int in[maxn];
vector<vector<int> > G(maxn);
queue<int> q;

int main()
{
    sc(n);sc(m);
    for(int i = 0; i < n; i++){
        sc(s[i]);
    }
    for(int i = 0; i < m; i++){
        int u, v;
        sc(u);sc(v);
        G[v].pb(u);
        in[u]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!in[i]){
            q.push(i);
            if(s[i]==1){
                dp[i] = 1;
                ans = max(dp[i], ans);
            }
        }
    }
    while(!q.empty()){
        int u = q.front();q.pop();
        for(int i = 0; i < (int)G[u].size(); i++){
            int v = G[u][i];
            if(s[u] == 0 && s[v] == 1)dp[v] = max(dp[v], dp[u]+1);
            else dp[v] = max(dp[v], dp[u]);
            ans = max(ans, dp[v]);
            in[v]--;
            if(!in[v]){
                q.push(v);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

