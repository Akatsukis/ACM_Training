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
//#include <unordered_map>
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

const ll mod = 100000073;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 5e6+10;
int f[maxn];
int g[maxn];
int p[maxn];
int sum[maxn];

void init()
{
    for(int i = 0, cnt = 0; i < maxn; i++){
        if((ll)cnt*(cnt+1)/2 < i)p[++cnt] = i;
        f[i] = cnt;
    }
    sum[0] = 1, sum[1] = 2, g[1] = 1;
    for(int i = 2; i < maxn; i++){
        int u = i - f[i], v = p[f[i]] - 1;
        //printf("i=%d u=%d v=%d\n", i, u, v);
        g[i] = (sum[v]-sum[u-1]+mod)%mod;
        sum[i] = (sum[i-1]+g[i])%mod;
    }
}

int main()
{
    init();
    int l, r;
    while(scanf("%d%d", &l, &r) != EOF){
        printf("%d %d\n", f[r-l+1], g[r-l+1]);
    }
    return 0;
}


