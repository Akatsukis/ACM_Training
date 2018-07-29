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
int bit[100];

int main()
{
    int n;
    sc(n);
    int u = n, v = n-1, m = 0;
    while(u){
        bit[m++] = u%2;
        u >>= 1;
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(v%2 != bit[i])ans++;
        v >>= 1;
    }
    printf("%d\n", ans);
    return 0;
}


