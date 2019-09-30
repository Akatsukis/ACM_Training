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
const int maxv = 1e2+10;
pii p[maxn];

pii getmin(pii x, pii y) {
    if(1LL*x.fi*y.se > 1LL*x.se*y.fi)return y;
    else return x;
}


pii getmax(pii x, pii y) {
    if(1LL*x.fi*y.se > 1LL*x.se*y.fi)return x;
    else return y;
}

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
        pii l = mk(1, maxv), r = mk(maxv, 1);
        bool flg = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(p[i].fi <= p[j].fi && p[i].se <= p[j].se){
                    flg = 0;
                    break;
                }
                if(1LL*(p[i].fi-p[j].fi)*(p[i].se-p[j].se) < 0){
                    int x = p[i].fi-p[j].fi;
                    int y = p[i].se-p[j].se;
                    int d = abs(__gcd(x, y));
                    //printf("x=%d, y=%d, d=%d\n", x, y, d);
                    x /= d; y /= d;
                    if(x > 0){
                        y = abs(y);
                        l = getmax(l, mk(y, x));
                    }
                    else{
                        x = abs(x);
                        r = getmin(r, mk(y, x));
                    }
                }
            }
        }
        pii ans = mk(0, 0);
        if(getmin(l, r) != l || l == r)flg = 0;
        else{
            for(int i = 1; i <= maxv*maxv; i++){
                for(int j = 1; j <= maxv*maxv; j++){
                    pii cur = mk(i, j);
                    if(cur != l && cur != r && getmin(l, cur) == l && getmin(cur, r) == cur){
                        ans = cur;
                        break;
                    }
                }
                if(ans != mk(0, 0))break;
            }
        }
        if(flg)printf("Case #%d: %d %d\n", kase++, ans.fi, ans.se);
        else printf("Case #%d: IMPOSSIBLE\n", kase++);
    }
    return 0;
}
