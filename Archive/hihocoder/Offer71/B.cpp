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
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+10;
int a[maxn];

int main()
{
    int n; sc(n);
    for(int i = 0; i < n; i++)sc(a[i]);
    int pos = n-1;
    while(pos && a[pos] >= a[pos-1])pos--;
    int ans = pos;
    int k = 0;
    while(k+1 < n && a[k+1] >= a[k])k++;
    if(pos == 0){
        printf("%d\n", 0);
        return 0;
    }
    for(int i = 0; i <= k; i++){
        int l = pos, r = n-1, now = n;
        while(l <= r){
            int m = (l+r)/2;
            if(a[m] >= a[i]){
                r = m-1;
                now = m;
            }
            else l = m+1;
        }
        //printf("now=%d\n", now);
        ans = min(ans, now-i-1);
        //printf("%d\n", now-i-1);
    }

    printf("%d\n", ans);
    return 0;
}


