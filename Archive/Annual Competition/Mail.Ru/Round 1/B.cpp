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
    int mx = 0;
    for(int i = 1; i <= n; i++){
        int x; sc(x);
        if(x > mx){
            printf("%d\n", i);
            return 0;
        }
        else mx = max(mx, x+1);
    }
    printf("-1\n");
    return 0;
}

