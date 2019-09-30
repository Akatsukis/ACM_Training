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
const int maxw = 1e9;

int main()
{
    srand(time(NULL));
    int T = 5;
    printf("%d\n", T);
    while(T--) {
        int n = 1000, m = 2000;
        printf("%d %d\n", n, m);
        for(int i = 0; i < m; i++) {
            int u = rand()%n+1, v = rand()%n+1, w = rand()%maxw+1;
            printf("%d %d %d\n", u, v, w);
        }
    }
    return 0;
}

