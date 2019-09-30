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
const int maxn = 4e3+10;
int par[maxn], sz[maxn];
char ans[maxn];

int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
    x = find(x); y = find(y);
    par[x] = y;
}

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--) {
        int n, m;
        sc(n); sc(m);
        for(int i = 0; i < n; i++) par[i] = i, sz[i] = 0;
        for(int i = 0; i < m; i++) {
            int l, r;
            sc(l); sc(r);
            l--; r--;
            for(; l < r; l++, r--) unite(l, r);
        }
        for(int i = 0; i < n; i++) sz[find(i)]++;
        vector<int> vec;
        vector<int> id(n, 0);
        for(int i = 0; i < n; i++) {
            if(find(i) == i)vec.push_back(sz[i]), id[i] = (int)vec.size()-1;
        }
        int N = vec.size(), W = n/2;
        vector<int> dp(W+1, 0);
        vector<vector<bool>> state(N, vector<bool>(W+1, 0));
        for(int i = 0; i < N; i++) {
            for(int j = W; j >= vec[i]; j--) {
                if(dp[j-vec[i]]+vec[i] > dp[j]) {
                    dp[j] = dp[j-vec[i]]+vec[i];
                    state[i][j] = 1;
                }
            }
        }
        vector<bool> tag(N, 0);
        int u = N, v = W;
        while(u--) {
            if(state[u][v]) {
                v -= vec[u];
                tag[u] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(tag[id[find(i)]])ans[i] = '1';
            else ans[i] = '0';
        }
        ans[n] = 0;
        printf("Case #%d: %s\n", kase++, ans);
    }
    return 0;
}

