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
#define All(A) A.begin(),A.end()
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

ll Pow(ll a, ll n)
{
    ll res = 1;
    while(n){
        if(n%2)res = (res*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    ll n, m;
    int k;
    cin >> n >> m >> k;
    if(k == -1 && (m%2 != n%2)){
        printf("0\n");
        return 0;
    }
    int ans = Pow(Pow(2, n-1), m-1) % mod;
    printf("%d\n", ans);
    return 0;
}

