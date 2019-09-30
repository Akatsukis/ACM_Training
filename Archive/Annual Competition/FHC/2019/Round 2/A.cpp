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
int posx[2], posy[2];

int main()
{
    int T, kase = 1;
    sc(T);
    while(T--) {
        int n, m, k;
        int A, B;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%d%d", &A, &B);
        for(int i = 0; i < k; i++) {
            scanf("%d%d", &posx[i], &posy[i]);
        }
        printf("Case #%d: ", kase++);
        int d = (A+B)%2;
        int d1 = (posx[0]+posy[0])%2;
        int d2 = (posx[1]+posy[1])%2;
        if(k == 2 && d1 == d2 && d == d1)puts("Y");
        else puts("N");
    }
    return 0;
}

