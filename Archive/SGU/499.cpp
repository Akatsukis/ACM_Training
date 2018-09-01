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
const int maxn = 1e6+10;
int num[maxn];

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++){
        int x; sc(x);
        for(int j = 1; j*j <= x; j++){
            if(x%j == 0){
                num[j]++;
                if(x/j != j)num[x/j]++;
            }
        }
    }
    int ans = 1;
    for(int i = maxn-1; i >= 0; i--){
        if(num[i] >= 2){
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}

