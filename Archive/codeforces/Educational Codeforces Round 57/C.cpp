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
const int INF = 0x3f3f3f3f;

int main()
{
    int T;
    sc(T);
    while(T--){
        int ang;
        sc(ang);
        int ans = INF;
        for(int i = 3; ; i++){
            if(i*ang%180 == 0){
                int k = i*ang/180;
                if(k <= i-2){
                    ans = min(ans, i);
                    break;
                }                
            }      
        }
        if(ans == INF)ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}

