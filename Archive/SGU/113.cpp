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
    int T; sc(T);
    while(T--){
        int n; sc(n);
        bool flg = 1;
        int cnt = 0;
        for(int i = 2; i*i <= n; i++){
            if(n%i == 0){
                while(n%i == 0){
                    cnt++;
                    n /= i;
                }
            }
        }
        if(n != 1)cnt++;
        if(cnt != 2)flg = 0;
        if(flg)puts("Yes");
        else puts("No");
    }
    return 0;
}
