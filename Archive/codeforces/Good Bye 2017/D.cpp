#include <bits/stdc++.h>

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

const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}

int extgcd(int a, int b, int &x, int &y)
{
    int d = a;
    if(b){
        d = extgcd(b, a%b, y, x);
        y -= (a/b)*x;
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
    printf("%lld\n", 1LL*inv(100)*341%mod);
    int k, pa, pb;
    scanf("%d%d%d", &k, &pa, &pb);
    return 0;
}

