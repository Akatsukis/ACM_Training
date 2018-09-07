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
    int n, q;
    sc(n); sc(q);
    int ans = 1;
    while(n > 1){
        int k = n/2;
        if(q > k){
            q = n-q+1;
            n = n-k;
        }
        else{
            ans += n-k;
            q = k-q+1;
            n = k;
        }
    }
    printf("%d\n", ans);
    return 0;
}

