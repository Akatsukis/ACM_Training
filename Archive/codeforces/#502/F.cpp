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
const int maxn = 1e8+10;
bitset<maxn> bs;
int n;
unsigned ans, a, b, c, d;

void cal(int p)
{
    unsigned val = a*p*p*p+b*p*p+c*p+d;
    for(int i = n/p; i; i /= p)ans += val*i;
}


int main()
{
    scanf("%d%u%u%u%u", &n, &a, &b, &c, &d);
    cal(2); cal(3);
    for(int i = 5, u = 2; i <= n; i += u, u = 6-u){
        if(!bs[i/3]){
            cal(i);
            if((i > (n-1+i)/i))continue;
            for(int j = i*i, v = u; j <= n; j += v*i, v = 6-v)bs[j/3] = 1;
        }
    }
    printf("%u\n", ans);
    return 0;
}


