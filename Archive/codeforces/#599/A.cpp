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
    long long n;
    scanf("%lld", &n);
    vector<int> ans;
    long long m = n;
    for(long long i = 2; i*i <= n; i++) {
        if(n%i == 0) {
            ans.push_back(i);
            while(n%i == 0) {
                n /= i;
            }
        }
    }
    if(n != m && n != 1) {
        ans.push_back(n);
    }
    if(ans.size() >= 2) {
        printf("1\n");
    }
    else if(ans.size() == 1) {
        printf("%d\n", ans[0]);
    }
    else {
        printf("%lld\n", n);
    }
    return 0;
}

