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
const int maxn = 5e2+10;
vector<int> G[maxn];

int main()
{
    int n, m, q;
    sc(n); sc(m); sc(q);
    for(int i = 0; i < m; i++){
        int l, r;
        sc(l); sc(r);
        G[l].pb(r);
    }
    for(int i = 1; i <= n; i++)sort(ALL(G[i]));
    for(int i = 0; i < q; i++){
        int p, q;
        sc(p); sc(q);
        int ans = 0;
        for(int j = p; j <= q; j++){
            ans += upper_bound(ALL(G[j]), q)-G[j].begin();
        }
        printf("%d\n", ans);
    }
    return 0;
}


