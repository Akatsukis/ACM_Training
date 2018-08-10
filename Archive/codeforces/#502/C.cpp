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
const int maxn = 1e5+10;

int main()
{
    int n; sc(n);
    int gap = sqrt(n);
    for(int i = 1; i <= n; i += gap){
        for(int j = gap-1; j >= 0; j--){
            if(i+j <= n)printf("%d ", i+j);
        }
    }
    puts("");
    return 0;
}


