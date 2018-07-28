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
const double eps = 1e-5;
const double PI = acos(-1.0);

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        int n, a, l;
        scanf("%d%d%d", &n, &a, &l);
        double len = a/(2*sin(PI/n));
        double area = len*len/2.0*sin(2*PI/n)*n;
        int ans = 0;
        while(area-eps >= l){
            ans++;
            len = len*cos(PI/n);
            area = len*len/2.0*sin(2*PI/n)*n;
        }
        printf("%d\n", ans);
    }
    return 0;
}


