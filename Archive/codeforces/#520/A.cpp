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
int n;

int main()
{
    sc(n);
    for(int i = 1; i <= n; i++)sc(a[i]);
    a[0] = 0; a[n+1] = 1001;
    int ans = 0, now = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] == a[i-1]+1 && a[i] == a[i+1]-1)now++;
        else ans = max(ans, now), now = 0;
    }
    ans = max(ans, now);
    printf("%d\n", ans);
    return 0;
}

