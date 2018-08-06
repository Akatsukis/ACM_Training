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
const int maxn = 2e5+10;
const int mod = 1e9+7;
const int base = 197;
char s[maxn];
ll h[maxn][2], pw[maxn];
int n;

int get_hash(int l, int r, int t)
{
    if(t == 0){
        int ret = (h[r][0]-h[l-1][0]*pw[r-l+1]%mod+mod)%mod;
        return ret;
    }
    else{
        int ret = (h[l][1]-h[r+1][1]*pw[r-l+1]%mod+mod)%mod;
        return ret;
    }
}

bool check(int l, int r, int u, int v)
{
    return get_hash(l, r, 0) == get_hash(u, v, 1);
}

int main()
{
    int T;
    sc(T);
    pw[0] = 1;
    for(int i = 1; i < maxn; i++)pw[i] = pw[i-1]*base%mod;
    while(T--){
        memset(h, 0, sizeof(h));
        memset(s, 0, sizeof(s));
        scanf("%s", s+1);
        n = strlen(s+1);
        for(int i = 1; i <= n; i++)s[i+n] = s[i];
        for(int i = 1; i <= 2*n; i++){
            h[i][0] = (h[i-1][0]*base+s[i]-'a')%mod;
        }
        for(int i = 2*n; i >= 1; i--){
            h[i][1] = (h[i+1][1]*base+s[i]-'a')%mod;
        }
        int ans = 0;
        for(int i = 1; i <= 2*n; i++){
            int u = i, v = i, tot = 0;
            for(int j = 0; j < 3; j++){
                int l = 1, r = min(u-1, 2*n-v), len = 0;
                while(l <= r){
                    int m = (l+r)>>1;
                    if(check(u-m, u-1, v+1, v+m)){
                        len = m;
                        l = m+1;
                    }
                    else r = m-1;
                }
                if(j != 2)len++;
                len = min(len, (n-1)/2-tot);
                len = min(len, min(u-1, 2*n-v));
                u = u-len;
                v = v+len;
                tot += len;
                //printf("i=%d, u=%d, v=%d, len=%d\n", i, u, v, len);
            }
            ans = max(ans, v-u+1);
        }
        printf("%d\n", ans);
    }
    return 0;
}


