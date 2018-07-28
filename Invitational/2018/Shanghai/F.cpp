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
const int maxn = 2e4+10;
int x[maxn], y[maxn], r[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        int n, m, q;
        sc(n); sc(m); sc(q);
        for(int i = 0; i < q; i++){
            scanf("%d%d%d", &x[i], &y[i], &r[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            vector<pii> vec;
            for(int j = 0; j < q; j++){
                int tmp = sqr(r[j])-sqr(i-x[j]);
                if(tmp < 0)continue;
                else tmp =sqrt(tmp);
                vec.pb(mk(max(0, y[j]-tmp), min(m-1, y[j]+tmp)));
            }
            sort(ALL(vec));
            int now = 0, cnt = 0;
            for(auto u : vec){
                if(u.fi > now){
                    cnt += u.fi-now;
                    now = max(now, u.se+1);
                }
                else now = max(now, u.se+1);
            }
            cnt += m-now;
            ans += cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}


