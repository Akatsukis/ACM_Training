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
const int maxn = 1e5+10;
const int mod = 1e9+7;
char a[maxn], b[maxn], c[maxn];

int cal(char s[]) {
    int n = strlen(s);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = (ans*10+s[i]-'0')%mod;
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s%s", a, b, c);
        int na = strlen(a), nb = strlen(b), nc = strlen(c);
        int pa = -1, pb = -1, pc = -1;
        ll va = cal(a), vb = cal(b), vc = cal(c);

        ll cura = va, curb = vb, curc = vc;
        int add = 0;
        for(int i = 0; i < maxn; i++) {
            int la = na+i, lb = nb, lc = nc+add;
            while(lc < max(la, lb)) {
                lc++; add++;
                curc = curc*10%mod;
            }
            if(lc <= max(la, lb)+1) {
                if((cura+curb)%mod == curc) {
                    pa = i, pb = 0, pc = add;
                    break;
                }
            }
            if(lc == max(la, lb)) {
                if((cura+curb)%mod == curc*10%mod) {
                    pa = i, pb = 0, pc = add+1;
                    break;
                }
            }
            cura = cura*10%mod;
        }

        cura = va, curb = vb, curc = vc;
        add = 0;
        for(int i = 0; i < maxn; i++) {
            int la = na, lb = nb+i, lc = nc+add;
            while(lc < max(la, lb)) {
                lc++; add++;
                curc = curc*10%mod;
            }
            if(lc <= max(la, lb)+1) {
                if((cura+curb)%mod == curc) {
                    pa = 0, pb = i, pc = add;
                    break;
                }
            }
            if(lc == max(la, lb)) {
                if((cura+curb)%mod == curc*10%mod) {
                    pa = 0, pb = i, pc = add+1;
                    break;
                }
            }
            curb=curb*10%mod;
        }

        if(pa == -1)puts("-1");
        else printf("%d %d %d\n", pa, pb, pc);
    }
    return 0;
}

