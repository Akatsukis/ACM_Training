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

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        unordered_set<int> st;
        for(int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            st.insert(x);
        }
        vector<int> ans(n+1, 0);
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j += i) {
                if(!st.count(j)) {
                    ans[i]++;
                }
            }
        }
        long long tot = 0;
        for(int i = 0; i < q; i++) {
            int x;
            scanf("%d", &x);
            tot += ans[x];
        }
        printf("Case #%d: %lld\n", kase++, tot);
    }
    return 0;
}

