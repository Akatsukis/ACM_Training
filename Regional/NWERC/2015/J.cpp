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
const int maxn = 256;
int ans[maxn];

int main()
{
    for(int i = 0; i <= maxn-1; i++){
        unsigned char t = i;
        t = t^(t<<1);
        ans[t] = i;
    }
    int n; sc(n);
    for(int i = 0; i < n; i++){
        int t; sc(t);
        printf("%d%c", ans[t], " \n"[i==n-1]);
    }
    return 0;
}


