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
char s[maxn];

int main()
{
    int T;
    sc(T);
    while(T--){
        int n;
        scanf("%d%s", &n, s);
        int u = 0, v = 0;
        while(u < n && s[u] == '<')u++;
        while(v < n && s[n-1-v] == '>')v++;
        printf("%d\n", min(u, v));
    }
    return 0;
}

