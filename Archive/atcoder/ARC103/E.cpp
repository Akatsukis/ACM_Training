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
const int maxn = 1e5+10;
char s[maxn];
 
int main()
{
    scanf("%s", s+1);
    int n = strlen(s+1);
    bool flg = 1;
    for(int i = 1; i < n; i++){
        if(s[i] != s[n-i])flg = 0;
    }
    if(s[1] != '1' || s[n] != '0')flg = 0;
    if(!flg)puts("-1");
    else{
        int rt = 1;
        for(int i = 2; i <= n; i++){
            printf("%d %d\n", rt, i);
            if(s[i-1] == '1')rt = i;
        }
    }
    return 0;
}
