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
const int maxn = 3e2+10;
int mat[maxn][maxn];
int dp[maxn][maxn];

int get(multiset<int> &st) {
    auto itl = st.begin();
    auto itr = st.end(); itr--;
    return sqr(*itr)-sqr(*itl);
}

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &mat[i][j]);
                dp[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++) {
            multiset<int> st;
            for(int l = 0, r = 0; r < m; r++) {
                st.insert(mat[i][r]);
                while(st.size() >= 2 && get(st) > k) {
                    st.erase(st.lower_bound(mat[i][l++]));
                }
                dp[i][r] = st.size();
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            stack<int> sk;
            for(int j = 0; j < n; j++){
                int v = j;
                while(!sk.empty() && dp[sk.top()][i] > dp[j][i]){
                    v = sk.top(); sk.pop();
                    ans = max(ans, dp[v][i]*(j-v));
                }
                if(sk.empty() || dp[sk.top()][i] < dp[j][i]){
                    dp[v][i] = dp[j][i];
                    sk.push(v);
                }
            }
            while(!sk.empty()){
                int v = sk.top(); sk.pop();
                ans = max(ans, dp[v][i]*(n-v));
            }
        }
        printf("Case #%d: %d\n", kase++, ans);
    }
    return 0;
}

