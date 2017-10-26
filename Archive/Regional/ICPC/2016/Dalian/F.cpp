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
#define fst fi
#define scd se
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
const int maxn = 1e5;
ll sum[maxn];
ll fac[maxn];

void init()
{
    for(int i = 2; i <= maxn; i++){
        sum[i] = sum[i - 1] + i;
    }
    fac[0] = 1;
    for(int i = 1; i <= maxn; i++){
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
}

int extgcd(int a, int b, int& x, int& y)
{
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else{
        x = 1;y = 0;
    }
    return d;
}

int mod_inverse(ll a)
{
    int x, y;
    extgcd(a, mod, x, y);
    return (mod+x%mod)%mod;
}

int main()
{
    init();
    int T;
    sc(T);
    while(T--){
        int n;
        sc(n);
        if(n <= 4){
            printf("%d\n", n);
            continue;
        }
        int id = upper_bound(sum, sum + maxn, n) - sum - 1;
        int rev = n - sum[id];
        int did;
        if(rev < id){
            did = id - rev + 1;
        }
        else if(rev == id){
            did = 2 * (id + 1);
            id++;
        }
        //printf("fac[%d]=%lld did=%d %d\n", id + 1, fac[id+1], did, mod_inverse(did));
        int ans = fac[id + 1] * mod_inverse(did) % mod;
        printf("%d\n", ans);
    }
    return 0;
}


