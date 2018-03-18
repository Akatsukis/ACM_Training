#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<">>>STOP"<<endl
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 20010;
const int base = 10000;
int mx[maxn][2], mn[maxn][2];
int n, s, t;

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--){
        sc(n); sc(s); sc(t);
        s += base;
        for(int i = 0; i < maxn; i++){
            mn[i][0] = INF;
            mx[i][0] = -INF;
        }
        mn[base][0] = mx[base][0] = 0;
        int cnt = 0, nxt = 1;
        for(int i = 0; i < n; i++){
            int x, y;
            sc(x); sc(y);
            for(int j = 0; j < maxn; j++){
                mx[j][nxt] = -INF, mn[j][nxt] = INF;
            }
            for(int j = 0; j < maxn; j++){
                if(mx[j][cnt] != -INF){
                    mx[j+x][nxt] = max(mx[j+x][nxt], mx[j][cnt]+y);
                    mn[j+x][nxt] = min(mn[j+x][nxt], mn[j][cnt]+y);
                    mx[j-x][nxt] = max(mx[j-x][nxt], mx[j][cnt]-y);
                    mn[j-x][nxt] = min(mn[j-x][nxt], mn[j][cnt]-y);
                }
            }
            swap(nxt, cnt);
        }
        double ans = 0;
        for(int i = 0; i < maxn; i++){
            if(mn[i][cnt] != INF){
                ans = max(ans, sqrt(sqr(i-s)+sqr(mn[i][cnt]-t)));
            }
            if(mx[i][cnt] != -INF){
                ans = max(ans, sqrt(sqr(i-s)+sqr(mx[i][cnt]-t)));
            }
        }
        printf("Case %d: %.3f\n", kase++, ans);
    }
    return 0;
}

