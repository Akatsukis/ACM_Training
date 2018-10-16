#include <cstdio>
#include <algorithm>
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
const int maxn = 1e5+10;
ll a[maxn], b[maxn];
int n;

int main()
{
    int T; sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++)scanf("%lld", &a[i]);
        for(int i = 0; i < n; i++)scanf("%lld", &b[i]);
        bool ok = 1;
        for(int i = 0; i < n-2; i++){
            if(a[i] > b[i]){
                ok = 0;
                break;
            }
            else{
                a[i+2] += (b[i]-a[i])*3;
                a[i+1] += (b[i]-a[i])*2;
                a[i] += b[i]-a[i];
            }
        }
        for(int i = n-2; i < n; i++){
            if(a[i] != b[i]){
                ok = 0;
                break;
            }
        }
        if(ok)puts("TAK");
        else puts("NIE");
    }
    return 0;
}

