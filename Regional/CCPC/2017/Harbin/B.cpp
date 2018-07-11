#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define ALL(A) A.begin(), A.end()
#define sqr(x) ((x)*(x))
#define sc(x) scanf("%d", &x)
#define pr(x) printf(">>>"#x":%d\n", x)
#define fastio ios::sync_with_stdio(0),cin.tie(0)
#define debug cout<<">>>STOP"<<endl
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 1e5+10;
int a[maxn], b[maxn];
int sum[maxn];
int n, k;
ll m;

bool solve(int u)
{
    ll ret = 0, rk = 0;
    int l = 1, r = 1;
    while(r <= n){
        while(r <= n && rk < k){
            rk += b[r++]>=a[u];
        }
        if(rk >= k)ret += (n+1)-(r-1);
        rk -= b[l++]>=a[u];
    }
    return ret >= m;
}

int main()
{
    int T;
    sc(T);
    while(T--){
        scanf("%d%d%lld", &n, &k, &m);
        for(int i = 1; i <= n; i++)sc(a[i]), b[i] = a[i];
        sort(a+1, a+1+n);
        int l = 1, r = n, ans = 1;
        while(l <= r){
            int mid = (l+r)>>1;
            if(solve(mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        printf("%d\n", a[ans]);
    }
    return 0;
}

