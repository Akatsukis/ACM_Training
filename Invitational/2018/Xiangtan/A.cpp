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
const int maxn = 2e5+10;
int a[maxn];
ll sum[maxn];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i <= n; i++)sc(a[i]);
        sum[0] = a[0];
        for(int i = 1; i <= n; i++)sum[i] = sum[i-1]+a[i];
        int l = 0, r = n, ans = 0;
        while(l <= r){
            int m = (l+r)>>1;
            ll now = m==0?sum[n]:sum[n]-sum[m-1];
            if(now >= m){
                ans = m;
                l = m+1;
            }
            else r = m-1;
        }
        printf("%d\n", ans);
    }
    return 0;
}

