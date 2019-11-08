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
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> vec(n);
        for(int i = 0; i < n; i++) {
            int m, p;
            scanf("%d%d", &m, &p);
            vec[m].push_back(p);
        }
        int cur = n, buy = 0;
        long long ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = n-1; i >= 0; i--) {
            cur -= vec[i].size();
            for(auto val: vec[i]) {
                pq.push(val);
            }
            int need = i-cur;
            while(buy < need) {
                int cost = pq.top(); pq.pop();
                ans += cost;
                buy++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

