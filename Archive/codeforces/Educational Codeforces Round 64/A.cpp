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
const int maxn = 1e2+10;
int a[maxn];

int main()
{
    int n;
    sc(n);
    bool ok = 1;
    for(int i = 1; i <= n; i++)scanf("%d", &a[i]);
    int ans = 0;
    for(int i = 2; i <= n; i++){
        if(a[i] == 1){
            if(a[i-1] == 2)ans += 3;
            else ans += 4;
        }
        else if(a[i] == 2){
            if(a[i-1] == 1){
                if(a[i-2] == 3)ans += 2;
                else ans += 3;
            }
            else ok = 0;
        }
        else{
            if(a[i-1] == 1)ans += 4;
            else ok = 0;
        }
    }
    if(ok){
        puts("Finite");
        printf("%d\n", ans);
    }
    else puts("Infinite");
    return 0;
}

