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
    int d, m;
    sc(d); sc(m);
    int ans = 0;
    if(m > 12){
        puts("Impossible");
        return 0;
    }
    for(int i = 1; i <= m; i++){
        int x = 0;
        if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)x = 31;
        else if(i == 2)x = 28;
        else x = 30;
        if(i == m && d > x){
            puts("Impossible");
            return 0;
        }
        else if(i == m)ans += d;
        else ans += x;
    }
    ans = ans%7==0?7:ans%7;
    printf("%d\n", ans);
    return 0;
}

