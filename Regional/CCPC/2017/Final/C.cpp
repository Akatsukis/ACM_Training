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
    int T, kase = 1;
    sc(T);
    while(T--){
        int x, y, k;
        scanf("%d%d%d",  &x, &y, &k);
        printf("Case #%d: ", kase++);
        if(x > y)printf("%d\n", k);
        else{
            for(int i = k; i >= 0; i--){
                int win = i*(-11*y+9*x), lose = (k-i)*11*x;
                if(win+lose >= 0){
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}

