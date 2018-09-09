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
const int maxn = 3e5+10;
int a[maxn], b[maxn];
ll sa[maxn], sb[maxn];

int main()
{
    int n; sc(n);
    for(int i = 1; i <= n; i++){
        sc(a[i]);
        sa[i] = sa[i-1]+a[i];
    }
    int m; sc(m);
    for(int i = 1; i <= m; i++){
        sc(b[i]);
        sb[i] = sb[i-1]+b[i];
    }
    if(sa[n] != sb[m]){
        puts("-1");
        return 0;
    }
    int ans = 0, l = 1, r = 1;
    ll tmp = 0;
    while(l <= n && r <= m){
        if(!tmp){
            ans++;
            tmp += a[l++]-b[r++];
        }
        else if(tmp > 0)tmp -= b[r++];
        else tmp += a[l++];
    }
    printf("%d\n", ans);
    return 0;
}

