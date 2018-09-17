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
int dp[10];

int main()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    int n; sc(n);
    for(int i = 0; i < n; i++){
        int x = 0, t = 0;
        char s[10];
        scanf("%d%s", &x, s);
        int len = strlen(s);
        for(int j = 0; j < len; j++){
            if(s[j] == 'A')t |= 1;
            if(s[j] == 'B')t |= 2;
            if(s[j] == 'C')t |= 4;
        }
        for(int j = 0; j < 8; j++){
            if(dp[j] != INF){
                dp[j|t] = min(dp[j|t], dp[j]+x);
            }
        }
    }
    if(dp[7] == INF)puts("-1");
    else printf("%d\n", dp[7]);
    return 0;
}

