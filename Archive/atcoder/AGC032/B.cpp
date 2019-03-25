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
    int n;
    sc(n);
    if(n%2 == 0){
        printf("%d\n", n*(n-2)/2);
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(i+j == n+1)continue;
                else printf("%d %d\n", i, j);
            }
        }
    }
    else{
        printf("%d\n", (n-1)*(n-1)/2);
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(i != n && i+j == n)continue;
                else printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}

