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

int main()
{
    int n; sc(n);
    if(n <= 2){
        puts("No");
        return 0;
    }
    puts("Yes");
    printf("%d ", (n+1)/2);
    for(int i = 1; i <= n; i += 2)printf("%d%c", i, " \n"[i+2>n]);
    printf("%d ", n/2);
    for(int i = 2; i <= n; i += 2)printf("%d%c", i, " \n"[i+2>n]);
    return 0;
}

