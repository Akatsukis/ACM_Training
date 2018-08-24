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
const int maxn = 50;
char s[maxn];

int main()
{
    while(scanf("%s", s) != EOF){
        int n = strlen(s);
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            if((s[i]-'0')&1)x += (1<<(n-1-i));
            if(((s[i]-'0')>>1)&1)y += (1<<(n-1-i));
        }
        printf("%d %d %d\n", n, x, y);
    }
    return 0;
}


