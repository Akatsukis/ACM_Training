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
const int INF = 0x3f3f3f3f;
int a[maxn];
int n;

bool check(int m)
{
    ll u = 0, v = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= m){
            u += m-a[i];
        }
        else if(a[i] > m+1){
            v += (a[i]-m)/2;
        }
    }
    return u <= v;
}

int main()
{
    int T; sc(T);
    while(T--){
        sc(n);
        for(int i = 0; i < n; i++)sc(a[i]);
        int l = 0, r = INF, ans = -1;
        while(l <= r){
            int m = (l+r)>>1;
            if(check(m)){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}


