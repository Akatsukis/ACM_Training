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
const int maxn = 1e6+10;
int a[maxn];

int main()
{
    int T; sc(T);
    while(T--){
        int n; sc(n);
        for(int i = 0; i < n; i++)sc(a[i]);
        int rev = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > (a[(i+1)%n]))rev++;
        }
        if(rev <= 1)puts("YES");
        else puts("NO");
    }
    return 0;
}

