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
        int n; sc(n);
        vector<int> vec;
        int tot = 0;
        for(int i = 1; i < n; i++){
            if(n%i == 0)tot += i, vec.pb(i);
        }
        if(n%tot != 0)printf("Case %d: Not perfect.\n", kase++);
        else{
            printf("Case %d: %d = ", kase++, n);
            for(int i = 0; i < SZ(vec); i++){
                printf("%d", vec[i]);
                if(i != SZ(vec)-1)printf(" + ");
                else puts("");
            }
        }
    }
    return 0;
}


