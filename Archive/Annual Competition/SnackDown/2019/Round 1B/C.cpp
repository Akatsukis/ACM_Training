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
int a[maxn];
int n, m, l, k;

int main()
{
    int T; sc(T);
    while(T--){
        scanf("%d%d%d%d", &n, &m, &k, &l);
        for(int i = 0; i < n; i++)sc(a[i]);
        sort(a, a+n);
        int ans = (n+m+1)*l-k;
        for(int i = 0; i < n; i++){
            if(a[i] > k){
                ans = min(ans, (m+i+1)*l-k);
                break;
            }
            ans = min(ans, (m+i+1)*l-a[i]);
        }
        printf("%d\n", max(ans, 0));
    }
    return 0;
}

