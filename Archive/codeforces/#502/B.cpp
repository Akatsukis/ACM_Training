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
char a[maxn], b[maxn];
ll sum[4];

int main()
{
    int n; sc(n);
    scanf("%s%s", a, b);
    set<pii> st;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '0' && b[i] == '0')sum[0]++;
        if(a[i] == '1' && b[i] == '0')sum[1]++;
        if(a[i] == '0' && b[i] == '1')sum[2]++;
        if(a[i] == '1' && b[i] == '1')sum[3]++;
    }
    ans = sum[0]*(sum[1]+sum[3])+sum[1]*(sum[0]+sum[2])-sum[0]*sum[1];
    printf("%lld\n", ans);
    return 0;
}


