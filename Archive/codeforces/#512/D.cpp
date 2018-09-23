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
ll n, m, k;

void print(ll u, ll v)
{
    printf("YES\n0 0\n%lld 0\n0 %lld\n", u, v);
}

bool check(ll a, ll b)
{
    if(2*n%a == 0 && m%b == 0){
        ll u = 2*n/a, v = m/b;
        if(u <= n && v <= m){
            print(u, v);
            return 1;
        }
    }
    if(2*n%b == 0 && m%a == 0){
        ll u = 2*n/b, v = m/a;
        if(u <= n && v <= m){
            print(u, v);
            return 1;
        }
    }
    if(n%a == 0 && 2*m%b == 0){
        ll u = n/a, v = 2*m/b;
        if(u <= n && v <= m){
            print(u, v);
            return 1;
        }
    }
    if(n%b == 0 && 2*m%a == 0){
        ll u = n/b, v = 2*m/a;
        if(u <= n && v <= m){
            print(u, v);
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i = 1; i*i <= k; i++){
        if(k%i)continue;
        if(check(i, k/i))return 0;
    }
    puts("NO");
    return 0;
}

