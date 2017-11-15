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
#define ALL(A) A.begin(),A.end()
#define sc(x) scanf("%d", &x)
#define pr(x) printf(#x":%d\n", x)
#define fastio ios::sync_with_stdio(0), cin.tie(0)
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
#define debug cout<<"???"<<endl

const ll mod = 1e9+7;
const int INF = 2e9+5;
//int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

ll mypow(ll b, ll m)
{
    ll res = 1;
    while(m){
        if(m&1)res = (res * b) % mod;
        b = (b * b) % mod;
        m >>= 1;
    }
    return res;
}

int extgcd(int a, int b, int &x, int&y)
{
    int d = a;
    if(b){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    else{
        x = 1; y = 0;
    }
    return d;
}

int inv(int a)
{
    int x, y;
    extgcd(a, mod, x, y);
    return (mod+x%mod)%mod;
}



int main()
{
    int T;
    sc(T);
    while(T--){
        ll n, m;
        scanf("%lld%lld", &n, &m);
        if(m == 1){
            printf("1\n");
            continue;
        }
        ll ans = 2*mypow(mypow(2, n) - 1, m - 1);
        if(n&1)ans++;
        ans = ans * inv(3) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}

