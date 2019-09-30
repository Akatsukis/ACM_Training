#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define sc(x) scanf("%d", &x)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define ABS(x) ((x)>=0?(x):(-(x)))
#define fastio ios::sync_with_stdio(0),cin.tie(0)
template<class T>T gcd(T a, T b){return b?gcd(b, a%b):a;}
const int maxn = 1e3+10;
int a[maxn], p[maxn];
vector<int> vec[maxn];

void init() {
    for(int i = 0; i < maxn; i++) {
        vec[i].clear();
    }
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        init();
        for(int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            vec[a[i]].push_back(p[i]);
        }
        for(int i = 0; i < maxn; i++) {
            sort(vec[i].begin(), vec[i].end());
        }
        int ans = INT_MAX;
        for(int i = 0; i < maxn; i++) {
            for(int j = 0; j < (int)vec[i].size(); j++) {
                if(j+1 >= k) {
                    ans = min(ans, vec[i][j]);
                    break;
                }
                map<int, int> dp[2];
                int cur = 0, nxt = 1;
                dp[cur][0] = 0; dp[nxt][0] = 0;
                for(int u = 0; u < maxn; u++) {
                    if(i == u)continue;
                    for(int id = 0; id < (int)vec[u].size(); id++) {
                        int v = vec[u][id];
                        for(auto p: dp[cur]) {
                            if(!dp[nxt].count(p.first+id+1))dp[nxt][p.first+id+1] = p.second+v*2;
                            else dp[nxt][p.first+id+1] = min(dp[nxt][p.first+id+1], p.second+v*2);
                        }
                    }
                    swap(cur, nxt);
                    dp[nxt] = dp[cur];
                }
                if(dp[cur].count(k-j-1)) {
                    ans = min(ans, vec[i][j]+dp[cur][k-j-1]);
                }
            }
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

