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
const int maxn = 10;

void solve(int n, int x)
{
    if(n <= 3){
        if(n == 1)printf("%d ", x);
        else if(n == 2)printf("%d %d ", x, 2*x);
        else if(n == 3)printf("%d %d %d ", x, x, 3*x);
        return;
    }
    int nxt = 0;
    for(int i = 1 ; i <= n; i++){
        if(i%2 == 0)nxt++;
        else printf("%d ", x);
    }
    solve(nxt, x*2);
}

int main()
{
    int n; 
    sc(n);
    solve(n, 1);
    return 0;
}

