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
ll extgcd(ll a, ll b, ll& x, ll& y)
{
    ll d = a;
    if(b){
        d = extgcd(b, a%b, y, x);
        y -= a/b*x;
    }
    else x = 1, y = 0;
    return d;
}

int main()
{
    ll x, y, n, m, l;
    scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l);
    ll a = m-n, p, b = -l, q, c = y-x;
    ll g = extgcd(a, b, p, q);
    if(c%g != 0){
        puts("Impossible");
        return 0;
    }
    p *= (c/g);
    ll r = (b/g);
    p = (p%r+r)%r;
    printf("%lld\n", p);
    return 0;
}

