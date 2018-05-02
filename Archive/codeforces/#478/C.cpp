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
const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;
const ll INF64 = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-7;
template<class T> T gcd(T a, T b){if(!b)return a;return gcd(b,a%b);}
const int maxn = 2e5+10;
int a[maxn];
ll sum[maxn];

int main()
{
    int n, q;
    sc(n); sc(q);
    for(int i = 1; i <= n; i++)sc(a[i]);
    for(int i = 1; i <= n; i++)sum[i] = sum[i-1]+a[i];
    int now = 1, lft = a[1];
    for(int i = 0; i < q; i++){
        ll k;
        scanf("%lld", &k);
        if(lft > k){
            printf("%d\n", n-now+1);
            lft -= k;
        }
        else{
            k -= lft;
            if(k >= sum[n]-sum[now]){
                printf("%d\n", n);
                now = 1, lft = a[1];
            }
            else{
                int l = now+1, r = n, ret = now+1;
                while(l <= r){
                    int m = (l+r)>>1;
                    if(sum[m]-sum[now] > k){
                        ret = m;
                        r = m-1;
                    }
                    else l = m+1;
                }
                lft = sum[ret]-sum[now]-k;
                now = ret;
                printf("%d\n", n-now+1);
            }
        }
    }
    return 0;
}

