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
const ll maxn = 1e6;
char s[maxn];

int main()
{
    int n; sc(n);
    if(n < 9)printf("0\n");
    else if(n == 9)printf("8\n");
    else{
        s[0] = '7', s[1] = '2';
        for(int i = 10; i < n; i++)s[i-8] = '0';
        printf("%s\n", s);
    }
    return 0;
}

