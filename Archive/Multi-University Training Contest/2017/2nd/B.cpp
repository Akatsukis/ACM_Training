#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
#include <unordered_map>
//#include <unordered_set>

using namespace std;
#define pb push_back
#define mk make_pair
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define ALL(A) A.begin(), A.end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repr(i, n) for(int (i)=(int)(n);(i)>=0;(i)--)
#define repab(i,a,b) for(int (i)=(int)(a);(i)<=(int)(b);(i)++)
#define reprab(i,a,b) for(int (i)=(int)(a);(i)>=(int)(b);(i)--)
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define freout1 freopen("out1.txt", "w", stdout)
#define lson (rt*2+1)
#define rson (rt*2+2)
#define lb puts("")
#define PI M_PI
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e3+10;
int kase;
char s[maxn][maxn];
unordered_map<ull, pii> mp;

inline unsigned sfr(unsigned h, unsigned x) {
    return h >> x;
}
int f(int i, int j) {
    ll w = i * 1000000ll + j;
    int h = 0;
    for(int k = 0; k < 5; ++k) {
        h += (int) ((w >> (8 * k)) & 255);
        h += (h << 10);
        h ^= sfr(h, 6);
    }
    h += h << 3;
    h ^= sfr(h, 11);
    h += h << 15;
    return sfr(h, 27) & 1;
}


void work()
{
    mp.clear();
    for(int i = 0; i < 1000; i++){
        scanf("%s", s[i]);
    }
    for(int i = 0; i + 8 < 1000; i++){
        for(int j = 0; j + 8 < 1000; j++){
            ull tmp = 0;
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    tmp <<= 1;
                    if(s[i + k][j + l] == '1')tmp |= 1;
                }
            }
            mp[tmp] = mk(i, j);
        }
    }
    for(int i = 1; i + 8 < 1e6; i += 993){
        for(int j = 1; j + 8 < 1e6; j += 993){
            ull tmp = 0;
            for(int k = 0; k < 8; k++){
                for(int l = 0; l < 8; l++){
                    tmp <<= 1;
                    if(f(i + k, j + l))tmp |= 1;
                }
            }
            if(mp.find(tmp) != mp.end()){
                printf("Case #%d :%d %d\n", ++kase, i - mp[tmp].fi, j - mp[tmp].se);
                return;
            }
        }
    }
}

int main()
{
#ifdef Akatsuki
    frein;
    //freout;
#endif // Akatsuki
    int T;
    sc(T);
    while(T--){
        work();
    }
    return 0;
}


