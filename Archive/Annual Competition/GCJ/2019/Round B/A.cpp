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
pii p[maxn];

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &p[i].fi, &p[i].se);
        }
        set<pair<int, int>> st;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(1LL*(p[i].fi-p[j].fi)*(p[i].se-p[j].se) < 0){
                    int x = abs(p[i].fi-p[j].fi);
                    int y = abs(p[i].se-p[j].se);
                    int d = __gcd(x, y);
                    x /= d; y /= d;
                    st.insert(mk(x, y));
                }
            }
        }
        printf("Case #%d: %d\n", kase++, (int)st.size()+1);
    }
    return 0;
}

