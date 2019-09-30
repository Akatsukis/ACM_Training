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
const int maxn = 5e3+10;
char s[maxn];

int main()
{
    int T, kase = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s), num = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] == 'B')num++;
        }
        printf("Case #%d: ", kase++);
        if((num < n-1 && num >= 2) || (num == 1 && n == 3))puts("Y");
        else puts("N");
    }
    return 0;
}

